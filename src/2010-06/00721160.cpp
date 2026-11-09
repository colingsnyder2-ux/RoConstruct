// from server: 100% by auto
// roc 2010-06 00721160  unit: RBX::UniversalTool  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721160
//
// 00721160  8b442408             mov eax, dword ptr [esp + 8]
// 00721164  83f8ff               cmp eax, -1
// 00721167  7506                 jne 0x72116f
// 00721169  b8a0cea400           mov eax, 0xa4cea0
// 0072116e  c3                   ret 
// 0072116f  8b0485082ea500       mov eax, dword ptr [eax*4 + 0xa52e08]
// 00721176  c3                   ret 
// library lua-5.1/lapi.c (function _lua_typename)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
