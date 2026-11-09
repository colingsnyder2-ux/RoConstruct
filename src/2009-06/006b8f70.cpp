// from server: 100% by auto
// roc 2009-06 006b8f70  unit: RBX::UniversalTool  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8f70
//
// 006b8f70  8b442408             mov eax, dword ptr [esp + 8]
// 006b8f74  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b8f78  e853fcffff           call 0x6b8bd0
// 006b8f7d  3d78c38e00           cmp eax, 0x8ec378
// 006b8f82  7504                 jne 0x6b8f88
// 006b8f84  83c8ff               or eax, 0xffffffff
// 006b8f87  c3                   ret 
// 006b8f88  8b4008               mov eax, dword ptr [eax + 8]
// 006b8f8b  c3                   ret 
// library lua-5.1/lapi.c (function _lua_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
