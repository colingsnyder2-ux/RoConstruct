// from server: 100% by auto
// roc 2008-06 006123f0  unit: seg_00610000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006123f0
//
// 006123f0  8b442404             mov eax, dword ptr [esp + 4]
// 006123f4  8b4808               mov ecx, dword ptr [eax + 8]
// 006123f7  33d2                 xor edx, edx
// 006123f9  39542408             cmp dword ptr [esp + 8], edx
// 006123fd  c7410801000000       mov dword ptr [ecx + 8], 1
// 00612404  0f95c2               setne dl
// 00612407  8911                 mov dword ptr [ecx], edx
// 00612409  83400810             add dword ptr [eax + 8], 0x10
// 0061240d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
