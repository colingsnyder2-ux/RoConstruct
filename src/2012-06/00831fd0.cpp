// from server: 100% by auto
// roc 2012-06 00831fd0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831fd0
//
// 00831fd0  8b442408             mov eax, dword ptr [esp + 8]
// 00831fd4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00831fd8  e863f9ffff           call 0x831940
// 00831fdd  8b4808               mov ecx, dword ptr [eax + 8]
// 00831fe0  83e902               sub ecx, 2
// 00831fe3  740e                 je 0x831ff3
// 00831fe5  83e905               sub ecx, 5
// 00831fe8  7403                 je 0x831fed
// 00831fea  33c0                 xor eax, eax
// 00831fec  c3                   ret 
// 00831fed  8b00                 mov eax, dword ptr [eax]
// 00831fef  83c018               add eax, 0x18
// 00831ff2  c3                   ret 
// 00831ff3  8b00                 mov eax, dword ptr [eax]
// 00831ff5  c3                   ret 
// library lua-5.1/lapi.c (function _lua_touserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
