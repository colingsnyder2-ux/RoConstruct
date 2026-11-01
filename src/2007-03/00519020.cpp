// from server: 100% by auto
// roc 2007-03 00519020  unit: seg_00510000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00519020
//
// 00519020  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00519024  56                   push esi
// 00519025  8b742408             mov esi, dword ptr [esp + 8]
// 00519029  57                   push edi
// 0051902a  8b7e6c               mov edi, dword ptr [esi + 0x6c]
// 0051902d  8bc7                 mov eax, edi
// 0051902f  51                   push ecx
// 00519030  0d00001000           or eax, 0x100000
// 00519035  56                   push esi
// 00519036  89466c               mov dword ptr [esi + 0x6c], eax
// 00519039  e862ffffff           call 0x518fa0
// 0051903e  83c408               add esp, 8
// 00519041  897e6c               mov dword ptr [esi + 0x6c], edi
// 00519044  5f                   pop edi
// 00519045  5e                   pop esi
// 00519046  c3                   ret 
// library libpng-1.2.7/pngmem.c (function _png_malloc_warn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngmem.c
