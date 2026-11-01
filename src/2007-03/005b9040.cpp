// from server: 100% by auto
// roc 2007-03 005b9040  unit: seg_005b0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9040
//
// 005b9040  8b442404             mov eax, dword ptr [esp + 4]
// 005b9044  dd442408             fld qword ptr [esp + 8]
// 005b9048  8b4808               mov ecx, dword ptr [eax + 8]
// 005b904b  dd19                 fstp qword ptr [ecx]
// 005b904d  c7410803000000       mov dword ptr [ecx + 8], 3
// 005b9054  83400810             add dword ptr [eax + 8], 0x10
// 005b9058  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
