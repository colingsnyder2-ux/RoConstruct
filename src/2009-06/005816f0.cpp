// from server: 100% by auto
// roc 2009-06 005816f0  unit: seg_00580000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005816f0
//
// 005816f0  56                   push esi
// 005816f1  8b742408             mov esi, dword ptr [esp + 8]
// 005816f5  85f6                 test esi, esi
// 005816f7  7428                 je 0x581721
// 005816f9  53                   push ebx
// 005816fa  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005816fe  83fb08               cmp ebx, 8
// 00581701  7e0e                 jle 0x581711
// 00581703  68e0c98c00           push 0x8cc9e0
// 00581708  56                   push esi
// 00581709  e852ca0000           call 0x58e160
// 0058170e  83c408               add esp, 8
// 00581711  85db                 test ebx, ebx
// 00581713  0f9cc0               setl al
// 00581716  fec8                 dec al
// 00581718  22c3                 and al, bl
// 0058171a  88862c010000         mov byte ptr [esi + 0x12c], al
// 00581720  5b                   pop ebx
// 00581721  5e                   pop esi
// 00581722  c3                   ret 
// library libpng-1.2.16/png.c (function _png_set_sig_bytes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 png.c
