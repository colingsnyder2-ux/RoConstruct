// from server: 100% by auto
// roc 2008-06 00612410  unit: seg_00610000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612410
//
// 00612410  8b442404             mov eax, dword ptr [esp + 4]
// 00612414  8b4808               mov ecx, dword ptr [eax + 8]
// 00612417  8b542408             mov edx, dword ptr [esp + 8]
// 0061241b  8911                 mov dword ptr [ecx], edx
// 0061241d  c7410802000000       mov dword ptr [ecx + 8], 2
// 00612424  83400810             add dword ptr [eax + 8], 0x10
// 00612428  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlightuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
