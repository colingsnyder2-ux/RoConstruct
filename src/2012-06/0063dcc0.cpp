// from server: 100% by auto
// roc 2012-06 0063dcc0  unit: seg_00630000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063dcc0
//
// 0063dcc0  56                   push esi
// 0063dcc1  8b742408             mov esi, dword ptr [esp + 8]
// 0063dcc5  85f6                 test esi, esi
// 0063dcc7  7428                 je 0x63dcf1
// 0063dcc9  53                   push ebx
// 0063dcca  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0063dcce  83fb08               cmp ebx, 8
// 0063dcd1  7e0e                 jle 0x63dce1
// 0063dcd3  689843b800           push 0xb84398
// 0063dcd8  56                   push esi
// 0063dcd9  e8d2040100           call 0x64e1b0
// 0063dcde  83c408               add esp, 8
// 0063dce1  85db                 test ebx, ebx
// 0063dce3  0f9cc0               setl al
// 0063dce6  fec8                 dec al
// 0063dce8  22c3                 and al, bl
// 0063dcea  88862c010000         mov byte ptr [esi + 0x12c], al
// 0063dcf0  5b                   pop ebx
// 0063dcf1  5e                   pop esi
// 0063dcf2  c3                   ret 
// library libpng-1.2.16/png.c (function _png_set_sig_bytes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 png.c
