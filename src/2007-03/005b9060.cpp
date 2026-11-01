// from server: 100% by auto
// roc 2007-03 005b9060  unit: seg_005b0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9060
//
// 005b9060  8b442404             mov eax, dword ptr [esp + 4]
// 005b9064  db442408             fild dword ptr [esp + 8]
// 005b9068  8b4808               mov ecx, dword ptr [eax + 8]
// 005b906b  c7410803000000       mov dword ptr [ecx + 8], 3
// 005b9072  dd19                 fstp qword ptr [ecx]
// 005b9074  83400810             add dword ptr [eax + 8], 0x10
// 005b9078  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushinteger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
