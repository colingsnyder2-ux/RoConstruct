// from server: 100% by auto
// roc 2007-03 005ffc80  unit: seg_005f0000  size: 276 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ffc80
//
// 005ffc80  83ec18               sub esp, 0x18
// 005ffc83  53                   push ebx
// 005ffc84  56                   push esi
// 005ffc85  57                   push edi
// 005ffc86  8bf0                 mov esi, eax
// 005ffc88  33db                 xor ebx, ebx
// 005ffc8a  55                   push ebp
// 005ffc8b  eb03                 jmp 0x5ffc90
// 005ffc8d  8d4900               lea ecx, [ecx]
// 005ffc90  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 005ffc97  7424                 je 0x5ffcbd
// 005ffc99  681d010000           push 0x11d
// 005ffc9e  56                   push esi
// 005ffc9f  e8cc110000           call 0x600e70
// 005ffca4  50                   push eax
// 005ffca5  8b4634               mov eax, dword ptr [esi + 0x34]
// 005ffca8  6828047c00           push 0x7c0428
// 005ffcad  50                   push eax
// 005ffcae  e88d8bffff           call 0x5f8840
// 005ffcb3  50                   push eax
// 005ffcb4  56                   push esi
// 005ffcb5  e8b6120000           call 0x600f70
// 005ffcba  83c41c               add esp, 0x1c
// 005ffcbd  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 005ffcc0  56                   push esi
// 005ffcc1  e8da260000           call 0x6023a0
// 005ffcc6  8b7e30               mov edi, dword ptr [esi + 0x30]
// 005ffcc9  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 005ffccd  8d541901             lea edx, [ecx + ebx + 1]
// 005ffcd1  83c404               add esp, 4
// 005ffcd4  81fac8000000         cmp edx, 0xc8
// 005ffcda  7e47                 jle 0x5ffd23
// 005ffcdc  8b07                 mov eax, dword ptr [edi]
// 005ffcde  8b403c               mov eax, dword ptr [eax + 0x3c]
// 005ffce1  85c0                 test eax, eax
// 005ffce3  68cc047c00           push 0x7c04cc
// 005ffce8  68c8000000           push 0xc8
// 005ffced  7513                 jne 0x5ffd02
// 005ffcef  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 005ffcf2  6860047c00           push 0x7c0460
// 005ffcf7  51                   push ecx
// 005ffcf8  e8438bffff           call 0x5f8840
// 005ffcfd  83c410               add esp, 0x10
// 005ffd00  eb12                 jmp 0x5ffd14
// 005ffd02  8b5710               mov edx, dword ptr [edi + 0x10]
// 005ffd05  50                   push eax
// 005ffd06  6838047c00           push 0x7c0438
// 005ffd0b  52                   push edx
// 005ffd0c  e82f8bffff           call 0x5f8840
// 005ffd11  83c414               add esp, 0x14
// 005ffd14  6a00                 push 0
// 005ffd16  50                   push eax
// 005ffd17  8b470c               mov eax, dword ptr [edi + 0xc]
// 005ffd1a  50                   push eax
// 005ffd1b  e8b0110000           call 0x600ed0
// 005ffd20  83c40c               add esp, 0xc
// 005ffd23  55                   push ebp
// 005ffd24  56                   push esi
// 005ffd25  e896d8ffff           call 0x5fd5c0
// 005ffd2a  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 005ffd2e  03cb                 add ecx, ebx
// 005ffd30  83c408               add esp, 8
// 005ffd33  6689844fac000000     mov word ptr [edi + ecx*2 + 0xac], ax
// 005ffd3b  83c301               add ebx, 1
// 005ffd3e  837e102c             cmp dword ptr [esi + 0x10], 0x2c
// 005ffd42  750e                 jne 0x5ffd52
// 005ffd44  56                   push esi
// 005ffd45  e856260000           call 0x6023a0
// 005ffd4a  83c404               add esp, 4
// 005ffd4d  e93effffff           jmp 0x5ffc90
// 005ffd52  837e103d             cmp dword ptr [esi + 0x10], 0x3d
// 005ffd56  5d                   pop ebp
// 005ffd57  7514                 jne 0x5ffd6d
// 005ffd59  56                   push esi
// 005ffd5a  e841260000           call 0x6023a0
// 005ffd5f  83c404               add esp, 4
// 005ffd62  8d7c240c             lea edi, [esp + 0xc]
// 005ffd66  e8f5e6ffff           call 0x5fe460
// 005ffd6b  eb06                 jmp 0x5ffd73
// 005ffd6d  33c0                 xor eax, eax
// 005ffd6f  8944240c             mov dword ptr [esp + 0xc], eax
// 005ffd73  50                   push eax
// 005ffd74  8d4c2410             lea ecx, [esp + 0x10]
// 005ffd78  8bd3                 mov edx, ebx
// 005ffd7a  8bc6                 mov eax, esi
// 005ffd7c  e8ffdbffff           call 0x5fd980
// 005ffd81  83c404               add esp, 4
// 005ffd84  8bd3                 mov edx, ebx
// 005ffd86  8bc6                 mov eax, esi
// 005ffd88  e8e3d8ffff           call 0x5fd670
// 005ffd8d  5f                   pop edi
// 005ffd8e  5e                   pop esi
// 005ffd8f  5b                   pop ebx
// 005ffd90  83c418               add esp, 0x18
// 005ffd93  c3                   ret 
// library lua-5.1.1/lparser.c (function _localstat)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
