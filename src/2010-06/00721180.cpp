// from server: 100% by auto
// roc 2010-06 00721180  unit: RBX::UniversalTool  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721180
//
// 00721180  8b442408             mov eax, dword ptr [esp + 8]
// 00721184  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00721188  e813fcffff           call 0x720da0
// 0072118d  83780806             cmp dword ptr [eax + 8], 6
// 00721191  750e                 jne 0x7211a1
// 00721193  8b00                 mov eax, dword ptr [eax]
// 00721195  80780600             cmp byte ptr [eax + 6], 0
// 00721199  7406                 je 0x7211a1
// 0072119b  b801000000           mov eax, 1
// 007211a0  c3                   ret 
// 007211a1  33c0                 xor eax, eax
// 007211a3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_iscfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
