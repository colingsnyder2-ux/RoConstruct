// from server: 100% by auto
// roc 2012-06 00832a70  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832a70
//
// 00832a70  8b442404             mov eax, dword ptr [esp + 4]
// 00832a74  50                   push eax
// 00832a75  e806e40100           call 0x850e80
// 00832a7a  83c404               add esp, 4
// 00832a7d  33c0                 xor eax, eax
// 00832a7f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
