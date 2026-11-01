// from server: 100% by auto
// roc 2007-03 005b8c40  unit: seg_005b0000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8c40
//
// 005b8c40  8b442408             mov eax, dword ptr [esp + 8]
// 005b8c44  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8c48  e863fcffff           call 0x5b88b0
// 005b8c4d  3da0007c00           cmp eax, 0x7c00a0
// 005b8c52  7504                 jne 0x5b8c58
// 005b8c54  83c8ff               or eax, 0xffffffff
// 005b8c57  c3                   ret 
// 005b8c58  8b4008               mov eax, dword ptr [eax + 8]
// 005b8c5b  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
