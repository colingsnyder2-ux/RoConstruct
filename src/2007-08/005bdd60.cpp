// from server: 100% by auto
// roc 2007-08 005bdd60  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdd60
//
// 005bdd60  8b442404             mov eax, dword ptr [esp + 4]
// 005bdd64  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdd67  33d2                 xor edx, edx
// 005bdd69  39542408             cmp dword ptr [esp + 8], edx
// 005bdd6d  c7410801000000       mov dword ptr [ecx + 8], 1
// 005bdd74  0f95c2               setne dl
// 005bdd77  8911                 mov dword ptr [ecx], edx
// 005bdd79  83400810             add dword ptr [eax + 8], 0x10
// 005bdd7d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
