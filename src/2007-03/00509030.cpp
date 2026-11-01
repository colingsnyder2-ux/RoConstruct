// from server: 100% by auto
// roc 2007-03 00509030  unit: seg_00500000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509030
//
// 00509030  8b442410             mov eax, dword ptr [esp + 0x10]
// 00509034  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00509038  8b542408             mov edx, dword ptr [esp + 8]
// 0050903c  6a00                 push 0
// 0050903e  6a00                 push 0
// 00509040  6a00                 push 0
// 00509042  50                   push eax
// 00509043  8b442414             mov eax, dword ptr [esp + 0x14]
// 00509047  51                   push ecx
// 00509048  52                   push edx
// 00509049  50                   push eax
// 0050904a  e801fdffff           call 0x508d50
// 0050904f  83c41c               add esp, 0x1c
// 00509052  c3                   ret 
// library libpng-1.2.7/pngread.c (function _png_create_read_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngread.c
