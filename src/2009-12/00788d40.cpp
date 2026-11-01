// from server: 100% by auto
// roc 2009-12 00788d40  unit: RBX::UniversalTool  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788d40
//
// 00788d40  8b442404             mov eax, dword ptr [esp + 4]
// 00788d44  8b4808               mov ecx, dword ptr [eax + 8]
// 00788d47  c7410800000000       mov dword ptr [ecx + 8], 0
// 00788d4e  83400810             add dword ptr [eax + 8], 0x10
// 00788d52  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
