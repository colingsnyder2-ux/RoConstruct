// from server: 100% by auto
// roc 2007-08 005be4e0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be4e0
//
// 005be4e0  8b442404             mov eax, dword ptr [esp + 4]
// 005be4e4  50                   push eax
// 005be4e5  e8868a0000           call 0x5c6f70
// 005be4ea  83c404               add esp, 4
// 005be4ed  33c0                 xor eax, eax
// 005be4ef  c3                   ret 
// library lua-5.1/lapi.c (function _lua_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
