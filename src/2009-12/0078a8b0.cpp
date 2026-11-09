// from server: 100% by auto
// roc 2009-12 0078a8b0  unit: RBX::UniversalTool  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a8b0
//
// 0078a8b0  53                   push ebx
// 0078a8b1  56                   push esi
// 0078a8b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0078a8b6  57                   push edi
// 0078a8b7  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0078a8bb  57                   push edi
// 0078a8bc  56                   push esi
// 0078a8bd  e86ee2ffff           call 0x788b30
// 0078a8c2  8bd8                 mov ebx, eax
// 0078a8c4  83c408               add esp, 8
// 0078a8c7  85db                 test ebx, ebx
// 0078a8c9  7542                 jne 0x78a90d
// 0078a8cb  57                   push edi
// 0078a8cc  56                   push esi
// 0078a8cd  e82ee1ffff           call 0x788a00
// 0078a8d2  83c408               add esp, 8
// 0078a8d5  85c0                 test eax, eax
// 0078a8d7  7532                 jne 0x78a90b
// 0078a8d9  55                   push ebp
// 0078a8da  6a03                 push 3
// 0078a8dc  56                   push esi
// 0078a8dd  e8cee0ffff           call 0x7889b0
// 0078a8e2  57                   push edi
// 0078a8e3  56                   push esi
// 0078a8e4  8be8                 mov ebp, eax
// 0078a8e6  e8a5e0ffff           call 0x788990
// 0078a8eb  50                   push eax
// 0078a8ec  56                   push esi
// 0078a8ed  e8bee0ffff           call 0x7889b0
// 0078a8f2  50                   push eax
// 0078a8f3  55                   push ebp
// 0078a8f4  68a89d9e00           push 0x9e9da8
// 0078a8f9  56                   push esi
// 0078a8fa  e881e5ffff           call 0x788e80
// 0078a8ff  50                   push eax
// 0078a900  57                   push edi
// 0078a901  56                   push esi
// 0078a902  e879fcffff           call 0x78a580
// 0078a907  83c434               add esp, 0x34
// 0078a90a  5d                   pop ebp
// 0078a90b  8bc3                 mov eax, ebx
// 0078a90d  5f                   pop edi
// 0078a90e  5e                   pop esi
// 0078a90f  5b                   pop ebx
// 0078a910  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_checkinteger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
