// from server: 100% by auto
// roc 2009-06 006b9340  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9340
//
// 006b9340  8b442404             mov eax, dword ptr [esp + 4]
// 006b9344  dd442408             fld qword ptr [esp + 8]
// 006b9348  8b4808               mov ecx, dword ptr [eax + 8]
// 006b934b  dd19                 fstp qword ptr [ecx]
// 006b934d  c7410803000000       mov dword ptr [ecx + 8], 3
// 006b9354  83400810             add dword ptr [eax + 8], 0x10
// 006b9358  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
