// from server: 100% by auto
// roc 2009-06 006b9150  unit: RBX::UniversalTool  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9150
//
// 006b9150  8b442408             mov eax, dword ptr [esp + 8]
// 006b9154  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b9158  e873faffff           call 0x6b8bd0
// 006b915d  8b4808               mov ecx, dword ptr [eax + 8]
// 006b9160  85c9                 test ecx, ecx
// 006b9162  7410                 je 0x6b9174
// 006b9164  83f901               cmp ecx, 1
// 006b9167  7505                 jne 0x6b916e
// 006b9169  833800               cmp dword ptr [eax], 0
// 006b916c  7406                 je 0x6b9174
// 006b916e  b801000000           mov eax, 1
// 006b9173  c3                   ret 
// 006b9174  33c0                 xor eax, eax
// 006b9176  c3                   ret 
// library lua-5.1/lapi.c (function _lua_toboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
