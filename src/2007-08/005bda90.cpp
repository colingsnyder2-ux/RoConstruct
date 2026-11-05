// from server: 100% by auto
// roc 2007-08 005bda90  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bda90
//
// 005bda90  8b442408             mov eax, dword ptr [esp + 8]
// 005bda94  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005bda98  e893f9ffff           call 0x5bd430
// 005bda9d  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdaa0  83e902               sub ecx, 2
// 005bdaa3  740e                 je 0x5bdab3
// 005bdaa5  83e905               sub ecx, 5
// 005bdaa8  7403                 je 0x5bdaad
// 005bdaaa  33c0                 xor eax, eax
// 005bdaac  c3                   ret 
// 005bdaad  8b00                 mov eax, dword ptr [eax]
// 005bdaaf  83c018               add eax, 0x18
// 005bdab2  c3                   ret 
// 005bdab3  8b00                 mov eax, dword ptr [eax]
// 005bdab5  c3                   ret 
// library lua-5.1/lapi.c (function _lua_touserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
