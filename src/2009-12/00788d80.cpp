// from server: 100% by auto
// roc 2009-12 00788d80  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788d80
//
// 00788d80  8b442404             mov eax, dword ptr [esp + 4]
// 00788d84  db442408             fild dword ptr [esp + 8]
// 00788d88  8b4808               mov ecx, dword ptr [eax + 8]
// 00788d8b  c7410803000000       mov dword ptr [ecx + 8], 3
// 00788d92  dd19                 fstp qword ptr [ecx]
// 00788d94  83400810             add dword ptr [eax + 8], 0x10
// 00788d98  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushinteger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
