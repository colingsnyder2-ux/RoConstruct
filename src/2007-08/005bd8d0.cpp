// from server: 100% by auto
// roc 2007-08 005bd8d0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd8d0
//
// 005bd8d0  8b442408             mov eax, dword ptr [esp + 8]
// 005bd8d4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005bd8d8  83ec10               sub esp, 0x10
// 005bd8db  e850fbffff           call 0x5bd430
// 005bd8e0  83780803             cmp dword ptr [eax + 8], 3
// 005bd8e4  7417                 je 0x5bd8fd
// 005bd8e6  8d0c24               lea ecx, [esp]
// 005bd8e9  51                   push ecx
// 005bd8ea  50                   push eax
// 005bd8eb  e8e0270500           call 0x6100d0
// 005bd8f0  83c408               add esp, 8
// 005bd8f3  85c0                 test eax, eax
// 005bd8f5  7506                 jne 0x5bd8fd
// 005bd8f7  d9ee                 fldz 
// 005bd8f9  83c410               add esp, 0x10
// 005bd8fc  c3                   ret 
// 005bd8fd  dd00                 fld qword ptr [eax]
// 005bd8ff  83c410               add esp, 0x10
// 005bd902  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tonumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
