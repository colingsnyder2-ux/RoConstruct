// from server: 100% by auto
// roc 2009-06 0058e2c0  unit: seg_00580000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058e2c0
//
// 0058e2c0  83ec54               sub esp, 0x54
// 0058e2c3  56                   push esi
// 0058e2c4  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 0058e2c8  85f6                 test esi, esi
// 0058e2ca  7513                 jne 0x58e2df
// 0058e2cc  8b442460             mov eax, dword ptr [esp + 0x60]
// 0058e2d0  50                   push eax
// 0058e2d1  56                   push esi
// 0058e2d2  e839ffffff           call 0x58e210
// 0058e2d7  83c408               add esp, 8
// 0058e2da  5e                   pop esi
// 0058e2db  83c454               add esp, 0x54
// 0058e2de  c3                   ret 
// 0058e2df  8b542460             mov edx, dword ptr [esp + 0x60]
// 0058e2e3  8d442404             lea eax, [esp + 4]
// 0058e2e7  8bce                 mov ecx, esi
// 0058e2e9  e882fbffff           call 0x58de70
// 0058e2ee  8d4c2404             lea ecx, [esp + 4]
// 0058e2f2  51                   push ecx
// 0058e2f3  56                   push esi
// 0058e2f4  e817ffffff           call 0x58e210
// 0058e2f9  83c408               add esp, 8
// 0058e2fc  5e                   pop esi
// 0058e2fd  83c454               add esp, 0x54
// 0058e300  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
