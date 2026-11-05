// from server: 100% by auto
// roc 2009-12 00610d10  unit: seg_00610000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00610d10
//
// 00610d10  56                   push esi
// 00610d11  8b742408             mov esi, dword ptr [esp + 8]
// 00610d15  85f6                 test esi, esi
// 00610d17  7504                 jne 0x610d1d
// 00610d19  33c0                 xor eax, eax
// 00610d1b  5e                   pop esi
// 00610d1c  c3                   ret 
// 00610d1d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00610d21  57                   push edi
// 00610d22  8b7e6c               mov edi, dword ptr [esi + 0x6c]
// 00610d25  8bc7                 mov eax, edi
// 00610d27  51                   push ecx
// 00610d28  0d00001000           or eax, 0x100000
// 00610d2d  56                   push esi
// 00610d2e  89466c               mov dword ptr [esi + 0x6c], eax
// 00610d31  e84affffff           call 0x610c80
// 00610d36  83c408               add esp, 8
// 00610d39  897e6c               mov dword ptr [esi + 0x6c], edi
// 00610d3c  5f                   pop edi
// 00610d3d  5e                   pop esi
// 00610d3e  c3                   ret 
// library libpng-1.2.16/pngmem.c (function _png_malloc_warn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngmem.c
