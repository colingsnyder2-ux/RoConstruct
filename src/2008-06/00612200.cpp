// from server: 100% by auto
// roc 2008-06 00612200  unit: seg_00610000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612200
//
// 00612200  8b442404             mov eax, dword ptr [esp + 4]
// 00612204  dd442408             fld qword ptr [esp + 8]
// 00612208  8b4808               mov ecx, dword ptr [eax + 8]
// 0061220b  dd19                 fstp qword ptr [ecx]
// 0061220d  c7410803000000       mov dword ptr [ecx + 8], 3
// 00612214  83400810             add dword ptr [eax + 8], 0x10
// 00612218  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
