// from server: 100% by auto
// roc 2012-06 00648050  unit: seg_00640000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00648050
//
// 00648050  56                   push esi
// 00648051  8b742408             mov esi, dword ptr [esp + 8]
// 00648055  85f6                 test esi, esi
// 00648057  743b                 je 0x648094
// 00648059  f6466c40             test byte ptr [esi + 0x6c], 0x40
// 0064805d  7519                 jne 0x648078
// 0064805f  56                   push esi
// 00648060  e82b2b0100           call 0x65ab90
// 00648065  8b442410             mov eax, dword ptr [esp + 0x10]
// 00648069  83c404               add esp, 4
// 0064806c  50                   push eax
// 0064806d  56                   push esi
// 0064806e  e82d130000           call 0x6493a0
// 00648073  83c408               add esp, 8
// 00648076  5e                   pop esi
// 00648077  c3                   ret 
// 00648078  688865b800           push 0xb86588
// 0064807d  56                   push esi
// 0064807e  e8dd610000           call 0x64e260
// 00648083  8b442414             mov eax, dword ptr [esp + 0x14]
// 00648087  83c408               add esp, 8
// 0064808a  50                   push eax
// 0064808b  56                   push esi
// 0064808c  e80f130000           call 0x6493a0
// 00648091  83c408               add esp, 8
// 00648094  5e                   pop esi
// 00648095  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_update_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
