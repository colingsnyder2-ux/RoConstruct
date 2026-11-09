// from server: 100% by auto
// roc 2008-06 00611e20  unit: seg_00610000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611e20
//
// 00611e20  8b442408             mov eax, dword ptr [esp + 8]
// 00611e24  83f8ff               cmp eax, -1
// 00611e27  7506                 jne 0x611e2f
// 00611e29  b898388400           mov eax, 0x843898
// 00611e2e  c3                   ret 
// 00611e2f  8b048564c28400       mov eax, dword ptr [eax*4 + 0x84c264]
// 00611e36  c3                   ret 
// library lua-5.1/lapi.c (function _lua_typename)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
