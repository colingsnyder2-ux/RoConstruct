// from server: 100% by auto
// roc 2009-12 0078a150  unit: RBX::UniversalTool  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a150
//
// 0078a150  53                   push ebx
// 0078a151  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0078a155  8d830f270000         lea eax, [ebx + 0x270f]
// 0078a15b  56                   push esi
// 0078a15c  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0078a160  3d0f270000           cmp eax, 0x270f
// 0078a165  770d                 ja 0x78a174
// 0078a167  56                   push esi
// 0078a168  e833e6ffff           call 0x7887a0
// 0078a16d  83c404               add esp, 4
// 0078a170  8d5c0301             lea ebx, [ebx + eax + 1]
// 0078a174  6aff                 push -1
// 0078a176  56                   push esi
// 0078a177  e814e8ffff           call 0x788990
// 0078a17c  83c408               add esp, 8
// 0078a17f  85c0                 test eax, eax
// 0078a181  7511                 jne 0x78a194
// 0078a183  6afe                 push -2
// 0078a185  56                   push esi
// 0078a186  e825e6ffff           call 0x7887b0
// 0078a18b  83c408               add esp, 8
// 0078a18e  5e                   pop esi
// 0078a18f  83c8ff               or eax, 0xffffffff
// 0078a192  5b                   pop ebx
// 0078a193  c3                   ret 
// 0078a194  57                   push edi
// 0078a195  6a00                 push 0
// 0078a197  53                   push ebx
// 0078a198  56                   push esi
// 0078a199  e8f2eeffff           call 0x789090
// 0078a19e  6aff                 push -1
// 0078a1a0  56                   push esi
// 0078a1a1  e88ae9ffff           call 0x788b30
// 0078a1a6  6afe                 push -2
// 0078a1a8  56                   push esi
// 0078a1a9  8bf8                 mov edi, eax
// 0078a1ab  e800e6ffff           call 0x7887b0
// 0078a1b0  83c41c               add esp, 0x1c
// 0078a1b3  85ff                 test edi, edi
// 0078a1b5  7425                 je 0x78a1dc
// 0078a1b7  57                   push edi
// 0078a1b8  53                   push ebx
// 0078a1b9  56                   push esi
// 0078a1ba  e8d1eeffff           call 0x789090
// 0078a1bf  6a00                 push 0
// 0078a1c1  53                   push ebx
// 0078a1c2  56                   push esi
// 0078a1c3  e848f1ffff           call 0x789310
// 0078a1c8  83c418               add esp, 0x18
// 0078a1cb  57                   push edi
// 0078a1cc  53                   push ebx
// 0078a1cd  56                   push esi
// 0078a1ce  e83df1ffff           call 0x789310
// 0078a1d3  83c40c               add esp, 0xc
// 0078a1d6  8bc7                 mov eax, edi
// 0078a1d8  5f                   pop edi
// 0078a1d9  5e                   pop esi
// 0078a1da  5b                   pop ebx
// 0078a1db  c3                   ret 
// 0078a1dc  53                   push ebx
// 0078a1dd  56                   push esi
// 0078a1de  e82deaffff           call 0x788c10
// 0078a1e3  8bf8                 mov edi, eax
// 0078a1e5  83c408               add esp, 8
// 0078a1e8  47                   inc edi
// 0078a1e9  57                   push edi
// 0078a1ea  53                   push ebx
// 0078a1eb  56                   push esi
// 0078a1ec  e81ff1ffff           call 0x789310
// 0078a1f1  83c40c               add esp, 0xc
// 0078a1f4  8bc7                 mov eax, edi
// 0078a1f6  5f                   pop edi
// 0078a1f7  5e                   pop esi
// 0078a1f8  5b                   pop ebx
// 0078a1f9  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_ref)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
