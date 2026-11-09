// from server: 100% by auto
// roc 2010-06 00721510  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721510
//
// 00721510  8b442404             mov eax, dword ptr [esp + 4]
// 00721514  dd442408             fld qword ptr [esp + 8]
// 00721518  8b4808               mov ecx, dword ptr [eax + 8]
// 0072151b  dd19                 fstp qword ptr [ecx]
// 0072151d  c7410803000000       mov dword ptr [ecx + 8], 3
// 00721524  83400810             add dword ptr [eax + 8], 0x10
// 00721528  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
