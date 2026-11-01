// from server: 100% by auto
// roc 2007-03 005b9230  unit: seg_005b0000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9230
//
// 005b9230  8b442404             mov eax, dword ptr [esp + 4]
// 005b9234  8b4808               mov ecx, dword ptr [eax + 8]
// 005b9237  33d2                 xor edx, edx
// 005b9239  39542408             cmp dword ptr [esp + 8], edx
// 005b923d  c7410801000000       mov dword ptr [ecx + 8], 1
// 005b9244  0f95c2               setne dl
// 005b9247  8911                 mov dword ptr [ecx], edx
// 005b9249  83400810             add dword ptr [eax + 8], 0x10
// 005b924d  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
