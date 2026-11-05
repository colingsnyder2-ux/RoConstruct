// from server: 100% by auto
// roc 2007-08 00612110  unit: seg_00610000  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00612110
//
// 00612110  51                   push ecx
// 00612111  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00612115  53                   push ebx
// 00612116  55                   push ebp
// 00612117  56                   push esi
// 00612118  57                   push edi
// 00612119  33ff                 xor edi, edi
// 0061211b  bd01000000           mov ebp, 1
// 00612120  897c2410             mov dword ptr [esp + 0x10], edi
// 00612124  8bd5                 mov edx, ebp
// 00612126  8b742418             mov esi, dword ptr [esp + 0x18]
// 0061212a  8b761c               mov esi, dword ptr [esi + 0x1c]
// 0061212d  33db                 xor ebx, ebx
// 0061212f  3bd6                 cmp edx, esi
// 00612131  8bca                 mov ecx, edx
// 00612133  7e08                 jle 0x61213d
// 00612135  8bce                 mov ecx, esi
// 00612137  3be9                 cmp ebp, ecx
// 00612139  7f42                 jg 0x61217d
// 0061213b  eb04                 jmp 0x612141
// 0061213d  3bea                 cmp ebp, edx
// 0061213f  7f2b                 jg 0x61216c
// 00612141  8b742418             mov esi, dword ptr [esp + 0x18]
// 00612145  8b760c               mov esi, dword ptr [esi + 0xc]
// 00612148  8bc5                 mov eax, ebp
// 0061214a  2bcd                 sub ecx, ebp
// 0061214c  c1e004               shl eax, 4
// 0061214f  83c101               add ecx, 1
// 00612152  8d7430f8             lea esi, [eax + esi - 8]
// 00612156  03e9                 add ebp, ecx
// 00612158  833e00               cmp dword ptr [esi], 0
// 0061215b  7403                 je 0x612160
// 0061215d  83c301               add ebx, 1
// 00612160  83c610               add esi, 0x10
// 00612163  83e901               sub ecx, 1
// 00612166  75f0                 jne 0x612158
// 00612168  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061216c  011cb8               add dword ptr [eax + edi*4], ebx
// 0061216f  015c2410             add dword ptr [esp + 0x10], ebx
// 00612173  83c701               add edi, 1
// 00612176  03d2                 add edx, edx
// 00612178  83ff1a               cmp edi, 0x1a
// 0061217b  7ea9                 jle 0x612126
// 0061217d  8b442410             mov eax, dword ptr [esp + 0x10]
// 00612181  5f                   pop edi
// 00612182  5e                   pop esi
// 00612183  5d                   pop ebp
// 00612184  5b                   pop ebx
// 00612185  59                   pop ecx
// 00612186  c3                   ret 
// library lua-5.1/ltable.c (function _numusearray)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
