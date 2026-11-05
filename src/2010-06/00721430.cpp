// from server: 100% by auto
// roc 2010-06 00721430  unit: RBX::UniversalTool  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721430
//
// 00721430  8b442408             mov eax, dword ptr [esp + 8]
// 00721434  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00721438  e863f9ffff           call 0x720da0
// 0072143d  8b4808               mov ecx, dword ptr [eax + 8]
// 00721440  83e902               sub ecx, 2
// 00721443  740e                 je 0x721453
// 00721445  83e905               sub ecx, 5
// 00721448  7403                 je 0x72144d
// 0072144a  33c0                 xor eax, eax
// 0072144c  c3                   ret 
// 0072144d  8b00                 mov eax, dword ptr [eax]
// 0072144f  83c018               add eax, 0x18
// 00721452  c3                   ret 
// 00721453  8b00                 mov eax, dword ptr [eax]
// 00721455  c3                   ret 
// library lua-5.1/lapi.c (function _lua_touserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
