// from server: 100% by auto
// roc 2012-06 0064e550  unit: seg_00640000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064e550
//
// 0064e550  56                   push esi
// 0064e551  8b742408             mov esi, dword ptr [esp + 8]
// 0064e555  85f6                 test esi, esi
// 0064e557  7504                 jne 0x64e55d
// 0064e559  33c0                 xor eax, eax
// 0064e55b  5e                   pop esi
// 0064e55c  c3                   ret 
// 0064e55d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0064e561  57                   push edi
// 0064e562  8b7e6c               mov edi, dword ptr [esi + 0x6c]
// 0064e565  8bc7                 mov eax, edi
// 0064e567  51                   push ecx
// 0064e568  0d00001000           or eax, 0x100000
// 0064e56d  56                   push esi
// 0064e56e  89466c               mov dword ptr [esi + 0x6c], eax
// 0064e571  e84affffff           call 0x64e4c0
// 0064e576  83c408               add esp, 8
// 0064e579  897e6c               mov dword ptr [esi + 0x6c], edi
// 0064e57c  5f                   pop edi
// 0064e57d  5e                   pop esi
// 0064e57e  c3                   ret 
// library libpng-1.2.16/pngmem.c (function _png_malloc_warn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngmem.c
