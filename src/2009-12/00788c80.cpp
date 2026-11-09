// from server: 100% by auto
// roc 2009-12 00788c80  unit: RBX::UniversalTool  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788c80
//
// 00788c80  8b442408             mov eax, dword ptr [esp + 8]
// 00788c84  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00788c88  e863f9ffff           call 0x7885f0
// 00788c8d  8b4808               mov ecx, dword ptr [eax + 8]
// 00788c90  83e902               sub ecx, 2
// 00788c93  740e                 je 0x788ca3
// 00788c95  83e905               sub ecx, 5
// 00788c98  7403                 je 0x788c9d
// 00788c9a  33c0                 xor eax, eax
// 00788c9c  c3                   ret 
// 00788c9d  8b00                 mov eax, dword ptr [eax]
// 00788c9f  83c018               add eax, 0x18
// 00788ca2  c3                   ret 
// 00788ca3  8b00                 mov eax, dword ptr [eax]
// 00788ca5  c3                   ret 
// library lua-5.1/lapi.c (function _lua_touserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
