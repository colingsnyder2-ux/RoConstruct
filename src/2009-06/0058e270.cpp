// from server: 100% by auto
// roc 2009-06 0058e270  unit: seg_00580000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058e270
//
// 0058e270  83ec54               sub esp, 0x54
// 0058e273  56                   push esi
// 0058e274  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 0058e278  85f6                 test esi, esi
// 0058e27a  7513                 jne 0x58e28f
// 0058e27c  8b442460             mov eax, dword ptr [esp + 0x60]
// 0058e280  50                   push eax
// 0058e281  56                   push esi
// 0058e282  e8d9feffff           call 0x58e160
// 0058e287  83c408               add esp, 8
// 0058e28a  5e                   pop esi
// 0058e28b  83c454               add esp, 0x54
// 0058e28e  c3                   ret 
// 0058e28f  8b542460             mov edx, dword ptr [esp + 0x60]
// 0058e293  8d442404             lea eax, [esp + 4]
// 0058e297  8bce                 mov ecx, esi
// 0058e299  e8d2fbffff           call 0x58de70
// 0058e29e  8d4c2404             lea ecx, [esp + 4]
// 0058e2a2  51                   push ecx
// 0058e2a3  56                   push esi
// 0058e2a4  e8b7feffff           call 0x58e160
// 0058e2a9  83c408               add esp, 8
// 0058e2ac  5e                   pop esi
// 0058e2ad  83c454               add esp, 0x54
// 0058e2b0  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
