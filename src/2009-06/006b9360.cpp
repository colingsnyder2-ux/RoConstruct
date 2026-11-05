// from server: 100% by auto
// roc 2009-06 006b9360  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9360
//
// 006b9360  8b442404             mov eax, dword ptr [esp + 4]
// 006b9364  db442408             fild dword ptr [esp + 8]
// 006b9368  8b4808               mov ecx, dword ptr [eax + 8]
// 006b936b  c7410803000000       mov dword ptr [ecx + 8], 3
// 006b9372  dd19                 fstp qword ptr [ecx]
// 006b9374  83400810             add dword ptr [eax + 8], 0x10
// 006b9378  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushinteger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
