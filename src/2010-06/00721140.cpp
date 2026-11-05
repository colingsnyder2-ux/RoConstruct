// from server: 100% by auto
// roc 2010-06 00721140  unit: RBX::UniversalTool  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721140
//
// 00721140  8b442408             mov eax, dword ptr [esp + 8]
// 00721144  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00721148  e853fcffff           call 0x720da0
// 0072114d  3d78dca400           cmp eax, 0xa4dc78
// 00721152  7504                 jne 0x721158
// 00721154  83c8ff               or eax, 0xffffffff
// 00721157  c3                   ret 
// 00721158  8b4008               mov eax, dword ptr [eax + 8]
// 0072115b  c3                   ret 
// library lua-5.1/lapi.c (function _lua_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
