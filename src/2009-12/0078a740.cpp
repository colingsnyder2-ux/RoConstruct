// from server: 100% by auto
// roc 2009-12 0078a740  unit: RBX::UniversalTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a740
//
// 0078a740  56                   push esi
// 0078a741  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0078a745  57                   push edi
// 0078a746  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0078a74a  56                   push esi
// 0078a74b  57                   push edi
// 0078a74c  e83fe2ffff           call 0x788990
// 0078a751  83c408               add esp, 8
// 0078a754  83f8ff               cmp eax, -1
// 0078a757  750f                 jne 0x78a768
// 0078a759  68bc9d9e00           push 0x9e9dbc
// 0078a75e  56                   push esi
// 0078a75f  57                   push edi
// 0078a760  e81bfeffff           call 0x78a580
// 0078a765  83c40c               add esp, 0xc
// 0078a768  5f                   pop edi
// 0078a769  5e                   pop esi
// 0078a76a  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_checkany)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
