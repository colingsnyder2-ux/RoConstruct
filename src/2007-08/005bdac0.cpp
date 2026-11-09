// from server: 100% by auto
// roc 2007-08 005bdac0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdac0
//
// 005bdac0  8b442408             mov eax, dword ptr [esp + 8]
// 005bdac4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005bdac8  e863f9ffff           call 0x5bd430
// 005bdacd  83780808             cmp dword ptr [eax + 8], 8
// 005bdad1  7403                 je 0x5bdad6
// 005bdad3  33c0                 xor eax, eax
// 005bdad5  c3                   ret 
// 005bdad6  8b00                 mov eax, dword ptr [eax]
// 005bdad8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tothread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
