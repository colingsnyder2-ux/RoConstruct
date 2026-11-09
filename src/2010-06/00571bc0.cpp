// from server: 100% by auto
// roc 2010-06 00571bc0  unit: seg_00570000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00571bc0
//
// 00571bc0  83ec54               sub esp, 0x54
// 00571bc3  56                   push esi
// 00571bc4  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 00571bc8  85f6                 test esi, esi
// 00571bca  7513                 jne 0x571bdf
// 00571bcc  8b442460             mov eax, dword ptr [esp + 0x60]
// 00571bd0  50                   push eax
// 00571bd1  56                   push esi
// 00571bd2  e8d9feffff           call 0x571ab0
// 00571bd7  83c408               add esp, 8
// 00571bda  5e                   pop esi
// 00571bdb  83c454               add esp, 0x54
// 00571bde  c3                   ret 
// 00571bdf  8b542460             mov edx, dword ptr [esp + 0x60]
// 00571be3  8d442404             lea eax, [esp + 4]
// 00571be7  8bce                 mov ecx, esi
// 00571be9  e8d2fbffff           call 0x5717c0
// 00571bee  8d4c2404             lea ecx, [esp + 4]
// 00571bf2  51                   push ecx
// 00571bf3  56                   push esi
// 00571bf4  e8b7feffff           call 0x571ab0
// 00571bf9  83c408               add esp, 8
// 00571bfc  5e                   pop esi
// 00571bfd  83c454               add esp, 0x54
// 00571c00  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
