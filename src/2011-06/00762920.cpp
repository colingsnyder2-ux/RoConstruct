// from server: 100% by auto
// roc 2011-06 00762920  unit: seg_00760000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762920
//
// 00762920  8b442404             mov eax, dword ptr [esp + 4]
// 00762924  dd442408             fld qword ptr [esp + 8]
// 00762928  8b4808               mov ecx, dword ptr [eax + 8]
// 0076292b  dd19                 fstp qword ptr [ecx]
// 0076292d  c7410803000000       mov dword ptr [ecx + 8], 3
// 00762934  83400810             add dword ptr [eax + 8], 0x10
// 00762938  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
