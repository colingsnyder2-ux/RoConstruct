// from server: 100% by auto
// roc 2010-06 007214f0  unit: RBX::UniversalTool  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007214f0
//
// 007214f0  8b442404             mov eax, dword ptr [esp + 4]
// 007214f4  8b4808               mov ecx, dword ptr [eax + 8]
// 007214f7  c7410800000000       mov dword ptr [ecx + 8], 0
// 007214fe  83400810             add dword ptr [eax + 8], 0x10
// 00721502  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
