/* SPDX-License-Identifier: GPL-2.0 */
#include <linux/linkage.h>
#include <asm/asm.h>
#include <asm/bitsperlong.h>
#include <asm/kvm_vcpu_regs.h>
#include <asm/nospec-branch.h>
#include <asm/percpu.h>
#include <asm/segment.h>
#include <asm/tdx.h>
#include "kvm-asm-offsets.h"
#include "run_flags.h"

#define WORD_SIZE (BITS_PER_LONG / 8)

#define VCPU_RAX	__VCPU_REGS_RAX * WORD_SIZE
#define VCPU_RCX	__VCPU_REGS_RCX * WORD_SIZE
#define VCPU_RDX	__VCPU_REGS_RDX * WORD_SIZE
#define VCPU_RBX	__VCPU_REGS_RBX * WORD_SIZE
/* Intentionally omit RSP as it's context switched by hardware */
#define VCPU_RBP	__VCPU_REGS_RBP * WORD_SIZE
#define VCPU_RSI	__VCPU_REGS_RSI * WORD_SIZE
#define VCPU_RDI	__VCPU_REGS_RDI * WORD_SIZE

#ifdef CONFIG_X86_64
#define VCPU_R8		__VCPU_REGS_R8  * WORD_SIZE
#define VCPU_R9		__VCPU_REGS_R9  * WORD_SIZE
#define VCPU_R10	__VCPU_REGS_R10 * WORD_SIZE
#define VCPU_R11	__VCPU_REGS_R11 * WORD_SIZE
#define VCPU_R12	__VCPU_REGS_R12 * WORD_SIZE
#define VCPU_R13	__VCPU_REGS_R13 * WORD_SIZE
#define VCPU_R14	__VCPU_REGS_R14 * WORD_SIZE
#define VCPU_R15	__VCPU_REGS_R15 * WORD_SIZE
#endif

#ifdef CONFIG_INTEL_TDX_HOST
#define TDH_VP_ENTER		0
#define EXIT_REASON_TDCALL	77
#define seamcall		.byte 0x66,0x0f,0x01,0xcf
#endif

.section .noinstr.text, "ax"

/**
 * __vmx_vcpu_run - Run a vCPU via a transition to VMX guest mode
 * @vmx:	struct vcpu_vmx *
 * @regs:	unsigned long * (to guest registers)
 * @flags:	VMX_RUN_VMRESUME:	use VMRESUME instead of VMLAUNCH
 *		VMX_RUN_SAVE_SPEC_CTRL: save guest SPEC_CTRL into vmx->spec_ctrl
 *
 * Returns:
 *	0 on VM-Exit, 1 on VM-Fail
 */
SYM_FUNC_START(__vmx_vcpu_run)
	push %_ASM_BP
	mov  %_ASM_SP, %_ASM_BP
#ifdef CONFIG_X86_64
	push %r15
	push %r14
	push %r13
	push %r12
#else
	push %edi
	push %esi
#endif
	push %_ASM_BX

	/* Save @vmx for SPEC_CTRL handling */
	push %_ASM_ARG1

	/* Save @flags for SPEC_CTRL handling */
	push %_ASM_ARG3

	/*
	 * Save @regs, _ASM_ARG2 may be modified by vmx_update_host_rsp() and
	 * @regs is needed after VM-Exit to save the guest's register values.
	 */
	push %_ASM_ARG2

	/* Copy @flags to BL, _ASM_ARG3 is volatile. */
	mov %_ASM_ARG3B, %bl

	lea (%_ASM_SP), %_ASM_ARG2
	call vmx_update_host_rsp

	ALTERNATIVE "jmp .Lspec_ctrl_done", "", X86_FEATURE_MSR_SPEC_CTRL

	/*
	 * SPEC_CTRL handling: if the guest's SPEC_CTRL value differs from the
	 * host's, write the MSR.
	 *
	 * IMPORTANT: To avoid RSB underflow attacks and any other nastiness,
	 * there must not be any returns or indirect branches between this code
	 * and vmentry.
	 */
	mov 2*WORD_SIZE(%_ASM_SP), %_ASM_DI
	movl VMX_spec_ctrl(%_ASM_DI), %edi
	movl PER_CPU_VAR(x86_spec_ctrl_current), %esi
	cmp %edi, %esi
	je .Lspec_ctrl_done
	mov $MSR_IA32_SPEC_CTRL, %ecx
	xor %edx, %edx
	mov %edi, %eax
	wrmsr

.Lspec_ctrl_done:

	/*
	 * Since vmentry is serializing on affected CPUs, there's no need for
	 * an LFENCE to stop speculation from skipping the wrmsr.
	 */

	/* Load @regs to RAX. */
	mov (%_ASM_SP), %_ASM_AX

	/* Check if vmlaunch or vmresume is needed */
	testb $VMX_RUN_VMRESUME, %bl

	/* Load guest registers.  Don't clobber flags. */
	mov VCPU_RCX(%_ASM_AX), %_ASM_CX
	mov VCPU_RDX(%_ASM_AX), %_ASM_DX
	mov VCPU_RBX(%_ASM_AX), %_ASM_BX
	mov VCPU_RBP(%_ASM_AX), %_ASM_BP
	mov VCPU_RSI(%_ASM_AX), %_ASM_SI
	mov VCPU_RDI(%_ASM_AX), %_ASM_DI
#ifdef CONFIG_X86_64
	mov VCPU_R8 (%_ASM_AX),  %r8
	mov VCPU_R9 (%_ASM_AX),  %r9
	mov VCPU_R10(%_ASM_AX), %r10
	mov VCPU_R11(%_ASM_AX), %r11
	mov VCPU_R12(%_ASM_AX), %r12
	mov VCPU_R13(%_ASM_AX), %r13
	mov VCPU_R14(%_ASM_AX), %r14
	mov VCPU_R15(%_ASM_AX), %r15
#endif
	/* Load guest RAX.  This kills the @regs pointer! */
	mov VCPU_RAX(%_ASM_AX), %_ASM_AX

	/* Check EFLAGS.ZF from 'testb' above */
	jz .Lvmlaunch

	/*
	 * After a successful VMRESUME/VMLAUNCH, control flow "magically"
	 * resumes below at 'vmx_vmexit' due to the VMCS HOST_RIP setting.
	 * So this isn't a typical function and objtool needs to be told to
	 * save the unwind state here and restore it below.
	 */
	UNWIND_HINT_SAVE

/*
 * If VMRESUME/VMLAUNCH and corresponding vmexit succeed, execution resumes at
 * the 'vmx_vmexit' label below.
 */
.Lvmresume:
	vmresume
	jmp .Lvmfail

.Lvmlaunch:
	vmlaunch
	jmp .Lvmfail

	_ASM_EXTABLE(.Lvmresume, .Lfixup)
	_ASM_EXTABLE(.Lvmlaunch, .Lfixup)

SYM_INNER_LABEL(vmx_vmexit, SYM_L_GLOBAL)

	/* Restore unwind state from before the VMRESUME/VMLAUNCH. */
	UNWIND_HINT_RESTORE
	ENDBR

	/* Temporarily save guest's RAX. */
	push %_ASM_AX

	/* Reload @regs to RAX. */
	mov WORD_SIZE(%_ASM_SP), %_ASM_AX

	/* Save all guest registers, including RAX from the stack */
	pop           VCPU_RAX(%_ASM_AX)
	mov %_ASM_CX, VCPU_RCX(%_ASM_AX)
	mov %_ASM_DX, VCPU_RDX(%_ASM_AX)
	mov %_ASM_BX, VCPU_RBX(%_ASM_AX)
	mov %_ASM_BP, VCPU_RBP(%_ASM_AX)
	mov %_ASM_SI, VCPU_RSI(%_ASM_AX)
	mov %_ASM_DI, VCPU_RDI(%_ASM_AX)
#ifdef CONFIG_X86_64
	mov %r8,  VCPU_R8 (%_ASM_AX)
	mov %r9,  VCPU_R9 (%_ASM_AX)
	mov %r10, VCPU_R10(%_ASM_AX)
	mov %r11, VCPU_R11(%_ASM_AX)
	mov %r12, VCPU_R12(%_ASM_AX)
	mov %r13, VCPU_R13(%_ASM_AX)
	mov %r14, VCPU_R14(%_ASM_AX)
	mov %r15, VCPU_R15(%_ASM_AX)
#endif

	/* Clear return value to indicate VM-Exit (as opposed to VM-Fail). */
	xor %ebx, %ebx

.Lclear_regs:
	/* Discard @regs.  The register is irrelevant, it just can't be RBX. */
	pop %_ASM_AX

	/*
	 * Clear all general purpose registers except RSP and RBX to prevent
	 * speculative use of the guest's values, even those that are reloaded
	 * via the stack.  In theory, an L1 cache miss when restoring registers
	 * could lead to speculative execution with the guest's values.
	 * Zeroing XORs are dirt cheap, i.e. the extra paranoia is essentially
	 * free.  RSP and RBX are exempt as RSP is restored by hardware during
	 * VM-Exit and RBX is explicitly loaded with 0 or 1 to hold the return
	 * value.
	 */
	xor %eax, %eax
	xor %ecx, %ecx
	xor %edx, %edx
	xor %ebp, %ebp
	xor %esi, %esi
	xor %edi, %edi
#ifdef CONFIG_X86_64
	xor %r8d,  %r8d
	xor %r9d,  %r9d
	xor %r10d, %r10d
	xor %r11d, %r11d
	xor %r12d, %r12d
	xor %r13d, %r13d
	xor %r14d, %r14d
	xor %r15d, %r15d
#endif

	/*
	 * IMPORTANT: RSB filling and SPEC_CTRL handling must be done before
	 * the first unbalanced RET after vmexit!
	 *
	 * For retpoline or IBRS, RSB filling is needed to prevent poisoned RSB
	 * entries and (in some cases) RSB underflow.
	 *
	 * eIBRS has its own protection against poisoned RSB, so it doesn't
	 * need the RSB filling sequence.  But it does need to be enabled, and a
	 * single call to retire, before the first unbalanced RET.
         */

	FILL_RETURN_BUFFER %_ASM_CX, RSB_CLEAR_LOOPS, X86_FEATURE_RSB_VMEXIT,\
			   X86_FEATURE_RSB_VMEXIT_LITE

	pop %_ASM_ARG2	/* @flags */
	pop %_ASM_ARG1	/* @vmx */

	call vmx_spec_ctrl_restore_host

	/* Put return value in AX */
	mov %_ASM_BX, %_ASM_AX

	pop %_ASM_BX
#ifdef CONFIG_X86_64
	pop %r12
	pop %r13
	pop %r14
	pop %r15
#else
	pop %esi
	pop %edi
#endif
	pop %_ASM_BP
	RET

.Lfixup:
	cmpb $0, kvm_rebooting
	jne .Lvmfail
	ud2
.Lvmfail:
	/* VM-Fail: set return value to 1 */
	mov $1, %_ASM_BX
	jmp .Lclear_regs

SYM_FUNC_END(__vmx_vcpu_run)


.section .text, "ax"

#ifndef CONFIG_CC_HAS_ASM_GOTO_OUTPUT
/**
 * vmread_error_trampoline - Trampoline from inline asm to vmread_error()
 * @field:	VMCS field encoding that failed
 * @fault:	%true if the VMREAD faulted, %false if it failed

 * Save and restore volatile registers across a call to vmread_error().  Note,
 * all parameters are passed on the stack.
 */
SYM_FUNC_START(vmread_error_trampoline)
	push %_ASM_BP
	mov  %_ASM_SP, %_ASM_BP

	push %_ASM_AX
	push %_ASM_CX
	push %_ASM_DX
#ifdef CONFIG_X86_64
	push %rdi
	push %rsi
	push %r8
	push %r9
	push %r10
	push %r11
#endif

	/* Load @field and @fault to arg1 and arg2 respectively. */
	mov 3*WORD_SIZE(%_ASM_BP), %_ASM_ARG2
	mov 2*WORD_SIZE(%_ASM_BP), %_ASM_ARG1

	call vmread_error

	/* Zero out @fault, which will be popped into the result register. */
	_ASM_MOV $0, 3*WORD_SIZE(%_ASM_BP)

#ifdef CONFIG_X86_64
	pop %r11
	pop %r10
	pop %r9
	pop %r8
	pop %rsi
	pop %rdi
#endif
	pop %_ASM_DX
	pop %_ASM_CX
	pop %_ASM_AX
	pop %_ASM_BP

	RET
SYM_FUNC_END(vmread_error_trampoline)
#endif

SYM_FUNC_START(vmx_do_interrupt_nmi_irqoff)
	/*
	 * Unconditionally create a stack frame, getting the correct RSP on the
	 * stack (for x86-64) would take two instructions anyways, and RBP can
	 * be used to restore RSP to make objtool happy (see below).
	 */
	push %_ASM_BP
	mov %_ASM_SP, %_ASM_BP

#ifdef CONFIG_X86_64
	/*
	 * Align RSP to a 16-byte boundary (to emulate CPU behavior) before
	 * creating the synthetic interrupt stack frame for the IRQ/NMI.
	 */
	and  $-16, %rsp
	push $__KERNEL_DS
	push %rbp
#endif
	pushf
	push $__KERNEL_CS
	CALL_NOSPEC _ASM_ARG1

	/*
	 * "Restore" RSP from RBP, even though IRET has already unwound RSP to
	 * the correct value.  objtool doesn't know the callee will IRET and,
	 * without the explicit restore, thinks the stack is getting walloped.
	 * Using an unwind hint is problematic due to x86-64's dynamic alignment.
	 */
	mov %_ASM_BP, %_ASM_SP
	pop %_ASM_BP
	RET
SYM_FUNC_END(vmx_do_interrupt_nmi_irqoff)

#ifdef CONFIG_INTEL_TDX_HOST

.pushsection .noinstr.text, "ax"

/**
 * __tdx_vcpu_run - Call SEAMCALL(TDH_VP_ENTER) to run a TD vcpu
 * @tdvpr:	physical address of TDVPR
 * @regs:	void * (to registers of TDVCPU)
 * @gpr_mask:	non-zero if guest registers need to be loaded prior to TDH_VP_ENTER
 *
 * Returns:
 *	TD-Exit Reason
 *
 * Note: KVM doesn't support using XMM in its hypercalls, it's the HyperV
 *	 code's responsibility to save/restore XMM registers on TDVMCALL.
 */
SYM_FUNC_START(__tdx_vcpu_run)
	push %rbp
	mov  %rsp, %rbp

	push %r15
	push %r14
	push %r13
	push %r12
	push %rbx

	/* Save @regs, which is needed after TDH_VP_ENTER to capture output. */
	push %rsi

	/* Load @tdvpr to RCX */
	mov %rdi, %rcx

	/* No need to load guest GPRs if the last exit wasn't a TDVMCALL. */
	test %dx, %dx
	je 1f

	/* Load @regs to RAX, which will be clobbered with $TDH_VP_ENTER anyways. */
	mov %rsi, %rax

	mov VCPU_RBX(%rax), %rbx
	mov VCPU_RDX(%rax), %rdx
	mov VCPU_RBP(%rax), %rbp
	mov VCPU_RSI(%rax), %rsi
	mov VCPU_RDI(%rax), %rdi

	mov VCPU_R8 (%rax),  %r8
	mov VCPU_R9 (%rax),  %r9
	mov VCPU_R10(%rax), %r10
	mov VCPU_R11(%rax), %r11
	mov VCPU_R12(%rax), %r12
	mov VCPU_R13(%rax), %r13
	mov VCPU_R14(%rax), %r14
	mov VCPU_R15(%rax), %r15

	/*  Load TDH_VP_ENTER to RAX.  This kills the @regs pointer! */
1:	mov $TDH_VP_ENTER, %rax

2:	seamcall

8:	nop
	/*
	 * Use same return value convention to tdxcall.S.
	 * TDX_SEAMCALL_VMFAILINVALID doesn't conflict with any TDX status code.
	 */
9:	jnc 3f
	mov $TDX_SEAMCALL_VMFAILINVALID, %rax
	jmp 5f
3:

	jnz .Lno_vmfailvalid
	mov $TDX_SEAMCALL_VMFAILVALID, %rax
	jmp 5f
.Lno_vmfailvalid:

	/* Skip to the exit path if TDH_VP_ENTER failed. */
	bt $TDX_ERROR_BIT, %rax
	jc 5f

	/* Temporarily save the TD-Exit reason. */
	push %rax

	/* check if TD-exit due to TDVMCALL */
	cmp $EXIT_REASON_TDCALL, %ax

	/* Reload @regs to RAX. */
	mov 8(%rsp), %rax

	/* Jump on non-TDVMCALL */
	jne 4f

	/* Save all output from SEAMCALL(TDH_VP_ENTER) */
	mov %rbx, VCPU_RBX(%rax)
	mov %rbp, VCPU_RBP(%rax)
	mov %rsi, VCPU_RSI(%rax)
	mov %rdi, VCPU_RDI(%rax)
	mov %r10, VCPU_R10(%rax)
	mov %r11, VCPU_R11(%rax)
	mov %r12, VCPU_R12(%rax)
	mov %r13, VCPU_R13(%rax)
	mov %r14, VCPU_R14(%rax)
	mov %r15, VCPU_R15(%rax)

4:	mov %rcx, VCPU_RCX(%rax)
	mov %rdx, VCPU_RDX(%rax)
	mov %r8,  VCPU_R8 (%rax)
	mov %r9,  VCPU_R9 (%rax)

	/*
	 * Clear all general purpose registers except RSP and RAX to prevent
	 * speculative use of the guest's values.
	 */
	xor %rbx, %rbx
	xor %rcx, %rcx
	xor %rdx, %rdx
	xor %rsi, %rsi
	xor %rdi, %rdi
	xor %rbp, %rbp
	xor %r8,  %r8
	xor %r9,  %r9
	xor %r10, %r10
	xor %r11, %r11
	xor %r12, %r12
	xor %r13, %r13
	xor %r14, %r14
	xor %r15, %r15

	/* Restore the TD-Exit reason to RAX for return. */
	pop %rax

	/* "POP" @regs. */
5:	add $8, %rsp
	pop %rbx
	pop %r12
	pop %r13
	pop %r14
	pop %r15

	pop %rbp
	RET

6:	cmpb $0, kvm_rebooting
	je 1f
	mov $TDX_SW_ERROR, %r12
	orq %r12, %rax
	jmp 5b
1:	ud2
	/* Use FAULT version to know what fault happened. */
	_ASM_EXTABLE_FAULT(2b, 6b)
	_ASM_EXTABLE_FIX_MC(8b, 9b)

SYM_FUNC_END(__tdx_vcpu_run)

.popsection

#endif
