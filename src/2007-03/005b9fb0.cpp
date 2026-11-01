// from server: 100% by auto
// roc 2007-03 005b9fb0  unit: seg_005b0000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9fb0
//
// 005b9fb0  8b442408             mov eax, dword ptr [esp + 8]
// 005b9fb4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b9fb8  8d500c               lea edx, [eax + 0xc]
// 005b9fbb  894808               mov dword ptr [eax + 8], ecx
// 005b9fbe  8910                 mov dword ptr [eax], edx
// 005b9fc0  c7400400000000       mov dword ptr [eax + 4], 0
// 005b9fc7  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_buffinit)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
