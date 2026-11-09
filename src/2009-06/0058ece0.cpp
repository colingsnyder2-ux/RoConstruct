// from server: 100% by auto
// roc 2009-06 0058ece0  unit: seg_00580000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058ece0
//
// 0058ece0  56                   push esi
// 0058ece1  8b742408             mov esi, dword ptr [esp + 8]
// 0058ece5  85f6                 test esi, esi
// 0058ece7  7504                 jne 0x58eced
// 0058ece9  33c0                 xor eax, eax
// 0058eceb  5e                   pop esi
// 0058ecec  c3                   ret 
// 0058eced  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0058ecf1  57                   push edi
// 0058ecf2  8b7e6c               mov edi, dword ptr [esi + 0x6c]
// 0058ecf5  8bc7                 mov eax, edi
// 0058ecf7  51                   push ecx
// 0058ecf8  0d00001000           or eax, 0x100000
// 0058ecfd  56                   push esi
// 0058ecfe  89466c               mov dword ptr [esi + 0x6c], eax
// 0058ed01  e84affffff           call 0x58ec50
// 0058ed06  83c408               add esp, 8
// 0058ed09  897e6c               mov dword ptr [esi + 0x6c], edi
// 0058ed0c  5f                   pop edi
// 0058ed0d  5e                   pop esi
// 0058ed0e  c3                   ret 
// library libpng-1.2.16/pngmem.c (function _png_malloc_warn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngmem.c
