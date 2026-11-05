// from server: 100% by auto
// roc 2007-08 005bd770  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd770
//
// 005bd770  8b442408             mov eax, dword ptr [esp + 8]
// 005bd774  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005bd778  e8b3fcffff           call 0x5bd430
// 005bd77d  3de82f7c00           cmp eax, 0x7c2fe8
// 005bd782  7504                 jne 0x5bd788
// 005bd784  83c8ff               or eax, 0xffffffff
// 005bd787  c3                   ret 
// 005bd788  8b4008               mov eax, dword ptr [eax + 8]
// 005bd78b  c3                   ret 
// library lua-5.1/lapi.c (function _lua_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
