// from server: 100% by auto
// roc 2008-06 00611fe0  unit: seg_00610000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611fe0
//
// 00611fe0  8b442408             mov eax, dword ptr [esp + 8]
// 00611fe4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00611fe8  e8a3faffff           call 0x611a90
// 00611fed  8b4808               mov ecx, dword ptr [eax + 8]
// 00611ff0  85c9                 test ecx, ecx
// 00611ff2  7410                 je 0x612004
// 00611ff4  83f901               cmp ecx, 1
// 00611ff7  7505                 jne 0x611ffe
// 00611ff9  833800               cmp dword ptr [eax], 0
// 00611ffc  7406                 je 0x612004
// 00611ffe  b801000000           mov eax, 1
// 00612003  c3                   ret 
// 00612004  33c0                 xor eax, eax
// 00612006  c3                   ret 
// library lua-5.1/lapi.c (function _lua_toboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
