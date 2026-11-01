// from server: 100% by auto
// roc 2009-12 00604cf0  unit: seg_00600000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00604cf0
//
// 00604cf0  56                   push esi
// 00604cf1  8b742408             mov esi, dword ptr [esp + 8]
// 00604cf5  85f6                 test esi, esi
// 00604cf7  743b                 je 0x604d34
// 00604cf9  f6466c40             test byte ptr [esi + 0x6c], 0x40
// 00604cfd  7519                 jne 0x604d18
// 00604cff  56                   push esi
// 00604d00  e83b1b0100           call 0x616840
// 00604d05  8b442410             mov eax, dword ptr [esp + 0x10]
// 00604d09  83c404               add esp, 4
// 00604d0c  50                   push eax
// 00604d0d  56                   push esi
// 00604d0e  e83d130000           call 0x606050
// 00604d13  83c408               add esp, 8
// 00604d16  5e                   pop esi
// 00604d17  c3                   ret 
// 00604d18  68004e9c00           push 0x9c4e00
// 00604d1d  56                   push esi
// 00604d1e  e81db50000           call 0x610240
// 00604d23  8b442414             mov eax, dword ptr [esp + 0x14]
// 00604d27  83c408               add esp, 8
// 00604d2a  50                   push eax
// 00604d2b  56                   push esi
// 00604d2c  e81f130000           call 0x606050
// 00604d31  83c408               add esp, 8
// 00604d34  5e                   pop esi
// 00604d35  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_update_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
