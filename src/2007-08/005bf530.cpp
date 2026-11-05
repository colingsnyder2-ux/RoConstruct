// from server: 100% by auto
// roc 2007-08 005bf530  unit: boost::detail::H::?$sp_counted_impl_p  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bf530
//
// 005bf530  53                   push ebx
// 005bf531  55                   push ebp
// 005bf532  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 005bf536  85ed                 test ebp, ebp
// 005bf538  56                   push esi
// 005bf539  8b742410             mov esi, dword ptr [esp + 0x10]
// 005bf53d  57                   push edi
// 005bf53e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005bf542  0f8499000000         je 0x5bf5e1
// 005bf548  33db                 xor ebx, ebx
// 005bf54a  391f                 cmp dword ptr [edi], ebx
// 005bf54c  8bc7                 mov eax, edi
// 005bf54e  740b                 je 0x5bf55b
// 005bf550  83c008               add eax, 8
// 005bf553  83c301               add ebx, 1
// 005bf556  833800               cmp dword ptr [eax], 0
// 005bf559  75f5                 jne 0x5bf550
// 005bf55b  53                   push ebx
// 005bf55c  6878917b00           push 0x7b9178
// 005bf561  68f0d8ffff           push 0xffffd8f0
// 005bf566  56                   push esi
// 005bf567  e8f4f4ffff           call 0x5bea60
// 005bf56c  55                   push ebp
// 005bf56d  6aff                 push -1
// 005bf56f  56                   push esi
// 005bf570  e88be8ffff           call 0x5bde00
// 005bf575  6aff                 push -1
// 005bf577  56                   push esi
// 005bf578  e8f3e1ffff           call 0x5bd770
// 005bf57d  83c424               add esp, 0x24
// 005bf580  83f805               cmp eax, 5
// 005bf583  743f                 je 0x5bf5c4
// 005bf585  6afe                 push -2
// 005bf587  56                   push esi
// 005bf588  e803e0ffff           call 0x5bd590
// 005bf58d  53                   push ebx
// 005bf58e  55                   push ebp
// 005bf58f  68eed8ffff           push 0xffffd8ee
// 005bf594  56                   push esi
// 005bf595  e8c6f4ffff           call 0x5bea60
// 005bf59a  83c418               add esp, 0x18
// 005bf59d  85c0                 test eax, eax
// 005bf59f  740f                 je 0x5bf5b0
// 005bf5a1  55                   push ebp
// 005bf5a2  6858917b00           push 0x7b9158
// 005bf5a7  56                   push esi
// 005bf5a8  e833f3ffff           call 0x5be8e0
// 005bf5ad  83c40c               add esp, 0xc
// 005bf5b0  6aff                 push -1
// 005bf5b2  56                   push esi
// 005bf5b3  e888e1ffff           call 0x5bd740
// 005bf5b8  55                   push ebp
// 005bf5b9  6afd                 push -3
// 005bf5bb  56                   push esi
// 005bf5bc  e85feaffff           call 0x5be020
// 005bf5c1  83c414               add esp, 0x14
// 005bf5c4  6afe                 push -2
// 005bf5c6  56                   push esi
// 005bf5c7  e814e0ffff           call 0x5bd5e0
// 005bf5cc  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005bf5d0  83c8ff               or eax, 0xffffffff
// 005bf5d3  2bc5                 sub eax, ebp
// 005bf5d5  50                   push eax
// 005bf5d6  56                   push esi
// 005bf5d7  e854e0ffff           call 0x5bd630
// 005bf5dc  83c410               add esp, 0x10
// 005bf5df  eb04                 jmp 0x5bf5e5
// 005bf5e1  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005bf5e5  833f00               cmp dword ptr [edi], 0
// 005bf5e8  744d                 je 0x5bf637
// 005bf5ea  b8feffffff           mov eax, 0xfffffffe
// 005bf5ef  2bc5                 sub eax, ebp
// 005bf5f1  89442418             mov dword ptr [esp + 0x18], eax
// 005bf5f5  85ed                 test ebp, ebp
// 005bf5f7  7e1a                 jle 0x5bf613
// 005bf5f9  8bdd                 mov ebx, ebp
// 005bf5fb  f7db                 neg ebx
// 005bf5fd  8d4900               lea ecx, [ecx]
// 005bf600  53                   push ebx
// 005bf601  56                   push esi
// 005bf602  e839e1ffff           call 0x5bd740
// 005bf607  83c408               add esp, 8
// 005bf60a  83ed01               sub ebp, 1
// 005bf60d  75f1                 jne 0x5bf600
// 005bf60f  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005bf613  8b4f04               mov ecx, dword ptr [edi + 4]
// 005bf616  55                   push ebp
// 005bf617  51                   push ecx
// 005bf618  56                   push esi
// 005bf619  e8a2e6ffff           call 0x5bdcc0
// 005bf61e  8b17                 mov edx, dword ptr [edi]
// 005bf620  8b442424             mov eax, dword ptr [esp + 0x24]
// 005bf624  52                   push edx
// 005bf625  50                   push eax
// 005bf626  56                   push esi
// 005bf627  e8f4e9ffff           call 0x5be020
// 005bf62c  83c708               add edi, 8
// 005bf62f  83c418               add esp, 0x18
// 005bf632  833f00               cmp dword ptr [edi], 0
// 005bf635  75be                 jne 0x5bf5f5
// 005bf637  83c9ff               or ecx, 0xffffffff
// 005bf63a  2bcd                 sub ecx, ebp
// 005bf63c  51                   push ecx
// 005bf63d  56                   push esi
// 005bf63e  e84ddfffff           call 0x5bd590
// 005bf643  83c408               add esp, 8
// 005bf646  5f                   pop edi
// 005bf647  5e                   pop esi
// 005bf648  5d                   pop ebp
// 005bf649  5b                   pop ebx
// 005bf64a  c3                   ret 
// library lua-5.1.2/lauxlib.c (function _luaL_openlib)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lauxlib.c
