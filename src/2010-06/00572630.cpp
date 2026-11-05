// from server: 100% by auto
// roc 2010-06 00572630  unit: seg_00570000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00572630
//
// 00572630  56                   push esi
// 00572631  8b742408             mov esi, dword ptr [esp + 8]
// 00572635  85f6                 test esi, esi
// 00572637  7504                 jne 0x57263d
// 00572639  33c0                 xor eax, eax
// 0057263b  5e                   pop esi
// 0057263c  c3                   ret 
// 0057263d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00572641  57                   push edi
// 00572642  8b7e6c               mov edi, dword ptr [esi + 0x6c]
// 00572645  8bc7                 mov eax, edi
// 00572647  51                   push ecx
// 00572648  0d00001000           or eax, 0x100000
// 0057264d  56                   push esi
// 0057264e  89466c               mov dword ptr [esi + 0x6c], eax
// 00572651  e84affffff           call 0x5725a0
// 00572656  83c408               add esp, 8
// 00572659  897e6c               mov dword ptr [esi + 0x6c], edi
// 0057265c  5f                   pop edi
// 0057265d  5e                   pop esi
// 0057265e  c3                   ret 
// library libpng-1.2.16/pngmem.c (function _png_malloc_warn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngmem.c
