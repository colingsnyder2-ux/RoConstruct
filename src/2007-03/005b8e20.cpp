// from server: 100% by auto
// roc 2007-03 005b8e20  unit: seg_005b0000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8e20
//
// 005b8e20  8b442408             mov eax, dword ptr [esp + 8]
// 005b8e24  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8e28  e883faffff           call 0x5b88b0
// 005b8e2d  8b4808               mov ecx, dword ptr [eax + 8]
// 005b8e30  85c9                 test ecx, ecx
// 005b8e32  7410                 je 0x5b8e44
// 005b8e34  83f901               cmp ecx, 1
// 005b8e37  7505                 jne 0x5b8e3e
// 005b8e39  833800               cmp dword ptr [eax], 0
// 005b8e3c  7406                 je 0x5b8e44
// 005b8e3e  b801000000           mov eax, 1
// 005b8e43  c3                   ret 
// 005b8e44  33c0                 xor eax, eax
// 005b8e46  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_toboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
