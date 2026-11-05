// from server: 100% by auto
// roc 2012-06 008320b0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008320b0
//
// 008320b0  8b442404             mov eax, dword ptr [esp + 4]
// 008320b4  dd442408             fld qword ptr [esp + 8]
// 008320b8  8b4808               mov ecx, dword ptr [eax + 8]
// 008320bb  dd19                 fstp qword ptr [ecx]
// 008320bd  c7410803000000       mov dword ptr [ecx + 8], 3
// 008320c4  83400810             add dword ptr [eax + 8], 0x10
// 008320c8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
