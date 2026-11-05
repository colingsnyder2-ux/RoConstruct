// from server: 100% by auto
// roc 2007-08 005bdb90  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdb90
//
// 005bdb90  8b442404             mov eax, dword ptr [esp + 4]
// 005bdb94  db442408             fild dword ptr [esp + 8]
// 005bdb98  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdb9b  c7410803000000       mov dword ptr [ecx + 8], 3
// 005bdba2  dd19                 fstp qword ptr [ecx]
// 005bdba4  83400810             add dword ptr [eax + 8], 0x10
// 005bdba8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushinteger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
