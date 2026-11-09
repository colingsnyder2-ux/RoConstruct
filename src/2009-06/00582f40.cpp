// from server: 100% by auto
// roc 2009-06 00582f40  unit: seg_00580000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00582f40
//
// 00582f40  56                   push esi
// 00582f41  8b742408             mov esi, dword ptr [esp + 8]
// 00582f45  85f6                 test esi, esi
// 00582f47  743b                 je 0x582f84
// 00582f49  f6466c40             test byte ptr [esi + 0x6c], 0x40
// 00582f4d  7519                 jne 0x582f68
// 00582f4f  56                   push esi
// 00582f50  e8db180100           call 0x594830
// 00582f55  8b442410             mov eax, dword ptr [esp + 0x10]
// 00582f59  83c404               add esp, 4
// 00582f5c  50                   push eax
// 00582f5d  56                   push esi
// 00582f5e  e83d130000           call 0x5842a0
// 00582f63  83c408               add esp, 8
// 00582f66  5e                   pop esi
// 00582f67  c3                   ret 
// 00582f68  6860df8c00           push 0x8cdf60
// 00582f6d  56                   push esi
// 00582f6e  e89db20000           call 0x58e210
// 00582f73  8b442414             mov eax, dword ptr [esp + 0x14]
// 00582f77  83c408               add esp, 8
// 00582f7a  50                   push eax
// 00582f7b  56                   push esi
// 00582f7c  e81f130000           call 0x5842a0
// 00582f81  83c408               add esp, 8
// 00582f84  5e                   pop esi
// 00582f85  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_update_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
