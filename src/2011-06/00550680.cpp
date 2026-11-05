// from server: 100% by auto
// roc 2011-06 00550680  unit: seg_00550000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00550680
//
// 00550680  56                   push esi
// 00550681  8b742408             mov esi, dword ptr [esp + 8]
// 00550685  85f6                 test esi, esi
// 00550687  7428                 je 0x5506b1
// 00550689  53                   push ebx
// 0055068a  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0055068e  83fb08               cmp ebx, 8
// 00550691  7e0e                 jle 0x5506a1
// 00550693  68a004a800           push 0xa804a0
// 00550698  56                   push esi
// 00550699  e8920c0100           call 0x561330
// 0055069e  83c408               add esp, 8
// 005506a1  85db                 test ebx, ebx
// 005506a3  0f9cc0               setl al
// 005506a6  fec8                 dec al
// 005506a8  22c3                 and al, bl
// 005506aa  88862c010000         mov byte ptr [esi + 0x12c], al
// 005506b0  5b                   pop ebx
// 005506b1  5e                   pop esi
// 005506b2  c3                   ret 
// library libpng-1.2.16/png.c (function _png_set_sig_bytes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 png.c
