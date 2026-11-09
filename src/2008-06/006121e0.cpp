// from server: 100% by auto
// roc 2008-06 006121e0  unit: seg_00610000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006121e0
//
// 006121e0  8b442404             mov eax, dword ptr [esp + 4]
// 006121e4  8b4808               mov ecx, dword ptr [eax + 8]
// 006121e7  c7410800000000       mov dword ptr [ecx + 8], 0
// 006121ee  83400810             add dword ptr [eax + 8], 0x10
// 006121f2  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
