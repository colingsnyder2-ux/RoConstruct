// from server: 100% by auto
// roc 2009-12 0078a660  unit: RBX::UniversalTool  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a660
//
// 0078a660  53                   push ebx
// 0078a661  55                   push ebp
// 0078a662  56                   push esi
// 0078a663  8b742410             mov esi, dword ptr [esp + 0x10]
// 0078a667  57                   push edi
// 0078a668  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0078a66c  57                   push edi
// 0078a66d  56                   push esi
// 0078a66e  e80de6ffff           call 0x788c80
// 0078a673  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0078a677  8bd8                 mov ebx, eax
// 0078a679  83c408               add esp, 8
// 0078a67c  85db                 test ebx, ebx
// 0078a67e  743d                 je 0x78a6bd
// 0078a680  57                   push edi
// 0078a681  56                   push esi
// 0078a682  e8a9eaffff           call 0x789130
// 0078a687  83c408               add esp, 8
// 0078a68a  85c0                 test eax, eax
// 0078a68c  742f                 je 0x78a6bd
// 0078a68e  55                   push ebp
// 0078a68f  68f0d8ffff           push 0xffffd8f0
// 0078a694  56                   push esi
// 0078a695  e856e9ffff           call 0x788ff0
// 0078a69a  6afe                 push -2
// 0078a69c  6aff                 push -1
// 0078a69e  56                   push esi
// 0078a69f  e8cce3ffff           call 0x788a70
// 0078a6a4  83c418               add esp, 0x18
// 0078a6a7  85c0                 test eax, eax
// 0078a6a9  7412                 je 0x78a6bd
// 0078a6ab  6afd                 push -3
// 0078a6ad  56                   push esi
// 0078a6ae  e8fde0ffff           call 0x7887b0
// 0078a6b3  83c408               add esp, 8
// 0078a6b6  5f                   pop edi
// 0078a6b7  5e                   pop esi
// 0078a6b8  5d                   pop ebp
// 0078a6b9  8bc3                 mov eax, ebx
// 0078a6bb  5b                   pop ebx
// 0078a6bc  c3                   ret 
// 0078a6bd  57                   push edi
// 0078a6be  56                   push esi
// 0078a6bf  e8cce2ffff           call 0x788990
// 0078a6c4  50                   push eax
// 0078a6c5  56                   push esi
// 0078a6c6  e8e5e2ffff           call 0x7889b0
// 0078a6cb  50                   push eax
// 0078a6cc  55                   push ebp
// 0078a6cd  68a89d9e00           push 0x9e9da8
// 0078a6d2  56                   push esi
// 0078a6d3  e8a8e7ffff           call 0x788e80
// 0078a6d8  50                   push eax
// 0078a6d9  57                   push edi
// 0078a6da  56                   push esi
// 0078a6db  e8a0feffff           call 0x78a580
// 0078a6e0  83c42c               add esp, 0x2c
// 0078a6e3  5f                   pop edi
// 0078a6e4  5e                   pop esi
// 0078a6e5  5d                   pop ebp
// 0078a6e6  33c0                 xor eax, eax
// 0078a6e8  5b                   pop ebx
// 0078a6e9  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_checkudata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
