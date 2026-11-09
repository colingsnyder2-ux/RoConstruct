// from server: 100% by auto
// roc 2009-12 00788f90  unit: RBX::UniversalTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788f90
//
// 00788f90  8b442404             mov eax, dword ptr [esp + 4]
// 00788f94  8b4808               mov ecx, dword ptr [eax + 8]
// 00788f97  8901                 mov dword ptr [ecx], eax
// 00788f99  c7410808000000       mov dword ptr [ecx + 8], 8
// 00788fa0  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00788fa3  83400810             add dword ptr [eax + 8], 0x10
// 00788fa7  33d2                 xor edx, edx
// 00788fa9  394170               cmp dword ptr [ecx + 0x70], eax
// 00788fac  0f94c2               sete dl
// 00788faf  8bc2                 mov eax, edx
// 00788fb1  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushthread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
