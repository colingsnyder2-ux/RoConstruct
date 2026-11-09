// from server: 100% by auto
// roc 2009-12 00788b70  unit: RBX::UniversalTool  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788b70
//
// 00788b70  8b442408             mov eax, dword ptr [esp + 8]
// 00788b74  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00788b78  e873faffff           call 0x7885f0
// 00788b7d  8b4808               mov ecx, dword ptr [eax + 8]
// 00788b80  85c9                 test ecx, ecx
// 00788b82  7410                 je 0x788b94
// 00788b84  83f901               cmp ecx, 1
// 00788b87  7505                 jne 0x788b8e
// 00788b89  833800               cmp dword ptr [eax], 0
// 00788b8c  7406                 je 0x788b94
// 00788b8e  b801000000           mov eax, 1
// 00788b93  c3                   ret 
// 00788b94  33c0                 xor eax, eax
// 00788b96  c3                   ret 
// library lua-5.1/lapi.c (function _lua_toboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
