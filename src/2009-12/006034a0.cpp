// from server: 100% by auto
// roc 2009-12 006034a0  unit: seg_00600000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006034a0
//
// 006034a0  56                   push esi
// 006034a1  8b742408             mov esi, dword ptr [esp + 8]
// 006034a5  85f6                 test esi, esi
// 006034a7  7428                 je 0x6034d1
// 006034a9  53                   push ebx
// 006034aa  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006034ae  83fb08               cmp ebx, 8
// 006034b1  7e0e                 jle 0x6034c1
// 006034b3  6880389c00           push 0x9c3880
// 006034b8  56                   push esi
// 006034b9  e8d2cc0000           call 0x610190
// 006034be  83c408               add esp, 8
// 006034c1  85db                 test ebx, ebx
// 006034c3  0f9cc0               setl al
// 006034c6  fec8                 dec al
// 006034c8  22c3                 and al, bl
// 006034ca  88862c010000         mov byte ptr [esi + 0x12c], al
// 006034d0  5b                   pop ebx
// 006034d1  5e                   pop esi
// 006034d2  c3                   ret 
// library libpng-1.2.16/png.c (function _png_set_sig_bytes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 png.c
