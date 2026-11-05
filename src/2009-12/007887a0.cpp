// from server: 100% by auto
// roc 2009-12 007887a0  unit: RBX::UniversalTool  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007887a0
//
// 007887a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007887a4  8b4108               mov eax, dword ptr [ecx + 8]
// 007887a7  2b410c               sub eax, dword ptr [ecx + 0xc]
// 007887aa  c1f804               sar eax, 4
// 007887ad  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
