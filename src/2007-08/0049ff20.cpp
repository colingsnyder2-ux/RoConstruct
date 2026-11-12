// from server: 100% by auto
// roc 2007-08 0049ff20  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 433 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049ff20
//
// 0049ff20  53                   push ebx
// 0049ff21  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0049ff25  c1fb03               sar ebx, 3
// 0049ff28  83eb01               sub ebx, 1
// 0049ff2b  807c241000           cmp byte ptr [esp + 0x10], 0
// 0049ff30  55                   push ebp
// 0049ff31  0f95c0               setne al
// 0049ff34  2c01                 sub al, 1
// 0049ff36  56                   push esi
// 0049ff37  57                   push edi
// 0049ff38  8bf1                 mov esi, ecx
// 0049ff3a  25ff000000           and eax, 0xff
// 0049ff3f  85db                 test ebx, ebx
// 0049ff41  88442418             mov byte ptr [esp + 0x18], al
// 0049ff45  7f3d                 jg 0x49ff84
// 0049ff47  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 0049ff4c  0f8401010000         je 0x4a0053
// 0049ff52  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0049ff56  03d9                 add ebx, ecx
// 0049ff58  f603f0               test byte ptr [ebx], 0xf0
// 0049ff5b  0f8405010000         je 0x4a0066
// 0049ff61  6a00                 push 0
// 0049ff63  8bce                 mov ecx, esi
// 0049ff65  e8c6feffff           call 0x49fe30
// 0049ff6a  6a01                 push 1
// 0049ff6c  6a08                 push 8
// 0049ff6e  53                   push ebx
// 0049ff6f  8bce                 mov ecx, esi
// 0049ff71  e81afeffff           call 0x49fd90
// 0049ff76  5f                   pop edi
// 0049ff77  5e                   pop esi
// 0049ff78  5d                   pop ebp
// 0049ff79  5b                   pop ebx
// 0049ff7a  c20c00               ret 0xc
// 0049ff7d  8d4900               lea ecx, [ecx]
// 0049ff80  8a442418             mov al, byte ptr [esp + 0x18]
// 0049ff84  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0049ff88  38043b               cmp byte ptr [ebx + edi], al
// 0049ff8b  0f85a0000000         jne 0x4a0031
// 0049ff91  8b06                 mov eax, dword ptr [esi]
// 0049ff93  8d7801               lea edi, [eax + 1]
// 0049ff96  85ff                 test edi, edi
// 0049ff98  7e5c                 jle 0x49fff6
// 0049ff9a  8b4e04               mov ecx, dword ptr [esi + 4]
// 0049ff9d  83e901               sub ecx, 1
// 0049ffa0  8d57ff               lea edx, [edi - 1]
// 0049ffa3  83e1f8               and ecx, 0xfffffff8
// 0049ffa6  83e2f8               and edx, 0xfffffff8
// 0049ffa9  3bca                 cmp ecx, edx
// 0049ffab  7d49                 jge 0x49fff6
// 0049ffad  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0049ffb0  8d7c0002             lea edi, [eax + eax + 2]
// 0049ffb4  8d4707               lea eax, [edi + 7]
// 0049ffb7  8d6e11               lea ebp, [esi + 0x11]
// 0049ffba  c1f803               sar eax, 3
// 0049ffbd  3bcd                 cmp ecx, ebp
// 0049ffbf  7527                 jne 0x49ffe8
// 0049ffc1  3d00010000           cmp eax, 0x100
// 0049ffc6  7e2e                 jle 0x49fff6
// 0049ffc8  50                   push eax
// 0049ffc9  ff15d0e67700         call dword ptr [0x77e6d0]
// 0049ffcf  8b4e04               mov ecx, dword ptr [esi + 4]
// 0049ffd2  83c107               add ecx, 7
// 0049ffd5  c1f903               sar ecx, 3
// 0049ffd8  51                   push ecx
// 0049ffd9  55                   push ebp
// 0049ffda  50                   push eax
// 0049ffdb  89460c               mov dword ptr [esi + 0xc], eax
// 0049ffde  e8690d1900           call 0x630d4c
// 0049ffe3  83c410               add esp, 0x10
// 0049ffe6  eb0e                 jmp 0x49fff6
// 0049ffe8  50                   push eax
// 0049ffe9  51                   push ecx
// 0049ffea  ff1520e77700         call dword ptr [0x77e720]
// 0049fff0  83c408               add esp, 8
// 0049fff3  89460c               mov dword ptr [esi + 0xc], eax
// 0049fff6  3b7e04               cmp edi, dword ptr [esi + 4]
// 0049fff9  7e03                 jle 0x49fffe
// 0049fffb  897e04               mov dword ptr [esi + 4], edi
// 0049fffe  8b06                 mov eax, dword ptr [esi]
// 004a0000  8b560c               mov edx, dword ptr [esi + 0xc]
// 004a0003  8bc8                 mov ecx, eax
// 004a0005  c1f803               sar eax, 3
// 004a0008  83e107               and ecx, 7
// 004a000b  7506                 jne 0x4a0013
// 004a000d  c6041080             mov byte ptr [eax + edx], 0x80
// 004a0011  eb0b                 jmp 0x4a001e
// 004a0013  03c2                 add eax, edx
// 004a0015  ba80000000           mov edx, 0x80
// 004a001a  d3fa                 sar edx, cl
// 004a001c  0810                 or byte ptr [eax], dl
// 004a001e  830601               add dword ptr [esi], 1
// 004a0021  83eb01               sub ebx, 1
// 004a0024  85db                 test ebx, ebx
// 004a0026  0f8f54ffffff         jg 0x49ff80
// 004a002c  e916ffffff           jmp 0x49ff47
// 004a0031  6a00                 push 0
// 004a0033  8bce                 mov ecx, esi
// 004a0035  e8f6fdffff           call 0x49fe30
// 004a003a  6a01                 push 1
// 004a003c  8d04dd08000000       lea eax, [ebx*8 + 8]
// 004a0043  50                   push eax
// 004a0044  57                   push edi
// 004a0045  8bce                 mov ecx, esi
// 004a0047  e844fdffff           call 0x49fd90
// 004a004c  5f                   pop edi
// 004a004d  5e                   pop esi
// 004a004e  5d                   pop ebp
// 004a004f  5b                   pop ebx
// 004a0050  c20c00               ret 0xc
// 004a0053  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a0057  8a0413               mov al, byte ptr [ebx + edx]
// 004a005a  03da                 add ebx, edx
// 004a005c  24f0                 and al, 0xf0
// 004a005e  3cf0                 cmp al, 0xf0
// 004a0060  0f85fbfeffff         jne 0x49ff61
// 004a0066  6a01                 push 1
// 004a0068  8bce                 mov ecx, esi
// 004a006a  e8c1fdffff           call 0x49fe30
// 004a006f  6a04                 push 4
// 004a0071  8bce                 mov ecx, esi
// 004a0073  e8c8faffff           call 0x49fb40
// 004a0078  8b0e                 mov ecx, dword ptr [esi]
// 004a007a  8a13                 mov dl, byte ptr [ebx]
// 004a007c  8bc1                 mov eax, ecx
// 004a007e  83e007               and eax, 7
// 004a0081  c0e204               shl dl, 4
// 004a0084  c1f903               sar ecx, 3
// 004a0087  85c0                 test eax, eax
// 004a0089  7510                 jne 0x4a009b
// 004a008b  8b460c               mov eax, dword ptr [esi + 0xc]
// 004a008e  5f                   pop edi
// 004a008f  881401               mov byte ptr [ecx + eax], dl
// 004a0092  830604               add dword ptr [esi], 4
// 004a0095  5e                   pop esi
// 004a0096  5d                   pop ebp
// 004a0097  5b                   pop ebx
// 004a0098  c20c00               ret 0xc
// 004a009b  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004a009e  03f9                 add edi, ecx
// 004a00a0  8ac8                 mov cl, al
// 004a00a2  8ada                 mov bl, dl
// 004a00a4  d2eb                 shr bl, cl
// 004a00a6  b908000000           mov ecx, 8
// 004a00ab  2bc8                 sub ecx, eax
// 004a00ad  081f                 or byte ptr [edi], bl
// 004a00af  83f908               cmp ecx, 8
// 004a00b2  7d13                 jge 0x4a00c7
// 004a00b4  83f904               cmp ecx, 4
// 004a00b7  7d0e                 jge 0x4a00c7
// 004a00b9  8b460c               mov eax, dword ptr [esi + 0xc]
// 004a00bc  d2e2                 shl dl, cl
// 004a00be  8b0e                 mov ecx, dword ptr [esi]
// 004a00c0  c1f903               sar ecx, 3
// 004a00c3  88540101             mov byte ptr [ecx + eax + 1], dl
// 004a00c7  830604               add dword ptr [esi], 4
// 004a00ca  5f                   pop edi
// 004a00cb  5e                   pop esi
// 004a00cc  5d                   pop ebp
// 004a00cd  5b                   pop ebx
// 004a00ce  c20c00               ret 0xc
// library openrbx-raknet/BitStream.cpp (function ?WriteCompressed@BitStream@RakNet@@AAEXPBEH_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet BitStream.cpp
