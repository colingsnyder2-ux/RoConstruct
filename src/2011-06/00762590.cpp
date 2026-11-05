// from server: 100% by auto
// roc 2011-06 00762590  unit: seg_00760000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762590
//
// 00762590  8b442408             mov eax, dword ptr [esp + 8]
// 00762594  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00762598  e813fcffff           call 0x7621b0
// 0076259d  83780806             cmp dword ptr [eax + 8], 6
// 007625a1  750e                 jne 0x7625b1
// 007625a3  8b00                 mov eax, dword ptr [eax]
// 007625a5  80780600             cmp byte ptr [eax + 6], 0
// 007625a9  7406                 je 0x7625b1
// 007625ab  b801000000           mov eax, 1
// 007625b0  c3                   ret 
// 007625b1  33c0                 xor eax, eax
// 007625b3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_iscfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
