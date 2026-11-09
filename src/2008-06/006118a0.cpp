// from server: 100% by auto
// roc 2008-06 006118a0  unit: seg_00610000  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006118a0
//
// 006118a0  53                   push ebx
// 006118a1  55                   push ebp
// 006118a2  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 006118a6  56                   push esi
// 006118a7  8b742410             mov esi, dword ptr [esp + 0x10]
// 006118ab  57                   push edi
// 006118ac  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006118b0  85ed                 test ebp, ebp
// 006118b2  0f8497000000         je 0x61194f
// 006118b8  33db                 xor ebx, ebx
// 006118ba  8bc7                 mov eax, edi
// 006118bc  391f                 cmp dword ptr [edi], ebx
// 006118be  7409                 je 0x6118c9
// 006118c0  83c008               add eax, 8
// 006118c3  43                   inc ebx
// 006118c4  833800               cmp dword ptr [eax], 0
// 006118c7  75f7                 jne 0x6118c0
// 006118c9  53                   push ebx
// 006118ca  6864388400           push 0x843864
// 006118cf  68f0d8ffff           push 0xffffd8f0
// 006118d4  56                   push esi
// 006118d5  e806f5ffff           call 0x610de0
// 006118da  55                   push ebp
// 006118db  6aff                 push -1
// 006118dd  56                   push esi
// 006118de  e8ad0b0000           call 0x612490
// 006118e3  6aff                 push -1
// 006118e5  56                   push esi
// 006118e6  e815050000           call 0x611e00
// 006118eb  83c424               add esp, 0x24
// 006118ee  83f805               cmp eax, 5
// 006118f1  743f                 je 0x611932
// 006118f3  6afe                 push -2
// 006118f5  56                   push esi
// 006118f6  e825030000           call 0x611c20
// 006118fb  53                   push ebx
// 006118fc  55                   push ebp
// 006118fd  68eed8ffff           push 0xffffd8ee
// 00611902  56                   push esi
// 00611903  e8d8f4ffff           call 0x610de0
// 00611908  83c418               add esp, 0x18
// 0061190b  85c0                 test eax, eax
// 0061190d  740f                 je 0x61191e
// 0061190f  55                   push ebp
// 00611910  6844388400           push 0x843844
// 00611915  56                   push esi
// 00611916  e845f3ffff           call 0x610c60
// 0061191b  83c40c               add esp, 0xc
// 0061191e  6aff                 push -1
// 00611920  56                   push esi
// 00611921  e8aa040000           call 0x611dd0
// 00611926  55                   push ebp
// 00611927  6afd                 push -3
// 00611929  56                   push esi
// 0061192a  e8810d0000           call 0x6126b0
// 0061192f  83c414               add esp, 0x14
// 00611932  6afe                 push -2
// 00611934  56                   push esi
// 00611935  e836030000           call 0x611c70
// 0061193a  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0061193e  83c8ff               or eax, 0xffffffff
// 00611941  2bc5                 sub eax, ebp
// 00611943  50                   push eax
// 00611944  56                   push esi
// 00611945  e876030000           call 0x611cc0
// 0061194a  83c410               add esp, 0x10
// 0061194d  eb04                 jmp 0x611953
// 0061194f  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00611953  833f00               cmp dword ptr [edi], 0
// 00611956  744f                 je 0x6119a7
// 00611958  b8feffffff           mov eax, 0xfffffffe
// 0061195d  2bc5                 sub eax, ebp
// 0061195f  89442418             mov dword ptr [esp + 0x18], eax
// 00611963  85ed                 test ebp, ebp
// 00611965  7e1c                 jle 0x611983
// 00611967  8bdd                 mov ebx, ebp
// 00611969  f7db                 neg ebx
// 0061196b  eb03                 jmp 0x611970
// 0061196d  8d4900               lea ecx, [ecx]
// 00611970  53                   push ebx
// 00611971  56                   push esi
// 00611972  e859040000           call 0x611dd0
// 00611977  83c408               add esp, 8
// 0061197a  83ed01               sub ebp, 1
// 0061197d  75f1                 jne 0x611970
// 0061197f  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00611983  8b4f04               mov ecx, dword ptr [edi + 4]
// 00611986  55                   push ebp
// 00611987  51                   push ecx
// 00611988  56                   push esi
// 00611989  e8c2090000           call 0x612350
// 0061198e  8b17                 mov edx, dword ptr [edi]
// 00611990  8b442424             mov eax, dword ptr [esp + 0x24]
// 00611994  52                   push edx
// 00611995  50                   push eax
// 00611996  56                   push esi
// 00611997  e8140d0000           call 0x6126b0
// 0061199c  83c708               add edi, 8
// 0061199f  83c418               add esp, 0x18
// 006119a2  833f00               cmp dword ptr [edi], 0
// 006119a5  75bc                 jne 0x611963
// 006119a7  83c9ff               or ecx, 0xffffffff
// 006119aa  2bcd                 sub ecx, ebp
// 006119ac  51                   push ecx
// 006119ad  56                   push esi
// 006119ae  e86d020000           call 0x611c20
// 006119b3  83c408               add esp, 8
// 006119b6  5f                   pop edi
// 006119b7  5e                   pop esi
// 006119b8  5d                   pop ebp
// 006119b9  5b                   pop ebx
// 006119ba  c3                   ret 
// library lua-5.1.2/lauxlib.c (function _luaL_openlib)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lauxlib.c
