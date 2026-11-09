// from server: 100% by auto
// roc 2007-08 005bdd80  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdd80
//
// 005bdd80  8b442404             mov eax, dword ptr [esp + 4]
// 005bdd84  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdd87  8b542408             mov edx, dword ptr [esp + 8]
// 005bdd8b  8911                 mov dword ptr [ecx], edx
// 005bdd8d  c7410802000000       mov dword ptr [ecx + 8], 2
// 005bdd94  83400810             add dword ptr [eax + 8], 0x10
// 005bdd98  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlightuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
