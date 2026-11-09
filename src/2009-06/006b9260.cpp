// from server: 100% by auto
// roc 2009-06 006b9260  unit: RBX::UniversalTool  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9260
//
// 006b9260  8b442408             mov eax, dword ptr [esp + 8]
// 006b9264  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b9268  e863f9ffff           call 0x6b8bd0
// 006b926d  8b4808               mov ecx, dword ptr [eax + 8]
// 006b9270  83e902               sub ecx, 2
// 006b9273  740e                 je 0x6b9283
// 006b9275  83e905               sub ecx, 5
// 006b9278  7403                 je 0x6b927d
// 006b927a  33c0                 xor eax, eax
// 006b927c  c3                   ret 
// 006b927d  8b00                 mov eax, dword ptr [eax]
// 006b927f  83c018               add eax, 0x18
// 006b9282  c3                   ret 
// 006b9283  8b00                 mov eax, dword ptr [eax]
// 006b9285  c3                   ret 
// library lua-5.1/lapi.c (function _lua_touserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
