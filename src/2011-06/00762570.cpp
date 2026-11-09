// from server: 100% by auto
// roc 2011-06 00762570  unit: seg_00760000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762570
//
// 00762570  8b442408             mov eax, dword ptr [esp + 8]
// 00762574  83f8ff               cmp eax, -1
// 00762577  7506                 jne 0x76257f
// 00762579  b8d064ab00           mov eax, 0xab64d0
// 0076257e  c3                   ret 
// 0076257f  8b048524ddab00       mov eax, dword ptr [eax*4 + 0xabdd24]
// 00762586  c3                   ret 
// library lua-5.1/lapi.c (function _lua_typename)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
