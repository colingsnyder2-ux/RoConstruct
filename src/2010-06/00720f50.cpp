// from server: 100% by auto
// roc 2010-06 00720f50  unit: RBX::UniversalTool  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00720f50
//
// 00720f50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00720f54  8b4108               mov eax, dword ptr [ecx + 8]
// 00720f57  2b410c               sub eax, dword ptr [ecx + 0xc]
// 00720f5a  c1f804               sar eax, 4
// 00720f5d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
