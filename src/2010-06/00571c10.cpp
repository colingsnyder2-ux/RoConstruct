// from server: 100% by auto
// roc 2010-06 00571c10  unit: seg_00570000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00571c10
//
// 00571c10  83ec54               sub esp, 0x54
// 00571c13  56                   push esi
// 00571c14  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 00571c18  85f6                 test esi, esi
// 00571c1a  7513                 jne 0x571c2f
// 00571c1c  8b442460             mov eax, dword ptr [esp + 0x60]
// 00571c20  50                   push eax
// 00571c21  56                   push esi
// 00571c22  e839ffffff           call 0x571b60
// 00571c27  83c408               add esp, 8
// 00571c2a  5e                   pop esi
// 00571c2b  83c454               add esp, 0x54
// 00571c2e  c3                   ret 
// 00571c2f  8b542460             mov edx, dword ptr [esp + 0x60]
// 00571c33  8d442404             lea eax, [esp + 4]
// 00571c37  8bce                 mov ecx, esi
// 00571c39  e882fbffff           call 0x5717c0
// 00571c3e  8d4c2404             lea ecx, [esp + 4]
// 00571c42  51                   push ecx
// 00571c43  56                   push esi
// 00571c44  e817ffffff           call 0x571b60
// 00571c49  83c408               add esp, 8
// 00571c4c  5e                   pop esi
// 00571c4d  83c454               add esp, 0x54
// 00571c50  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
