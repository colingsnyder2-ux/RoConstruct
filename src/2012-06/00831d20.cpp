// from server: 100% by auto
// roc 2012-06 00831d20  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831d20
//
// 00831d20  8b442408             mov eax, dword ptr [esp + 8]
// 00831d24  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00831d28  e813fcffff           call 0x831940
// 00831d2d  83780806             cmp dword ptr [eax + 8], 6
// 00831d31  750e                 jne 0x831d41
// 00831d33  8b00                 mov eax, dword ptr [eax]
// 00831d35  80780600             cmp byte ptr [eax + 6], 0
// 00831d39  7406                 je 0x831d41
// 00831d3b  b801000000           mov eax, 1
// 00831d40  c3                   ret 
// 00831d41  33c0                 xor eax, eax
// 00831d43  c3                   ret 
// library lua-5.1/lapi.c (function _lua_iscfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
