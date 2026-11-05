// from server: 100% by auto
// roc 2012-06 00832000  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832000
//
// 00832000  8b442408             mov eax, dword ptr [esp + 8]
// 00832004  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00832008  e833f9ffff           call 0x831940
// 0083200d  83780808             cmp dword ptr [eax + 8], 8
// 00832011  7403                 je 0x832016
// 00832013  33c0                 xor eax, eax
// 00832015  c3                   ret 
// 00832016  8b00                 mov eax, dword ptr [eax]
// 00832018  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tothread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
