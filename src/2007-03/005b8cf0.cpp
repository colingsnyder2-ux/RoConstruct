// from server: 100% by auto
// roc 2007-03 005b8cf0  unit: seg_005b0000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8cf0
//
// 005b8cf0  8b442408             mov eax, dword ptr [esp + 8]
// 005b8cf4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8cf8  e8b3fbffff           call 0x5b88b0
// 005b8cfd  3da0007c00           cmp eax, 0x7c00a0
// 005b8d02  740d                 je 0x5b8d11
// 005b8d04  8b4008               mov eax, dword ptr [eax + 8]
// 005b8d07  83f804               cmp eax, 4
// 005b8d0a  7408                 je 0x5b8d14
// 005b8d0c  83f803               cmp eax, 3
// 005b8d0f  7403                 je 0x5b8d14
// 005b8d11  33c0                 xor eax, eax
// 005b8d13  c3                   ret 
// 005b8d14  b801000000           mov eax, 1
// 005b8d19  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_isstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
