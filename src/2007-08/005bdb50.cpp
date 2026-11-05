// from server: 100% by auto
// roc 2007-08 005bdb50  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdb50
//
// 005bdb50  8b442404             mov eax, dword ptr [esp + 4]
// 005bdb54  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdb57  c7410800000000       mov dword ptr [ecx + 8], 0
// 005bdb5e  83400810             add dword ptr [eax + 8], 0x10
// 005bdb62  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushnil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
