// from server: 100% by auto
// roc 2012-06 00831ce0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831ce0
//
// 00831ce0  8b442408             mov eax, dword ptr [esp + 8]
// 00831ce4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00831ce8  e853fcffff           call 0x831940
// 00831ced  3d202dbd00           cmp eax, 0xbd2d20
// 00831cf2  7504                 jne 0x831cf8
// 00831cf4  83c8ff               or eax, 0xffffffff
// 00831cf7  c3                   ret 
// 00831cf8  8b4008               mov eax, dword ptr [eax + 8]
// 00831cfb  c3                   ret 
// library lua-5.1/lapi.c (function _lua_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
