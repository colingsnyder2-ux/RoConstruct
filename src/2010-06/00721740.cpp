// from server: 100% by auto
// roc 2010-06 00721740  unit: RBX::UniversalTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721740
//
// 00721740  8b442404             mov eax, dword ptr [esp + 4]
// 00721744  8b4808               mov ecx, dword ptr [eax + 8]
// 00721747  8901                 mov dword ptr [ecx], eax
// 00721749  c7410808000000       mov dword ptr [ecx + 8], 8
// 00721750  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00721753  83400810             add dword ptr [eax + 8], 0x10
// 00721757  33d2                 xor edx, edx
// 00721759  394170               cmp dword ptr [ecx + 0x70], eax
// 0072175c  0f94c2               sete dl
// 0072175f  8bc2                 mov eax, edx
// 00721761  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushthread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
