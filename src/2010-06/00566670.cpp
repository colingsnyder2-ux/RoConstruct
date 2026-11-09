// from server: 100% by auto
// roc 2010-06 00566670  unit: seg_00560000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00566670
//
// 00566670  56                   push esi
// 00566671  8b742408             mov esi, dword ptr [esp + 8]
// 00566675  85f6                 test esi, esi
// 00566677  743b                 je 0x5666b4
// 00566679  f6466c40             test byte ptr [esi + 0x6c], 0x40
// 0056667d  7519                 jne 0x566698
// 0056667f  56                   push esi
// 00566680  e8db1a0100           call 0x578160
// 00566685  8b442410             mov eax, dword ptr [esp + 0x10]
// 00566689  83c404               add esp, 4
// 0056668c  50                   push eax
// 0056668d  56                   push esi
// 0056668e  e83d130000           call 0x5679d0
// 00566693  83c408               add esp, 8
// 00566696  5e                   pop esi
// 00566697  c3                   ret 
// 00566698  68602ba200           push 0xa22b60
// 0056669d  56                   push esi
// 0056669e  e8bdb40000           call 0x571b60
// 005666a3  8b442414             mov eax, dword ptr [esp + 0x14]
// 005666a7  83c408               add esp, 8
// 005666aa  50                   push eax
// 005666ab  56                   push esi
// 005666ac  e81f130000           call 0x5679d0
// 005666b1  83c408               add esp, 8
// 005666b4  5e                   pop esi
// 005666b5  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_update_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
