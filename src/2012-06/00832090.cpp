// from server: 100% by auto
// roc 2012-06 00832090  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832090
//
// 00832090  8b442404             mov eax, dword ptr [esp + 4]
// 00832094  8b4808               mov ecx, dword ptr [eax + 8]
// 00832097  c7410800000000       mov dword ptr [ecx + 8], 0
// 0083209e  83400810             add dword ptr [eax + 8], 0x10
// 008320a2  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
