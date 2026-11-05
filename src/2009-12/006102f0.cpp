// from server: 100% by auto
// roc 2009-12 006102f0  unit: seg_00610000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006102f0
//
// 006102f0  83ec54               sub esp, 0x54
// 006102f3  56                   push esi
// 006102f4  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 006102f8  85f6                 test esi, esi
// 006102fa  7513                 jne 0x61030f
// 006102fc  8b442460             mov eax, dword ptr [esp + 0x60]
// 00610300  50                   push eax
// 00610301  56                   push esi
// 00610302  e839ffffff           call 0x610240
// 00610307  83c408               add esp, 8
// 0061030a  5e                   pop esi
// 0061030b  83c454               add esp, 0x54
// 0061030e  c3                   ret 
// 0061030f  8b542460             mov edx, dword ptr [esp + 0x60]
// 00610313  8d442404             lea eax, [esp + 4]
// 00610317  8bce                 mov ecx, esi
// 00610319  e882fbffff           call 0x60fea0
// 0061031e  8d4c2404             lea ecx, [esp + 4]
// 00610322  51                   push ecx
// 00610323  56                   push esi
// 00610324  e817ffffff           call 0x610240
// 00610329  83c408               add esp, 8
// 0061032c  5e                   pop esi
// 0061032d  83c454               add esp, 0x54
// 00610330  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
