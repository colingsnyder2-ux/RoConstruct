// from server: 100% by auto
// roc 2011-06 00762b50  unit: seg_00760000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762b50
//
// 00762b50  8b442404             mov eax, dword ptr [esp + 4]
// 00762b54  8b4808               mov ecx, dword ptr [eax + 8]
// 00762b57  8901                 mov dword ptr [ecx], eax
// 00762b59  c7410808000000       mov dword ptr [ecx + 8], 8
// 00762b60  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00762b63  83400810             add dword ptr [eax + 8], 0x10
// 00762b67  33d2                 xor edx, edx
// 00762b69  394170               cmp dword ptr [ecx + 0x70], eax
// 00762b6c  0f94c2               sete dl
// 00762b6f  8bc2                 mov eax, edx
// 00762b71  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushthread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
