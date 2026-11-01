// from server: 100% by auto
// roc 2007-03 0050df60  unit: seg_00500000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050df60
//
// 0050df60  8b442410             mov eax, dword ptr [esp + 0x10]
// 0050df64  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0050df68  8b542408             mov edx, dword ptr [esp + 8]
// 0050df6c  6a00                 push 0
// 0050df6e  6a00                 push 0
// 0050df70  6a00                 push 0
// 0050df72  50                   push eax
// 0050df73  8b442414             mov eax, dword ptr [esp + 0x14]
// 0050df77  51                   push ecx
// 0050df78  52                   push edx
// 0050df79  50                   push eax
// 0050df7a  e891d6ffff           call 0x50b610
// 0050df7f  83c41c               add esp, 0x1c
// 0050df82  c3                   ret 
// library libpng-1.2.7/pngread.c (function _png_create_read_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngread.c
