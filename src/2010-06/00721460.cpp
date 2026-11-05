// from server: 100% by auto
// roc 2010-06 00721460  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721460
//
// 00721460  8b442408             mov eax, dword ptr [esp + 8]
// 00721464  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00721468  e833f9ffff           call 0x720da0
// 0072146d  83780808             cmp dword ptr [eax + 8], 8
// 00721471  7403                 je 0x721476
// 00721473  33c0                 xor eax, eax
// 00721475  c3                   ret 
// 00721476  8b00                 mov eax, dword ptr [eax]
// 00721478  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tothread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
