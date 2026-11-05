// from server: 100% by auto
// roc 2010-06 00721720  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721720
//
// 00721720  8b442404             mov eax, dword ptr [esp + 4]
// 00721724  8b4808               mov ecx, dword ptr [eax + 8]
// 00721727  8b542408             mov edx, dword ptr [esp + 8]
// 0072172b  8911                 mov dword ptr [ecx], edx
// 0072172d  c7410802000000       mov dword ptr [ecx + 8], 2
// 00721734  83400810             add dword ptr [eax + 8], 0x10
// 00721738  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlightuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
