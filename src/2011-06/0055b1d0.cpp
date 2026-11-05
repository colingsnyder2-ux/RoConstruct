// from server: 100% by auto
// roc 2011-06 0055b1d0  unit: seg_00550000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055b1d0
//
// 0055b1d0  56                   push esi
// 0055b1d1  8b742408             mov esi, dword ptr [esp + 8]
// 0055b1d5  85f6                 test esi, esi
// 0055b1d7  743b                 je 0x55b214
// 0055b1d9  f6466c40             test byte ptr [esi + 0x6c], 0x40
// 0055b1dd  7519                 jne 0x55b1f8
// 0055b1df  56                   push esi
// 0055b1e0  e89b420100           call 0x56f480
// 0055b1e5  8b442410             mov eax, dword ptr [esp + 0x10]
// 0055b1e9  83c404               add esp, 4
// 0055b1ec  50                   push eax
// 0055b1ed  56                   push esi
// 0055b1ee  e82d130000           call 0x55c520
// 0055b1f3  83c408               add esp, 8
// 0055b1f6  5e                   pop esi
// 0055b1f7  c3                   ret 
// 0055b1f8  68d826a800           push 0xa826d8
// 0055b1fd  56                   push esi
// 0055b1fe  e8dd610000           call 0x5613e0
// 0055b203  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055b207  83c408               add esp, 8
// 0055b20a  50                   push eax
// 0055b20b  56                   push esi
// 0055b20c  e80f130000           call 0x55c520
// 0055b211  83c408               add esp, 8
// 0055b214  5e                   pop esi
// 0055b215  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_update_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
