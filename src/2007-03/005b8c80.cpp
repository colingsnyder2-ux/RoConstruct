// from server: 100% by auto
// roc 2007-03 005b8c80  unit: seg_005b0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8c80
//
// 005b8c80  8b442408             mov eax, dword ptr [esp + 8]
// 005b8c84  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8c88  e823fcffff           call 0x5b88b0
// 005b8c8d  83780806             cmp dword ptr [eax + 8], 6
// 005b8c91  750e                 jne 0x5b8ca1
// 005b8c93  8b00                 mov eax, dword ptr [eax]
// 005b8c95  80780600             cmp byte ptr [eax + 6], 0
// 005b8c99  7406                 je 0x5b8ca1
// 005b8c9b  b801000000           mov eax, 1
// 005b8ca0  c3                   ret 
// 005b8ca1  33c0                 xor eax, eax
// 005b8ca3  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_iscfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
