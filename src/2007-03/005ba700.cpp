// from server: 100% by auto
// roc 2007-03 005ba700  unit: seg_005b0000  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba700
//
// 005ba700  53                   push ebx
// 005ba701  56                   push esi
// 005ba702  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005ba706  57                   push edi
// 005ba707  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005ba70b  57                   push edi
// 005ba70c  56                   push esi
// 005ba70d  e8cee6ffff           call 0x5b8de0
// 005ba712  8bd8                 mov ebx, eax
// 005ba714  83c408               add esp, 8
// 005ba717  85db                 test ebx, ebx
// 005ba719  7542                 jne 0x5ba75d
// 005ba71b  57                   push edi
// 005ba71c  56                   push esi
// 005ba71d  e88ee5ffff           call 0x5b8cb0
// 005ba722  83c408               add esp, 8
// 005ba725  85c0                 test eax, eax
// 005ba727  7532                 jne 0x5ba75b
// 005ba729  55                   push ebp
// 005ba72a  6a03                 push 3
// 005ba72c  56                   push esi
// 005ba72d  e82ee5ffff           call 0x5b8c60
// 005ba732  57                   push edi
// 005ba733  56                   push esi
// 005ba734  8be8                 mov ebp, eax
// 005ba736  e805e5ffff           call 0x5b8c40
// 005ba73b  50                   push eax
// 005ba73c  56                   push esi
// 005ba73d  e81ee5ffff           call 0x5b8c60
// 005ba742  50                   push eax
// 005ba743  55                   push ebp
// 005ba744  68dc917b00           push 0x7b91dc
// 005ba749  56                   push esi
// 005ba74a  e811eaffff           call 0x5b9160
// 005ba74f  50                   push eax
// 005ba750  57                   push edi
// 005ba751  56                   push esi
// 005ba752  e899fcffff           call 0x5ba3f0
// 005ba757  83c434               add esp, 0x34
// 005ba75a  5d                   pop ebp
// 005ba75b  8bc3                 mov eax, ebx
// 005ba75d  5f                   pop edi
// 005ba75e  5e                   pop esi
// 005ba75f  5b                   pop ebx
// 005ba760  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_checkinteger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
