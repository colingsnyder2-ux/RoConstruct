// roc 2012-06 005bfa20  unit: RakNet::RakPeer  size: 636 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bfa20
//
// 005bfa20  6aff                 push -1
// 005bfa22  68662bab00           push 0xab2b66
// 005bfa27  64a100000000         mov eax, dword ptr fs:[0]
// 005bfa2d  50                   push eax
// 005bfa2e  64892500000000       mov dword ptr fs:[0], esp
// 005bfa35  81ec50020000         sub esp, 0x250
// 005bfa3b  8b842468020000       mov eax, dword ptr [esp + 0x268]
// 005bfa42  55                   push ebp
// 005bfa43  56                   push esi
// 005bfa44  8bb42474020000       mov esi, dword ptr [esp + 0x274]
// 005bfa4b  57                   push edi
// 005bfa4c  6a00                 push 0
// 005bfa4e  56                   push esi
// 005bfa4f  8bf9                 mov edi, ecx
// 005bfa51  50                   push eax
// 005bfa52  8d4c2440             lea ecx, [esp + 0x40]
// 005bfa56  e8d57bfaff           call 0x567630
// 005bfa5b  6a01                 push 1
// 005bfa5d  8d4c2438             lea ecx, [esp + 0x38]
// 005bfa61  c784246802000000000000 mov dword ptr [esp + 0x268], 0
// 005bfa6c  e85f80faff           call 0x567ad0
// 005bfa71  8d4c2424             lea ecx, [esp + 0x24]
// 005bfa75  e86622faff           call 0x561ce0
// 005bfa7a  8d4c2424             lea ecx, [esp + 0x24]
// 005bfa7e  51                   push ecx
// 005bfa7f  8d4c2438             lea ecx, [esp + 0x38]
// 005bfa83  e8f8c5faff           call 0x56c080
// 005bfa88  8d542410             lea edx, [esp + 0x10]
// 005bfa8c  52                   push edx
// 005bfa8d  8d4c2438             lea ecx, [esp + 0x38]
// 005bfa91  e8eac5faff           call 0x56c080
// 005bfa96  6a01                 push 1
// 005bfa98  6a08                 push 8
// 005bfa9a  8d442417             lea eax, [esp + 0x17]
// 005bfa9e  50                   push eax
// 005bfa9f  8d4c2440             lea ecx, [esp + 0x40]
// 005bfaa3  e8d87cfaff           call 0x567780
// 005bfaa8  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 005bfaac  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 005bfab0  83c007               add eax, 7
// 005bfab3  c1e803               shr eax, 3
// 005bfab6  2bf0                 sub esi, eax
// 005bfab8  8d1408               lea edx, [eax + ecx]
// 005bfabb  0fb68728020000       movzx eax, byte ptr [edi + 0x228]
// 005bfac2  3bc6                 cmp eax, esi
// 005bfac4  756d                 jne 0x5bfb33
// 005bfac6  8d8f28010000         lea ecx, [edi + 0x128]
// 005bfacc  8bf2                 mov esi, edx
// 005bface  83f804               cmp eax, 4
// 005bfad1  7214                 jb 0x5bfae7
// 005bfad3  8b16                 mov edx, dword ptr [esi]
// 005bfad5  3b11                 cmp edx, dword ptr [ecx]
// 005bfad7  755a                 jne 0x5bfb33
// 005bfad9  83e804               sub eax, 4
// 005bfadc  83c104               add ecx, 4
// 005bfadf  83c604               add esi, 4
// 005bfae2  83f804               cmp eax, 4
// 005bfae5  73ec                 jae 0x5bfad3
// 005bfae7  85c0                 test eax, eax
// 005bfae9  7420                 je 0x5bfb0b
// 005bfaeb  8a11                 mov dl, byte ptr [ecx]
// 005bfaed  3a16                 cmp dl, byte ptr [esi]
// 005bfaef  7542                 jne 0x5bfb33
// 005bfaf1  83f801               cmp eax, 1
// 005bfaf4  7615                 jbe 0x5bfb0b
// 005bfaf6  8a5101               mov dl, byte ptr [ecx + 1]
// 005bfaf9  3a5601               cmp dl, byte ptr [esi + 1]
// 005bfafc  7535                 jne 0x5bfb33
// 005bfafe  83f802               cmp eax, 2
// 005bfb01  7608                 jbe 0x5bfb0b
// 005bfb03  8a4102               mov al, byte ptr [ecx + 2]
// 005bfb06  3a4602               cmp al, byte ptr [esi + 2]
// 005bfb09  7528                 jne 0x5bfb33
// 005bfb0b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005bfb0f  8b542410             mov edx, dword ptr [esp + 0x10]
// 005bfb13  8b84246c020000       mov eax, dword ptr [esp + 0x26c]
// 005bfb1a  51                   push ecx
// 005bfb1b  52                   push edx
// 005bfb1c  50                   push eax
// 005bfb1d  8bcf                 mov ecx, edi
// 005bfb1f  c7800012000005000000 mov dword ptr [eax + 0x1200], 5
// 005bfb29  e832edffff           call 0x5be860
// 005bfb2e  e93b010000           jmp 0x5bfc6e
// 005bfb33  8d8c2448010000       lea ecx, [esp + 0x148]
// 005bfb3a  e8617afaff           call 0x5675a0
// 005bfb3f  6a01                 push 1
// 005bfb41  6a08                 push 8
// 005bfb43  8d442416             lea eax, [esp + 0x16]
// 005bfb47  50                   push eax
// 005bfb48  8d8c2454010000       lea ecx, [esp + 0x154]
// 005bfb4f  c684247002000001     mov byte ptr [esp + 0x270], 1
// 005bfb57  c644241a18           mov byte ptr [esp + 0x1a], 0x18
// 005bfb5c  e82f82faff           call 0x567d90
// 005bfb61  8b0d4c69e200         mov ecx, dword ptr [0xe2694c]
// 005bfb67  8b17                 mov edx, dword ptr [edi]
// 005bfb69  8b92c8000000         mov edx, dword ptr [edx + 0xc8]
// 005bfb6f  83ec14               sub esp, 0x14
// 005bfb72  8bc4                 mov eax, esp
// 005bfb74  8908                 mov dword ptr [eax], ecx
// 005bfb76  8b0d5069e200         mov ecx, dword ptr [0xe26950]
// 005bfb7c  894804               mov dword ptr [eax + 4], ecx
// 005bfb7f  8b0d5469e200         mov ecx, dword ptr [0xe26954]
// 005bfb85  894808               mov dword ptr [eax + 8], ecx
// 005bfb88  8b0d5869e200         mov ecx, dword ptr [0xe26958]
// 005bfb8e  89480c               mov dword ptr [eax + 0xc], ecx
// 005bfb91  8b0d5c69e200         mov ecx, dword ptr [0xe2695c]
// 005bfb97  894810               mov dword ptr [eax + 0x10], ecx
// 005bfb9a  8bcf                 mov ecx, edi
// 005bfb9c  ffd2                 call edx
// 005bfb9e  8bf0                 mov esi, eax
// 005bfba0  e82b80faff           call 0x567bd0
// 005bfba5  84c0                 test al, al
// 005bfba7  751b                 jne 0x5bfbc4
// 005bfba9  6a08                 push 8
// 005bfbab  8d442420             lea eax, [esp + 0x20]
// 005bfbaf  50                   push eax
// 005bfbb0  56                   push esi
// 005bfbb1  e88a7ffaff           call 0x567b40
// 005bfbb6  83c40c               add esp, 0xc
// 005bfbb9  6a01                 push 1
// 005bfbbb  6a40                 push 0x40
// 005bfbbd  8d4c2424             lea ecx, [esp + 0x24]
// 005bfbc1  51                   push ecx
// 005bfbc2  eb05                 jmp 0x5bfbc9
// 005bfbc4  6a01                 push 1
// 005bfbc6  6a40                 push 0x40
// 005bfbc8  56                   push esi
// 005bfbc9  8d8c2454010000       lea ecx, [esp + 0x154]
// 005bfbd0  e8bb81faff           call 0x567d90
// 005bfbd5  6a00                 push 0
// 005bfbd7  e8e48dffff           call 0x5b89c0
// 005bfbdc  52                   push edx
// 005bfbdd  50                   push eax
// 005bfbde  6a00                 push 0
// 005bfbe0  6a00                 push 0
// 005bfbe2  83ec28               sub esp, 0x28
// 005bfbe5  8bf4                 mov esi, esp
// 005bfbe7  8bce                 mov ecx, esi
// 005bfbe9  89642454             mov dword ptr [esp + 0x54], esp
// 005bfbed  e8ee20faff           call 0x561ce0
// 005bfbf2  8d6e10               lea ebp, [esi + 0x10]
// 005bfbf5  8bcd                 mov ecx, ebp
// 005bfbf7  e8341efaff           call 0x561a30
// 005bfbfc  8b15f815d900         mov edx, dword ptr [0xd915f8]
// 005bfc02  8916                 mov dword ptr [esi], edx
// 005bfc04  a1fc15d900           mov eax, dword ptr [0xd915fc]
// 005bfc09  8b9424ac020000       mov edx, dword ptr [esp + 0x2ac]
// 005bfc10  894604               mov dword ptr [esi + 4], eax
// 005bfc13  668b0d0016d900       mov cx, word ptr [0xd91600]
// 005bfc1a  66894e08             mov word ptr [esi + 8], cx
// 005bfc1e  52                   push edx
// 005bfc1f  8bcd                 mov ecx, ebp
// 005bfc21  e8ea1bfaff           call 0x561810
// 005bfc26  8b842484010000       mov eax, dword ptr [esp + 0x184]
// 005bfc2d  6a00                 push 0
// 005bfc2f  6a02                 push 2
// 005bfc31  83c007               add eax, 7
// 005bfc34  c1e803               shr eax, 3
// 005bfc37  6a00                 push 0
// 005bfc39  50                   push eax
// 005bfc3a  8b8424a0010000       mov eax, dword ptr [esp + 0x1a0]
// 005bfc41  50                   push eax
// 005bfc42  8bcf                 mov ecx, edi
// 005bfc44  e877c4ffff           call 0x5bc0c0
// 005bfc49  8b8c246c020000       mov ecx, dword ptr [esp + 0x26c]
// 005bfc50  c7810012000002000000 mov dword ptr [ecx + 0x1200], 2
// 005bfc5a  8d8c2448010000       lea ecx, [esp + 0x148]
// 005bfc61  c684246402000000     mov byte ptr [esp + 0x264], 0
// 005bfc69  e8427afaff           call 0x5676b0
// 005bfc6e  8d4c2434             lea ecx, [esp + 0x34]
// 005bfc72  c7842464020000ffffffff mov dword ptr [esp + 0x264], 0xffffffff
// 005bfc7d  e82e7afaff           call 0x5676b0
// 005bfc82  8b8c245c020000       mov ecx, dword ptr [esp + 0x25c]
// 005bfc89  5f                   pop edi
// 005bfc8a  5e                   pop esi
// 005bfc8b  64890d00000000       mov dword ptr fs:[0], ecx
// 005bfc92  5d                   pop ebp
// 005bfc93  81c45c020000         add esp, 0x25c
// 005bfc99  c21000               ret 0x10
// copied from an identical function in another client (function ?ParseConnectionRequestPacket@RakPeer@RakNet@@IAEXPAURemoteSystemStruct@12@ABUSystemAddress@2@PBDH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp