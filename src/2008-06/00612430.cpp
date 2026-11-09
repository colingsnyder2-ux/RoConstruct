// from server: 100% by auto
// roc 2008-06 00612430  unit: seg_00610000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612430
//
// 00612430  8b442404             mov eax, dword ptr [esp + 4]
// 00612434  8b4808               mov ecx, dword ptr [eax + 8]
// 00612437  8901                 mov dword ptr [ecx], eax
// 00612439  c7410808000000       mov dword ptr [ecx + 8], 8
// 00612440  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00612443  83400810             add dword ptr [eax + 8], 0x10
// 00612447  33d2                 xor edx, edx
// 00612449  394170               cmp dword ptr [ecx + 0x70], eax
// 0061244c  0f94c2               sete dl
// 0061244f  8bc2                 mov eax, edx
// 00612451  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushthread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
