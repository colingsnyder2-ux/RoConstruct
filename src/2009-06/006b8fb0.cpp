// from server: 100% by auto
// roc 2009-06 006b8fb0  unit: RBX::UniversalTool  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8fb0
//
// 006b8fb0  8b442408             mov eax, dword ptr [esp + 8]
// 006b8fb4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b8fb8  e813fcffff           call 0x6b8bd0
// 006b8fbd  83780806             cmp dword ptr [eax + 8], 6
// 006b8fc1  750e                 jne 0x6b8fd1
// 006b8fc3  8b00                 mov eax, dword ptr [eax]
// 006b8fc5  80780600             cmp byte ptr [eax + 6], 0
// 006b8fc9  7406                 je 0x6b8fd1
// 006b8fcb  b801000000           mov eax, 1
// 006b8fd0  c3                   ret 
// 006b8fd1  33c0                 xor eax, eax
// 006b8fd3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_iscfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
