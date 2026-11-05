// from server: 100% by auto
// roc 2009-12 0078a770  unit: RBX::UniversalTool  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a770
//
// 0078a770  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0078a774  53                   push ebx
// 0078a775  56                   push esi
// 0078a776  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0078a77a  57                   push edi
// 0078a77b  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0078a77f  50                   push eax
// 0078a780  57                   push edi
// 0078a781  56                   push esi
// 0078a782  e819e4ffff           call 0x788ba0
// 0078a787  8bd8                 mov ebx, eax
// 0078a789  83c40c               add esp, 0xc
// 0078a78c  85db                 test ebx, ebx
// 0078a78e  7534                 jne 0x78a7c4
// 0078a790  55                   push ebp
// 0078a791  6a04                 push 4
// 0078a793  56                   push esi
// 0078a794  e817e2ffff           call 0x7889b0
// 0078a799  57                   push edi
// 0078a79a  56                   push esi
// 0078a79b  8be8                 mov ebp, eax
// 0078a79d  e8eee1ffff           call 0x788990
// 0078a7a2  50                   push eax
// 0078a7a3  56                   push esi
// 0078a7a4  e807e2ffff           call 0x7889b0
// 0078a7a9  50                   push eax
// 0078a7aa  55                   push ebp
// 0078a7ab  68a89d9e00           push 0x9e9da8
// 0078a7b0  56                   push esi
// 0078a7b1  e8cae6ffff           call 0x788e80
// 0078a7b6  50                   push eax
// 0078a7b7  57                   push edi
// 0078a7b8  56                   push esi
// 0078a7b9  e8c2fdffff           call 0x78a580
// 0078a7be  83c434               add esp, 0x34
// 0078a7c1  8bc3                 mov eax, ebx
// 0078a7c3  5d                   pop ebp
// 0078a7c4  5f                   pop edi
// 0078a7c5  5e                   pop esi
// 0078a7c6  5b                   pop ebx
// 0078a7c7  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_checklstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
