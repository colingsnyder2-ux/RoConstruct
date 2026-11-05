// from server: 100% by auto
// roc 2007-08 005bdb70  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdb70
//
// 005bdb70  8b442404             mov eax, dword ptr [esp + 4]
// 005bdb74  dd442408             fld qword ptr [esp + 8]
// 005bdb78  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdb7b  dd19                 fstp qword ptr [ecx]
// 005bdb7d  c7410803000000       mov dword ptr [ecx + 8], 3
// 005bdb84  83400810             add dword ptr [eax + 8], 0x10
// 005bdb88  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
