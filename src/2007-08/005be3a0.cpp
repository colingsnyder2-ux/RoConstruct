// from server: 100% by auto
// roc 2007-08 005be3a0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be3a0
//
// 005be3a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005be3a4  8b4108               mov eax, dword ptr [ecx + 8]
// 005be3a7  83e810               sub eax, 0x10
// 005be3aa  83780806             cmp dword ptr [eax + 8], 6
// 005be3ae  7522                 jne 0x5be3d2
// 005be3b0  8b00                 mov eax, dword ptr [eax]
// 005be3b2  80780600             cmp byte ptr [eax + 6], 0
// 005be3b6  751a                 jne 0x5be3d2
// 005be3b8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005be3bc  8b4010               mov eax, dword ptr [eax + 0x10]
// 005be3bf  6a00                 push 0
// 005be3c1  52                   push edx
// 005be3c2  8b542410             mov edx, dword ptr [esp + 0x10]
// 005be3c6  52                   push edx
// 005be3c7  50                   push eax
// 005be3c8  51                   push ecx
// 005be3c9  e882550500           call 0x613950
// 005be3ce  83c414               add esp, 0x14
// 005be3d1  c3                   ret 
// 005be3d2  b801000000           mov eax, 1
// 005be3d7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
