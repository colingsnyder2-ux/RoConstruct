// from server: 100% by auto
// roc 2012-06 0064e310  unit: seg_00640000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064e310
//
// 0064e310  83ec54               sub esp, 0x54
// 0064e313  56                   push esi
// 0064e314  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 0064e318  85f6                 test esi, esi
// 0064e31a  7513                 jne 0x64e32f
// 0064e31c  8b442460             mov eax, dword ptr [esp + 0x60]
// 0064e320  50                   push eax
// 0064e321  56                   push esi
// 0064e322  e839ffffff           call 0x64e260
// 0064e327  83c408               add esp, 8
// 0064e32a  5e                   pop esi
// 0064e32b  83c454               add esp, 0x54
// 0064e32e  c3                   ret 
// 0064e32f  8b542460             mov edx, dword ptr [esp + 0x60]
// 0064e333  8d442404             lea eax, [esp + 4]
// 0064e337  8bce                 mov ecx, esi
// 0064e339  e872fbffff           call 0x64deb0
// 0064e33e  8d4c2404             lea ecx, [esp + 4]
// 0064e342  51                   push ecx
// 0064e343  56                   push esi
// 0064e344  e817ffffff           call 0x64e260
// 0064e349  83c408               add esp, 8
// 0064e34c  5e                   pop esi
// 0064e34d  83c454               add esp, 0x54
// 0064e350  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
