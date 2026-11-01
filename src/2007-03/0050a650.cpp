// from server: 100% by auto
// roc 2007-03 0050a650  unit: seg_00500000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050a650
//
// 0050a650  8b442408             mov eax, dword ptr [esp + 8]
// 0050a654  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0050a658  50                   push eax
// 0050a659  6a00                 push 0
// 0050a65b  51                   push ecx
// 0050a65c  e8bffeffff           call 0x50a520
// 0050a661  83c40c               add esp, 0xc
// 0050a664  f7d8                 neg eax
// 0050a666  1bc0                 sbb eax, eax
// 0050a668  83c001               add eax, 1
// 0050a66b  c3                   ret 
// library libpng-1.2.7/png.c (function _png_check_sig)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 png.c
