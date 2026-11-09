// from server: 100% by auto
// roc 2008-06 00611e40  unit: seg_00610000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611e40
//
// 00611e40  8b442408             mov eax, dword ptr [esp + 8]
// 00611e44  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00611e48  e843fcffff           call 0x611a90
// 00611e4d  83780806             cmp dword ptr [eax + 8], 6
// 00611e51  750e                 jne 0x611e61
// 00611e53  8b00                 mov eax, dword ptr [eax]
// 00611e55  80780600             cmp byte ptr [eax + 6], 0
// 00611e59  7406                 je 0x611e61
// 00611e5b  b801000000           mov eax, 1
// 00611e60  c3                   ret 
// 00611e61  33c0                 xor eax, eax
// 00611e63  c3                   ret 
// library lua-5.1/lapi.c (function _lua_iscfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
