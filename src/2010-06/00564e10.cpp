// from server: 100% by auto
// roc 2010-06 00564e10  unit: seg_00560000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00564e10
//
// 00564e10  56                   push esi
// 00564e11  8b742408             mov esi, dword ptr [esp + 8]
// 00564e15  85f6                 test esi, esi
// 00564e17  7428                 je 0x564e41
// 00564e19  53                   push ebx
// 00564e1a  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00564e1e  83fb08               cmp ebx, 8
// 00564e21  7e0e                 jle 0x564e31
// 00564e23  68e015a200           push 0xa215e0
// 00564e28  56                   push esi
// 00564e29  e882cc0000           call 0x571ab0
// 00564e2e  83c408               add esp, 8
// 00564e31  85db                 test ebx, ebx
// 00564e33  0f9cc0               setl al
// 00564e36  fec8                 dec al
// 00564e38  22c3                 and al, bl
// 00564e3a  88862c010000         mov byte ptr [esi + 0x12c], al
// 00564e40  5b                   pop ebx
// 00564e41  5e                   pop esi
// 00564e42  c3                   ret 
// library libpng-1.2.16/png.c (function _png_set_sig_bytes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 png.c
