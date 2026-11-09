// from server: 100% by auto
// roc 2007-08 005bd950  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd950
//
// 005bd950  8b442408             mov eax, dword ptr [esp + 8]
// 005bd954  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005bd958  e8d3faffff           call 0x5bd430
// 005bd95d  8b4808               mov ecx, dword ptr [eax + 8]
// 005bd960  85c9                 test ecx, ecx
// 005bd962  7410                 je 0x5bd974
// 005bd964  83f901               cmp ecx, 1
// 005bd967  7505                 jne 0x5bd96e
// 005bd969  833800               cmp dword ptr [eax], 0
// 005bd96c  7406                 je 0x5bd974
// 005bd96e  b801000000           mov eax, 1
// 005bd973  c3                   ret 
// 005bd974  33c0                 xor eax, eax
// 005bd976  c3                   ret 
// library lua-5.1/lapi.c (function _lua_toboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
