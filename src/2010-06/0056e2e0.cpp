// from server: 100% by auto
// roc 2010-06 0056e2e0  unit: G3D::LineSegment  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056e2e0
//
// 0056e2e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0056e2e4  85c9                 test ecx, ecx
// 0056e2e6  7435                 je 0x56e31d
// 0056e2e8  8b8110010000         mov eax, dword ptr [ecx + 0x110]
// 0056e2ee  8bd0                 mov edx, eax
// 0056e2f0  c1ea18               shr edx, 0x18
// 0056e2f3  88542404             mov byte ptr [esp + 4], dl
// 0056e2f7  8bd0                 mov edx, eax
// 0056e2f9  c1ea10               shr edx, 0x10
// 0056e2fc  88542405             mov byte ptr [esp + 5], dl
// 0056e300  8bd0                 mov edx, eax
// 0056e302  88442407             mov byte ptr [esp + 7], al
// 0056e306  6a04                 push 4
// 0056e308  8d442408             lea eax, [esp + 8]
// 0056e30c  50                   push eax
// 0056e30d  c1ea08               shr edx, 8
// 0056e310  51                   push ecx
// 0056e311  88542412             mov byte ptr [esp + 0x12], dl
// 0056e315  e8e669ffff           call 0x564d00
// 0056e31a  83c40c               add esp, 0xc
// 0056e31d  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
