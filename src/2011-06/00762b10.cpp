// from server: 100% by auto
// roc 2011-06 00762b10  unit: seg_00760000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762b10
//
// 00762b10  8b442404             mov eax, dword ptr [esp + 4]
// 00762b14  8b4808               mov ecx, dword ptr [eax + 8]
// 00762b17  33d2                 xor edx, edx
// 00762b19  39542408             cmp dword ptr [esp + 8], edx
// 00762b1d  c7410801000000       mov dword ptr [ecx + 8], 1
// 00762b24  0f95c2               setne dl
// 00762b27  8911                 mov dword ptr [ecx], edx
// 00762b29  83400810             add dword ptr [eax + 8], 0x10
// 00762b2d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
