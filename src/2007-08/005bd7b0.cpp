// from server: 100% by auto
// roc 2007-08 005bd7b0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd7b0
//
// 005bd7b0  8b442408             mov eax, dword ptr [esp + 8]
// 005bd7b4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005bd7b8  e873fcffff           call 0x5bd430
// 005bd7bd  83780806             cmp dword ptr [eax + 8], 6
// 005bd7c1  750e                 jne 0x5bd7d1
// 005bd7c3  8b00                 mov eax, dword ptr [eax]
// 005bd7c5  80780600             cmp byte ptr [eax + 6], 0
// 005bd7c9  7406                 je 0x5bd7d1
// 005bd7cb  b801000000           mov eax, 1
// 005bd7d0  c3                   ret 
// 005bd7d1  33c0                 xor eax, eax
// 005bd7d3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_iscfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
