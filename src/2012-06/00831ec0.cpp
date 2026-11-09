// from server: 100% by auto
// roc 2012-06 00831ec0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831ec0
//
// 00831ec0  8b442408             mov eax, dword ptr [esp + 8]
// 00831ec4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00831ec8  e873faffff           call 0x831940
// 00831ecd  8b4808               mov ecx, dword ptr [eax + 8]
// 00831ed0  85c9                 test ecx, ecx
// 00831ed2  7410                 je 0x831ee4
// 00831ed4  83f901               cmp ecx, 1
// 00831ed7  7505                 jne 0x831ede
// 00831ed9  833800               cmp dword ptr [eax], 0
// 00831edc  7406                 je 0x831ee4
// 00831ede  b801000000           mov eax, 1
// 00831ee3  c3                   ret 
// 00831ee4  33c0                 xor eax, eax
// 00831ee6  c3                   ret 
// library lua-5.1/lapi.c (function _lua_toboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
