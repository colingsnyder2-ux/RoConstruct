// from server: 100% by auto
// roc 2011-06 00762900  unit: seg_00760000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762900
//
// 00762900  8b442404             mov eax, dword ptr [esp + 4]
// 00762904  8b4808               mov ecx, dword ptr [eax + 8]
// 00762907  c7410800000000       mov dword ptr [ecx + 8], 0
// 0076290e  83400810             add dword ptr [eax + 8], 0x10
// 00762912  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
