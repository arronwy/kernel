/* SPDX-License-Identifier: GPL-2.0 */
#ifndef S390_MEM_ENCRYPT_H__
#define S390_MEM_ENCRYPT_H__

#ifndef __ASSEMBLY__

int set_memory_encrypted(unsigned long vaddr, int numpages);
int set_memory_decrypted(unsigned long vaddr, int numpages);

static inline int set_memory_decrypted_noflush(unsigned long addr, int numpages)
{
	set_memory_decrypted(addr, numpages);
}

#endif	/* __ASSEMBLY__ */

#endif	/* S390_MEM_ENCRYPT_H__ */
