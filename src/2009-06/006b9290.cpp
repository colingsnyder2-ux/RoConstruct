// from server: 100% by auto
// roc 2009-06 006b9290  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9290
//
// 006b9290  8b442408             mov eax, dword ptr [esp + 8]
// 006b9294  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b9298  e833f9ffff           call 0x6b8bd0
// 006b929d  83780808             cmp dword ptr [eax + 8], 8
// 006b92a1  7403                 je 0x6b92a6
// 006b92a3  33c0                 xor eax, eax
// 006b92a5  c3                   ret 
// 006b92a6  8b00                 mov eax, dword ptr [eax]
// 006b92a8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tothread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
