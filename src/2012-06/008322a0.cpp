// from server: 100% by auto
// roc 2012-06 008322a0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008322a0
//
// 008322a0  8b442404             mov eax, dword ptr [esp + 4]
// 008322a4  8b4808               mov ecx, dword ptr [eax + 8]
// 008322a7  33d2                 xor edx, edx
// 008322a9  39542408             cmp dword ptr [esp + 8], edx
// 008322ad  c7410801000000       mov dword ptr [ecx + 8], 1
// 008322b4  0f95c2               setne dl
// 008322b7  8911                 mov dword ptr [ecx], edx
// 008322b9  83400810             add dword ptr [eax + 8], 0x10
// 008322bd  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
