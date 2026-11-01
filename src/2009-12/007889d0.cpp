// from server: 100% by auto
// roc 2009-12 007889d0  unit: RBX::UniversalTool  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007889d0
//
// 007889d0  8b442408             mov eax, dword ptr [esp + 8]
// 007889d4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007889d8  e813fcffff           call 0x7885f0
// 007889dd  83780806             cmp dword ptr [eax + 8], 6
// 007889e1  750e                 jne 0x7889f1
// 007889e3  8b00                 mov eax, dword ptr [eax]
// 007889e5  80780600             cmp byte ptr [eax + 6], 0
// 007889e9  7406                 je 0x7889f1
// 007889eb  b801000000           mov eax, 1
// 007889f0  c3                   ret 
// 007889f1  33c0                 xor eax, eax
// 007889f3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_iscfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
