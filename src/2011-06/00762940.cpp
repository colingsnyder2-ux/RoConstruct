// from server: 100% by auto
// roc 2011-06 00762940  unit: seg_00760000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762940
//
// 00762940  8b442404             mov eax, dword ptr [esp + 4]
// 00762944  db442408             fild dword ptr [esp + 8]
// 00762948  8b4808               mov ecx, dword ptr [eax + 8]
// 0076294b  c7410803000000       mov dword ptr [ecx + 8], 3
// 00762952  dd19                 fstp qword ptr [ecx]
// 00762954  83400810             add dword ptr [eax + 8], 0x10
// 00762958  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushinteger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
