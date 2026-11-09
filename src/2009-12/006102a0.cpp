// from server: 100% by auto
// roc 2009-12 006102a0  unit: seg_00610000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006102a0
//
// 006102a0  83ec54               sub esp, 0x54
// 006102a3  56                   push esi
// 006102a4  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 006102a8  85f6                 test esi, esi
// 006102aa  7513                 jne 0x6102bf
// 006102ac  8b442460             mov eax, dword ptr [esp + 0x60]
// 006102b0  50                   push eax
// 006102b1  56                   push esi
// 006102b2  e8d9feffff           call 0x610190
// 006102b7  83c408               add esp, 8
// 006102ba  5e                   pop esi
// 006102bb  83c454               add esp, 0x54
// 006102be  c3                   ret 
// 006102bf  8b542460             mov edx, dword ptr [esp + 0x60]
// 006102c3  8d442404             lea eax, [esp + 4]
// 006102c7  8bce                 mov ecx, esi
// 006102c9  e8d2fbffff           call 0x60fea0
// 006102ce  8d4c2404             lea ecx, [esp + 4]
// 006102d2  51                   push ecx
// 006102d3  56                   push esi
// 006102d4  e8b7feffff           call 0x610190
// 006102d9  83c408               add esp, 8
// 006102dc  5e                   pop esi
// 006102dd  83c454               add esp, 0x54
// 006102e0  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
