// roc 2012-06 005bbf00  unit: RakNet::RakPeer  size: 249 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bbf00
//
// 005bbf00  56                   push esi
// 005bbf01  8bf1                 mov esi, ecx
// 005bbf03  684c69e200           push 0xe2694c
// 005bbf08  8d4c240c             lea ecx, [esp + 0xc]
// 005bbf0c  e88f59faff           call 0x5618a0
// 005bbf11  84c0                 test al, al
// 005bbf13  7406                 je 0x5bbf1b
// 005bbf15  33c0                 xor eax, eax
// 005bbf17  5e                   pop esi
// 005bbf18  c21c00               ret 0x1c
// 005bbf1b  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 005bbf20  53                   push ebx
// 005bbf21  55                   push ebp
// 005bbf22  57                   push edi
// 005bbf23  7447                 je 0x5bbf6c
// 005bbf25  8d442414             lea eax, [esp + 0x14]
// 005bbf29  50                   push eax
// 005bbf2a  8bce                 mov ecx, esi
// 005bbf2c  e86ff4ffff           call 0x5bb3a0
// 005bbf31  83f8ff               cmp eax, -1
// 005bbf34  0f84b6000000         je 0x5bbff0
// 005bbf3a  807c242c00           cmp byte ptr [esp + 0x2c], 0
// 005bbf3f  7418                 je 0x5bbf59
// 005bbf41  8b962c020000         mov edx, dword ptr [esi + 0x22c]
// 005bbf47  8bc8                 mov ecx, eax
// 005bbf49  69c908120000         imul ecx, ecx, 0x1208
// 005bbf4f  803c1101             cmp byte ptr [ecx + edx], 1
// 005bbf53  0f8597000000         jne 0x5bbff0
// 005bbf59  69c008120000         imul eax, eax, 0x1208
// 005bbf5f  03862c020000         add eax, dword ptr [esi + 0x22c]
// 005bbf65  5f                   pop edi
// 005bbf66  5d                   pop ebp
// 005bbf67  5b                   pop ebx
// 005bbf68  5e                   pop esi
// 005bbf69  c21c00               ret 0x1c
// 005bbf6c  33c0                 xor eax, eax
// 005bbf6e  83cdff               or ebp, 0xffffffff
// 005bbf71  33ff                 xor edi, edi
// 005bbf73  663b460e             cmp ax, word ptr [esi + 0xe]
// 005bbf77  7377                 jae 0x5bbff0
// 005bbf79  33db                 xor ebx, ebx
// 005bbf7b  eb03                 jmp 0x5bbf80
// 005bbf7d  8d4900               lea ecx, [ecx]
// 005bbf80  8b962c020000         mov edx, dword ptr [esi + 0x22c]
// 005bbf86  8d4c2414             lea ecx, [esp + 0x14]
// 005bbf8a  51                   push ecx
// 005bbf8b  8d4c1a04             lea ecx, [edx + ebx + 4]
// 005bbf8f  e80c59faff           call 0x5618a0
// 005bbf94  84c0                 test al, al
// 005bbf96  7413                 je 0x5bbfab
// 005bbf98  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 005bbf9e  803c0300             cmp byte ptr [ebx + eax], 0
// 005bbfa2  7537                 jne 0x5bbfdb
// 005bbfa4  83fdff               cmp ebp, -1
// 005bbfa7  7502                 jne 0x5bbfab
// 005bbfa9  8bef                 mov ebp, edi
// 005bbfab  0fb74e0e             movzx ecx, word ptr [esi + 0xe]
// 005bbfaf  47                   inc edi
// 005bbfb0  81c308120000         add ebx, 0x1208
// 005bbfb6  3bf9                 cmp edi, ecx
// 005bbfb8  72c6                 jb 0x5bbf80
// 005bbfba  83fdff               cmp ebp, -1
// 005bbfbd  7431                 je 0x5bbff0
// 005bbfbf  807c242c00           cmp byte ptr [esp + 0x2c], 0
// 005bbfc4  752a                 jne 0x5bbff0
// 005bbfc6  8bc5                 mov eax, ebp
// 005bbfc8  69c008120000         imul eax, eax, 0x1208
// 005bbfce  03862c020000         add eax, dword ptr [esi + 0x22c]
// 005bbfd4  5f                   pop edi
// 005bbfd5  5d                   pop ebp
// 005bbfd6  5b                   pop ebx
// 005bbfd7  5e                   pop esi
// 005bbfd8  c21c00               ret 0x1c
// 005bbfdb  8bc7                 mov eax, edi
// 005bbfdd  69c008120000         imul eax, eax, 0x1208
// 005bbfe3  03862c020000         add eax, dword ptr [esi + 0x22c]
// 005bbfe9  5f                   pop edi
// 005bbfea  5d                   pop ebp
// 005bbfeb  5b                   pop ebx
// 005bbfec  5e                   pop esi
// 005bbfed  c21c00               ret 0x1c
// 005bbff0  5f                   pop edi
// 005bbff1  5d                   pop ebp
// 005bbff2  5b                   pop ebx
// 005bbff3  33c0                 xor eax, eax
// 005bbff5  5e                   pop esi
// 005bbff6  c21c00               ret 0x1c
// copied from an identical function in another client (function ?GetRemoteSystemFromSystemAddress@RakPeer@RakNet@@IBEPAURemoteSystemStruct@12@USystemAddress@2@_N1@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp