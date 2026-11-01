// from server: 100% by auto
// roc 2007-03 005b9020  unit: seg_005b0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9020
//
// 005b9020  8b442404             mov eax, dword ptr [esp + 4]
// 005b9024  8b4808               mov ecx, dword ptr [eax + 8]
// 005b9027  c7410800000000       mov dword ptr [ecx + 8], 0
// 005b902e  83400810             add dword ptr [eax + 8], 0x10
// 005b9032  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushnil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
