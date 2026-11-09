// from server: 100% by auto
// roc 2007-08 005bdda0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdda0
//
// 005bdda0  8b442404             mov eax, dword ptr [esp + 4]
// 005bdda4  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdda7  8901                 mov dword ptr [ecx], eax
// 005bdda9  c7410808000000       mov dword ptr [ecx + 8], 8
// 005bddb0  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005bddb3  83400810             add dword ptr [eax + 8], 0x10
// 005bddb7  33d2                 xor edx, edx
// 005bddb9  394170               cmp dword ptr [ecx + 0x70], eax
// 005bddbc  0f94c2               sete dl
// 005bddbf  8bc2                 mov eax, edx
// 005bddc1  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushthread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
