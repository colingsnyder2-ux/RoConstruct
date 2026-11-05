// from server: 100% by auto
// roc 2007-08 005244e0  unit: G3D::Line  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005244e0
//
// 005244e0  8b442404             mov eax, dword ptr [esp + 4]
// 005244e4  8b4804               mov ecx, dword ptr [eax + 4]
// 005244e7  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 005244ea  2b442410             sub eax, dword ptr [esp + 0x10]
// 005244ee  c3                   ret 
// library rbx2016-jpeg/jmemansi.c (function _jpeg_mem_available)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: rbx2016-jpeg jmemansi.c
