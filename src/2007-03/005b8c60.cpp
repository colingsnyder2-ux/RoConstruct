// from server: 100% by auto
// roc 2007-03 005b8c60  unit: seg_005b0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8c60
//
// 005b8c60  8b442408             mov eax, dword ptr [esp + 8]
// 005b8c64  83f8ff               cmp eax, -1
// 005b8c67  7506                 jne 0x5b8c6f
// 005b8c69  b81c917b00           mov eax, 0x7b911c
// 005b8c6e  c3                   ret 
// 005b8c6f  8b048500027c00       mov eax, dword ptr [eax*4 + 0x7c0200]
// 005b8c76  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_typename)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
