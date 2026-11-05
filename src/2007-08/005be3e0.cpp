// from server: 100% by auto
// roc 2007-08 005be3e0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be3e0
//
// 005be3e0  8b442404             mov eax, dword ptr [esp + 4]
// 005be3e4  0fb64006             movzx eax, byte ptr [eax + 6]
// 005be3e8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_status)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
