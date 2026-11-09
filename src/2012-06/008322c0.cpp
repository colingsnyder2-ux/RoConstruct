// from server: 100% by auto
// roc 2012-06 008322c0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008322c0
//
// 008322c0  8b442404             mov eax, dword ptr [esp + 4]
// 008322c4  8b4808               mov ecx, dword ptr [eax + 8]
// 008322c7  8b542408             mov edx, dword ptr [esp + 8]
// 008322cb  8911                 mov dword ptr [ecx], edx
// 008322cd  c7410802000000       mov dword ptr [ecx + 8], 2
// 008322d4  83400810             add dword ptr [eax + 8], 0x10
// 008322d8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlightuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
