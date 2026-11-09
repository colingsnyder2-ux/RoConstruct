// from server: 100% by auto
// roc 2007-08 005bda60  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bda60
//
// 005bda60  8b442408             mov eax, dword ptr [esp + 8]
// 005bda64  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005bda68  e8c3f9ffff           call 0x5bd430
// 005bda6d  83780806             cmp dword ptr [eax + 8], 6
// 005bda71  750c                 jne 0x5bda7f
// 005bda73  8b00                 mov eax, dword ptr [eax]
// 005bda75  80780600             cmp byte ptr [eax + 6], 0
// 005bda79  7404                 je 0x5bda7f
// 005bda7b  8b4010               mov eax, dword ptr [eax + 0x10]
// 005bda7e  c3                   ret 
// 005bda7f  33c0                 xor eax, eax
// 005bda81  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tocfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
