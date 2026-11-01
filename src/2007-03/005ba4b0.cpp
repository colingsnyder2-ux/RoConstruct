// from server: 100% by auto
// roc 2007-03 005ba4b0  unit: seg_005b0000  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba4b0
//
// 005ba4b0  53                   push ebx
// 005ba4b1  55                   push ebp
// 005ba4b2  56                   push esi
// 005ba4b3  8b742410             mov esi, dword ptr [esp + 0x10]
// 005ba4b7  57                   push edi
// 005ba4b8  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005ba4bc  57                   push edi
// 005ba4bd  56                   push esi
// 005ba4be  e89deaffff           call 0x5b8f60
// 005ba4c3  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 005ba4c7  8bd8                 mov ebx, eax
// 005ba4c9  83c408               add esp, 8
// 005ba4cc  85db                 test ebx, ebx
// 005ba4ce  743d                 je 0x5ba50d
// 005ba4d0  57                   push edi
// 005ba4d1  56                   push esi
// 005ba4d2  e819efffff           call 0x5b93f0
// 005ba4d7  83c408               add esp, 8
// 005ba4da  85c0                 test eax, eax
// 005ba4dc  742f                 je 0x5ba50d
// 005ba4de  55                   push ebp
// 005ba4df  68f0d8ffff           push 0xffffd8f0
// 005ba4e4  56                   push esi
// 005ba4e5  e8e6edffff           call 0x5b92d0
// 005ba4ea  6afe                 push -2
// 005ba4ec  6aff                 push -1
// 005ba4ee  56                   push esi
// 005ba4ef  e82ce8ffff           call 0x5b8d20
// 005ba4f4  83c418               add esp, 0x18
// 005ba4f7  85c0                 test eax, eax
// 005ba4f9  7412                 je 0x5ba50d
// 005ba4fb  6afd                 push -3
// 005ba4fd  56                   push esi
// 005ba4fe  e85de5ffff           call 0x5b8a60
// 005ba503  83c408               add esp, 8
// 005ba506  5f                   pop edi
// 005ba507  5e                   pop esi
// 005ba508  5d                   pop ebp
// 005ba509  8bc3                 mov eax, ebx
// 005ba50b  5b                   pop ebx
// 005ba50c  c3                   ret 
// 005ba50d  57                   push edi
// 005ba50e  56                   push esi
// 005ba50f  e82ce7ffff           call 0x5b8c40
// 005ba514  50                   push eax
// 005ba515  56                   push esi
// 005ba516  e845e7ffff           call 0x5b8c60
// 005ba51b  50                   push eax
// 005ba51c  55                   push ebp
// 005ba51d  68dc917b00           push 0x7b91dc
// 005ba522  56                   push esi
// 005ba523  e838ecffff           call 0x5b9160
// 005ba528  50                   push eax
// 005ba529  57                   push edi
// 005ba52a  56                   push esi
// 005ba52b  e8c0feffff           call 0x5ba3f0
// 005ba530  83c42c               add esp, 0x2c
// 005ba533  5f                   pop edi
// 005ba534  5e                   pop esi
// 005ba535  5d                   pop ebp
// 005ba536  33c0                 xor eax, eax
// 005ba538  5b                   pop ebx
// 005ba539  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_checkudata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
