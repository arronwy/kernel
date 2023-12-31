// SPDX-License-Identifier: GPL-2.0-only

#include "../cpuflags.h"
#include "bitmap.h"
#include "error.h"
#include "find.h"
#include "math.h"
#include "tdx.h"
#include <asm/shared/tdx.h>

#define PMD_SHIFT	21
#define PMD_SIZE	(_AC(1, UL) << PMD_SHIFT)
#define PMD_MASK	(~(PMD_SIZE - 1))

extern struct boot_params *boot_params;

/*
 * accept_memory() and process_unaccepted_memory() called from EFI stub which
 * runs before decompresser and its early_tdx_detect().
 *
 * Enumerate TDX directly from the early users.
 */
bool early_is_tdx_guest(void)
{
	static bool once;
	static bool is_tdx;

	if (!IS_ENABLED(CONFIG_INTEL_TDX_GUEST))
		return false;

	if (!once) {
		u32 eax, sig[3];

		cpuid_count(TDX_CPUID_LEAF_ID, 0, &eax,
			    &sig[0], &sig[2],  &sig[1]);
		is_tdx = !memcmp(TDX_IDENT, sig, sizeof(sig));
		once = true;
	}

	return is_tdx;
}

static inline void __accept_memory(phys_addr_t start, phys_addr_t end)
{
	/* Platform-specific memory-acceptance call goes here */
	if (early_is_tdx_guest())
		tdx_accept_memory(start, end);
	else
		error("Cannot accept memory: unknown platform\n");
}

/*
 * The accepted memory bitmap only works at PMD_SIZE granularity.  This
 * function takes unaligned start/end addresses and either:
 *  1. Accepts the memory immediately and in its entirety
 *  2. Accepts unaligned parts, and marks *some* aligned part unaccepted
 *
 * The function will never reach the bitmap_set() with zero bits to set.
 */
void process_unaccepted_memory(struct boot_params *params, u64 start, u64 end)
{
	/*
	 * Ensure that at least one bit will be set in the bitmap by
	 * immediately accepting all regions under 2*PMD_SIZE.  This is
	 * imprecise and may immediately accept some areas that could
	 * have been represented in the bitmap.  But, results in simpler
	 * code below
	 *
	 * Consider case like this:
	 *
	 * | 4k | 2044k |    2048k   |
	 * ^ 0x0        ^ 2MB        ^ 4MB
	 *
	 * Only the first 4k has been accepted. The 0MB->2MB region can not be
	 * represented in the bitmap. The 2MB->4MB region can be represented in
	 * the bitmap. But, the 0MB->4MB region is <2*PMD_SIZE and will be
	 * immediately accepted in its entirety.
	 */
	if (end - start < 2 * PMD_SIZE) {
		__accept_memory(start, end);
		return;
	}

	/*
	 * No matter how the start and end are aligned, at least one unaccepted
	 * PMD_SIZE area will remain to be marked in the bitmap.
	 */

	/* Immediately accept a <PMD_SIZE piece at the start: */
	if (start & ~PMD_MASK) {
		__accept_memory(start, round_up(start, PMD_SIZE));
		start = round_up(start, PMD_SIZE);
	}

	/* Immediately accept a <PMD_SIZE piece at the end: */
	if (end & ~PMD_MASK) {
		__accept_memory(round_down(end, PMD_SIZE), end);
		end = round_down(end, PMD_SIZE);
	}

	/*
	 * 'start' and 'end' are now both PMD-aligned.
	 * Record the range as being unaccepted:
	 */
	bitmap_set((unsigned long *)params->unaccepted_memory,
		   start / PMD_SIZE, (end - start) / PMD_SIZE);
}

void accept_memory(phys_addr_t start, phys_addr_t end)
{
	unsigned long range_start, range_end;
	unsigned long *bitmap, bitmap_size;

	bitmap = (unsigned long *)boot_params->unaccepted_memory;
	range_start = start / PMD_SIZE;
	bitmap_size = DIV_ROUND_UP(end, PMD_SIZE);

	for_each_set_bitrange_from(range_start, range_end, bitmap, bitmap_size) {
		__accept_memory(range_start * PMD_SIZE, range_end * PMD_SIZE);
		bitmap_clear(bitmap, range_start, range_end - range_start);
	}
}
