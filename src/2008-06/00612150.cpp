// from server: 100% by auto
// roc 2008-06 00612150  unit: seg_00610000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612150
//
// 00612150  8b442408             mov eax, dword ptr [esp + 8]
// 00612154  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00612158  e833f9ffff           call 0x611a90
// 0061215d  83780808             cmp dword ptr [eax + 8], 8
// 00612161  7403                 je 0x612166
// 00612163  33c0                 xor eax, eax
// 00612165  c3                   ret 
// 00612166  8b00                 mov eax, dword ptr [eax]
// 00612168  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tothread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
