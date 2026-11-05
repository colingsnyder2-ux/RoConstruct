// from server: 100% by auto
// roc 2010-06 00571a90  unit: G3D::LineSegment  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00571a90
//
// 00571a90  8b442404             mov eax, dword ptr [esp + 4]
// 00571a94  85c0                 test eax, eax
// 00571a96  7415                 je 0x571aad
// 00571a98  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00571a9c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00571aa0  894848               mov dword ptr [eax + 0x48], ecx
// 00571aa3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00571aa7  895040               mov dword ptr [eax + 0x40], edx
// 00571aaa  894844               mov dword ptr [eax + 0x44], ecx
// 00571aad  c3                   ret 
// library libpng-1.2.10/pngerror.c (function _png_set_error_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngerror.c
