// from server: 100% by auto
// roc 2012-06 00832960  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832960
//
// 00832960  8b442404             mov eax, dword ptr [esp + 4]
// 00832964  0fb64006             movzx eax, byte ptr [eax + 6]
// 00832968  c3                   ret 
// library lua-5.1/lapi.c (function _lua_status)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
