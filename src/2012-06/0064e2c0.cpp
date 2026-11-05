// from server: 100% by auto
// roc 2012-06 0064e2c0  unit: seg_00640000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064e2c0
//
// 0064e2c0  83ec54               sub esp, 0x54
// 0064e2c3  56                   push esi
// 0064e2c4  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 0064e2c8  85f6                 test esi, esi
// 0064e2ca  7513                 jne 0x64e2df
// 0064e2cc  8b442460             mov eax, dword ptr [esp + 0x60]
// 0064e2d0  50                   push eax
// 0064e2d1  56                   push esi
// 0064e2d2  e8d9feffff           call 0x64e1b0
// 0064e2d7  83c408               add esp, 8
// 0064e2da  5e                   pop esi
// 0064e2db  83c454               add esp, 0x54
// 0064e2de  c3                   ret 
// 0064e2df  8b542460             mov edx, dword ptr [esp + 0x60]
// 0064e2e3  8d442404             lea eax, [esp + 4]
// 0064e2e7  8bce                 mov ecx, esi
// 0064e2e9  e8c2fbffff           call 0x64deb0
// 0064e2ee  8d4c2404             lea ecx, [esp + 4]
// 0064e2f2  51                   push ecx
// 0064e2f3  56                   push esi
// 0064e2f4  e8b7feffff           call 0x64e1b0
// 0064e2f9  83c408               add esp, 8
// 0064e2fc  5e                   pop esi
// 0064e2fd  83c454               add esp, 0x54
// 0064e300  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
