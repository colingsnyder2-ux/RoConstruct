// from server: 100% by auto
// roc 2011-06 00762730  unit: seg_00760000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762730
//
// 00762730  8b442408             mov eax, dword ptr [esp + 8]
// 00762734  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00762738  e873faffff           call 0x7621b0
// 0076273d  8b4808               mov ecx, dword ptr [eax + 8]
// 00762740  85c9                 test ecx, ecx
// 00762742  7410                 je 0x762754
// 00762744  83f901               cmp ecx, 1
// 00762747  7505                 jne 0x76274e
// 00762749  833800               cmp dword ptr [eax], 0
// 0076274c  7406                 je 0x762754
// 0076274e  b801000000           mov eax, 1
// 00762753  c3                   ret 
// 00762754  33c0                 xor eax, eax
// 00762756  c3                   ret 
// library lua-5.1/lapi.c (function _lua_toboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
