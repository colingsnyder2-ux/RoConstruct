// from server: 100% by auto
// roc 2009-06 006b9570  unit: RBX::UniversalTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9570
//
// 006b9570  8b442404             mov eax, dword ptr [esp + 4]
// 006b9574  8b4808               mov ecx, dword ptr [eax + 8]
// 006b9577  8901                 mov dword ptr [ecx], eax
// 006b9579  c7410808000000       mov dword ptr [ecx + 8], 8
// 006b9580  8b4810               mov ecx, dword ptr [eax + 0x10]
// 006b9583  83400810             add dword ptr [eax + 8], 0x10
// 006b9587  33d2                 xor edx, edx
// 006b9589  394170               cmp dword ptr [ecx + 0x70], eax
// 006b958c  0f94c2               sete dl
// 006b958f  8bc2                 mov eax, edx
// 006b9591  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushthread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
