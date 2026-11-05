// from server: 100% by auto
// roc 2012-06 00831af0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831af0
//
// 00831af0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00831af4  8b4108               mov eax, dword ptr [ecx + 8]
// 00831af7  2b410c               sub eax, dword ptr [ecx + 0xc]
// 00831afa  c1f804               sar eax, 4
// 00831afd  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
