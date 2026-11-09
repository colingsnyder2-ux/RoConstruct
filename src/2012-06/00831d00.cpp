// from server: 100% by auto
// roc 2012-06 00831d00  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831d00
//
// 00831d00  8b442408             mov eax, dword ptr [esp + 8]
// 00831d04  83f8ff               cmp eax, -1
// 00831d07  7506                 jne 0x831d0f
// 00831d09  b8f409bd00           mov eax, 0xbd09f4
// 00831d0e  c3                   ret 
// 00831d0f  8b04852cf5bf00       mov eax, dword ptr [eax*4 + 0xbff52c]
// 00831d16  c3                   ret 
// library lua-5.1/lapi.c (function _lua_typename)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
