// from server: 100% by auto
// roc 2009-12 00788d60  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788d60
//
// 00788d60  8b442404             mov eax, dword ptr [esp + 4]
// 00788d64  dd442408             fld qword ptr [esp + 8]
// 00788d68  8b4808               mov ecx, dword ptr [eax + 8]
// 00788d6b  dd19                 fstp qword ptr [ecx]
// 00788d6d  c7410803000000       mov dword ptr [ecx + 8], 3
// 00788d74  83400810             add dword ptr [eax + 8], 0x10
// 00788d78  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
