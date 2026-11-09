// from server: 100% by auto
// roc 2011-06 00561490  unit: seg_00560000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00561490
//
// 00561490  83ec54               sub esp, 0x54
// 00561493  56                   push esi
// 00561494  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 00561498  85f6                 test esi, esi
// 0056149a  7513                 jne 0x5614af
// 0056149c  8b442460             mov eax, dword ptr [esp + 0x60]
// 005614a0  50                   push eax
// 005614a1  56                   push esi
// 005614a2  e839ffffff           call 0x5613e0
// 005614a7  83c408               add esp, 8
// 005614aa  5e                   pop esi
// 005614ab  83c454               add esp, 0x54
// 005614ae  c3                   ret 
// 005614af  8b542460             mov edx, dword ptr [esp + 0x60]
// 005614b3  8d442404             lea eax, [esp + 4]
// 005614b7  8bce                 mov ecx, esi
// 005614b9  e872fbffff           call 0x561030
// 005614be  8d4c2404             lea ecx, [esp + 4]
// 005614c2  51                   push ecx
// 005614c3  56                   push esi
// 005614c4  e817ffffff           call 0x5613e0
// 005614c9  83c408               add esp, 8
// 005614cc  5e                   pop esi
// 005614cd  83c454               add esp, 0x54
// 005614d0  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
