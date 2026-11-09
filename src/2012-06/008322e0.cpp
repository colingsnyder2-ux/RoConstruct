// from server: 100% by auto
// roc 2012-06 008322e0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008322e0
//
// 008322e0  8b442404             mov eax, dword ptr [esp + 4]
// 008322e4  8b4808               mov ecx, dword ptr [eax + 8]
// 008322e7  8901                 mov dword ptr [ecx], eax
// 008322e9  c7410808000000       mov dword ptr [ecx + 8], 8
// 008322f0  8b4810               mov ecx, dword ptr [eax + 0x10]
// 008322f3  83400810             add dword ptr [eax + 8], 0x10
// 008322f7  33d2                 xor edx, edx
// 008322f9  394170               cmp dword ptr [ecx + 0x70], eax
// 008322fc  0f94c2               sete dl
// 008322ff  8bc2                 mov eax, edx
// 00832301  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushthread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
