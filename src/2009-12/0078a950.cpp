// from server: 100% by auto
// roc 2009-12 0078a950  unit: RBX::UniversalTool  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a950
//
// 0078a950  53                   push ebx
// 0078a951  55                   push ebp
// 0078a952  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0078a956  56                   push esi
// 0078a957  8b742410             mov esi, dword ptr [esp + 0x10]
// 0078a95b  57                   push edi
// 0078a95c  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0078a960  85ed                 test ebp, ebp
// 0078a962  0f8498000000         je 0x78aa00
// 0078a968  33db                 xor ebx, ebx
// 0078a96a  8bc7                 mov eax, edi
// 0078a96c  391f                 cmp dword ptr [edi], ebx
// 0078a96e  7409                 je 0x78a979
// 0078a970  83c008               add eax, 8
// 0078a973  43                   inc ebx
// 0078a974  833800               cmp dword ptr [eax], 0
// 0078a977  75f7                 jne 0x78a970
// 0078a979  6a01                 push 1
// 0078a97b  68ec9d9e00           push 0x9e9dec
// 0078a980  68f0d8ffff           push 0xffffd8f0
// 0078a985  56                   push esi
// 0078a986  e8e5f4ffff           call 0x789e70
// 0078a98b  55                   push ebp
// 0078a98c  6aff                 push -1
// 0078a98e  56                   push esi
// 0078a98f  e85ce6ffff           call 0x788ff0
// 0078a994  6aff                 push -1
// 0078a996  56                   push esi
// 0078a997  e8f4dfffff           call 0x788990
// 0078a99c  83c424               add esp, 0x24
// 0078a99f  83f805               cmp eax, 5
// 0078a9a2  743f                 je 0x78a9e3
// 0078a9a4  6afe                 push -2
// 0078a9a6  56                   push esi
// 0078a9a7  e804deffff           call 0x7887b0
// 0078a9ac  53                   push ebx
// 0078a9ad  55                   push ebp
// 0078a9ae  68eed8ffff           push 0xffffd8ee
// 0078a9b3  56                   push esi
// 0078a9b4  e8b7f4ffff           call 0x789e70
// 0078a9b9  83c418               add esp, 0x18
// 0078a9bc  85c0                 test eax, eax
// 0078a9be  740f                 je 0x78a9cf
// 0078a9c0  55                   push ebp
// 0078a9c1  68cc9d9e00           push 0x9e9dcc
// 0078a9c6  56                   push esi
// 0078a9c7  e824f3ffff           call 0x789cf0
// 0078a9cc  83c40c               add esp, 0xc
// 0078a9cf  6aff                 push -1
// 0078a9d1  56                   push esi
// 0078a9d2  e889dfffff           call 0x788960
// 0078a9d7  55                   push ebp
// 0078a9d8  6afd                 push -3
// 0078a9da  56                   push esi
// 0078a9db  e850e8ffff           call 0x789230
// 0078a9e0  83c414               add esp, 0x14
// 0078a9e3  6afe                 push -2
// 0078a9e5  56                   push esi
// 0078a9e6  e815deffff           call 0x788800
// 0078a9eb  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0078a9ef  83c8ff               or eax, 0xffffffff
// 0078a9f2  2bc5                 sub eax, ebp
// 0078a9f4  50                   push eax
// 0078a9f5  56                   push esi
// 0078a9f6  e855deffff           call 0x788850
// 0078a9fb  83c410               add esp, 0x10
// 0078a9fe  eb04                 jmp 0x78aa04
// 0078aa00  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0078aa04  833f00               cmp dword ptr [edi], 0
// 0078aa07  744e                 je 0x78aa57
// 0078aa09  b8feffffff           mov eax, 0xfffffffe
// 0078aa0e  2bc5                 sub eax, ebp
// 0078aa10  89442418             mov dword ptr [esp + 0x18], eax
// 0078aa14  85ed                 test ebp, ebp
// 0078aa16  7e1b                 jle 0x78aa33
// 0078aa18  8bdd                 mov ebx, ebp
// 0078aa1a  f7db                 neg ebx
// 0078aa1c  8d642400             lea esp, [esp]
// 0078aa20  53                   push ebx
// 0078aa21  56                   push esi
// 0078aa22  e839dfffff           call 0x788960
// 0078aa27  83c408               add esp, 8
// 0078aa2a  83ed01               sub ebp, 1
// 0078aa2d  75f1                 jne 0x78aa20
// 0078aa2f  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0078aa33  8b4f04               mov ecx, dword ptr [edi + 4]
// 0078aa36  55                   push ebp
// 0078aa37  51                   push ecx
// 0078aa38  56                   push esi
// 0078aa39  e872e4ffff           call 0x788eb0
// 0078aa3e  8b17                 mov edx, dword ptr [edi]
// 0078aa40  8b442424             mov eax, dword ptr [esp + 0x24]
// 0078aa44  52                   push edx
// 0078aa45  50                   push eax
// 0078aa46  56                   push esi
// 0078aa47  e8e4e7ffff           call 0x789230
// 0078aa4c  83c708               add edi, 8
// 0078aa4f  83c418               add esp, 0x18
// 0078aa52  833f00               cmp dword ptr [edi], 0
// 0078aa55  75bd                 jne 0x78aa14
// 0078aa57  83c9ff               or ecx, 0xffffffff
// 0078aa5a  2bcd                 sub ecx, ebp
// 0078aa5c  51                   push ecx
// 0078aa5d  56                   push esi
// 0078aa5e  e84dddffff           call 0x7887b0
// 0078aa63  83c408               add esp, 8
// 0078aa66  5f                   pop edi
// 0078aa67  5e                   pop esi
// 0078aa68  5d                   pop ebp
// 0078aa69  5b                   pop ebx
// 0078aa6a  c3                   ret 
// library lua-5.1.3/lauxlib.c (function _luaL_openlib)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lauxlib.c
