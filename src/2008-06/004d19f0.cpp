// from server: 100% by auto
// roc 2008-06 004d19f0  unit: RBX::Network::PhysicsSender  size: 1570 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d19f0
//
// 004d19f0  83ec24               sub esp, 0x24
// 004d19f3  53                   push ebx
// 004d19f4  55                   push ebp
// 004d19f5  56                   push esi
// 004d19f6  57                   push edi
// 004d19f7  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 004d19fb  8bf1                 mov esi, ecx
// 004d19fd  33ed                 xor ebp, ebp
// 004d19ff  8d8e28050000         lea ecx, [esi + 0x528]
// 004d1a05  896c2424             mov dword ptr [esp + 0x24], ebp
// 004d1a09  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004d1a0d  8d5fe4               lea ebx, [edi - 0x1c]
// 004d1a10  e87b3f0000           call 0x4d5990
// 004d1a15  84c0                 test al, al
// 004d1a17  7403                 je 0x4d1a1c
// 004d1a19  83eb10               sub ebx, 0x10
// 004d1a1c  8b442440             mov eax, dword ptr [esp + 0x40]
// 004d1a20  03db                 add ebx, ebx
// 004d1a22  03db                 add ebx, ebx
// 004d1a24  03db                 add ebx, ebx
// 004d1a26  c60000               mov byte ptr [eax], 0
// 004d1a29  895c2420             mov dword ptr [esp + 0x20], ebx
// 004d1a2d  396e20               cmp dword ptr [esi + 0x20], ebp
// 004d1a30  764d                 jbe 0x4d1a7f
// 004d1a32  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 004d1a36  8bcd                 mov ecx, ebp
// 004d1a38  e8233bfdff           call 0x4a5560
// 004d1a3d  8b8e00050000         mov ecx, dword ptr [esi + 0x500]
// 004d1a43  6a01                 push 1
// 004d1a45  6a20                 push 0x20
// 004d1a47  8d542444             lea edx, [esp + 0x44]
// 004d1a4b  894c2444             mov dword ptr [esp + 0x44], ecx
// 004d1a4f  52                   push edx
// 004d1a50  8bcd                 mov ecx, ebp
// 004d1a52  e8a93bfdff           call 0x4a5600
// 004d1a57  6a01                 push 1
// 004d1a59  8d04fd1fffffff       lea eax, [edi*8 - 0xe1]
// 004d1a60  50                   push eax
// 004d1a61  55                   push ebp
// 004d1a62  8d4e1c               lea ecx, [esi + 0x1c]
// 004d1a65  c744242801000000     mov dword ptr [esp + 0x28], 1
// 004d1a6d  c644241f01           mov byte ptr [esp + 0x1f], 1
// 004d1a72  e889efffff           call 0x4d0a00
// 004d1a77  01862c040000         add dword ptr [esi + 0x42c], eax
// 004d1a7d  eb0e                 jmp 0x4d1a8d
// 004d1a7f  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004d1a83  c644241300           mov byte ptr [esp + 0x13], 0
// 004d1a88  e8b33afdff           call 0x4a5540
// 004d1a8d  c644243c00           mov byte ptr [esp + 0x3c], 0
// 004d1a92  8d7e54               lea edi, [esi + 0x54]
// 004d1a95  8b5704               mov edx, dword ptr [edi + 4]
// 004d1a98  8b4f08               mov ecx, dword ptr [edi + 8]
// 004d1a9b  3bd1                 cmp edx, ecx
// 004d1a9d  7706                 ja 0x4d1aa5
// 004d1a9f  2bca                 sub ecx, edx
// 004d1aa1  8bc1                 mov eax, ecx
// 004d1aa3  eb07                 jmp 0x4d1aac
// 004d1aa5  8b470c               mov eax, dword ptr [edi + 0xc]
// 004d1aa8  2bc2                 sub eax, edx
// 004d1aaa  03c1                 add eax, ecx
// 004d1aac  85c0                 test eax, eax
// 004d1aae  0f8613020000         jbe 0x4d1cc7
// 004d1ab4  8bca                 mov ecx, edx
// 004d1ab6  8b17                 mov edx, dword ptr [edi]
// 004d1ab8  8b0c8a               mov ecx, dword ptr [edx + ecx*4]
// 004d1abb  894c2414             mov dword ptr [esp + 0x14], ecx
// 004d1abf  8b4130               mov eax, dword ptr [ecx + 0x30]
// 004d1ac2  0b4134               or eax, dword ptr [ecx + 0x34]
// 004d1ac5  7530                 jne 0x4d1af7
// 004d1ac7  ff4704               inc dword ptr [edi + 4]
// 004d1aca  8b4704               mov eax, dword ptr [edi + 4]
// 004d1acd  3b470c               cmp eax, dword ptr [edi + 0xc]
// 004d1ad0  7507                 jne 0x4d1ad9
// 004d1ad2  c7470400000000       mov dword ptr [edi + 4], 0
// 004d1ad9  8b493c               mov ecx, dword ptr [ecx + 0x3c]
// 004d1adc  51                   push ecx
// 004d1add  e898eb1c00           call 0x6a067a
// 004d1ae2  8b542418             mov edx, dword ptr [esp + 0x18]
// 004d1ae6  83c404               add esp, 4
// 004d1ae9  52                   push edx
// 004d1aea  8d8eb0070000         lea ecx, [esi + 0x7b0]
// 004d1af0  e8abdeffff           call 0x4cf9a0
// 004d1af5  eb9e                 jmp 0x4d1a95
// 004d1af7  8b4704               mov eax, dword ptr [edi + 4]
// 004d1afa  8bca                 mov ecx, edx
// 004d1afc  8b0481               mov eax, dword ptr [ecx + eax*4]
// 004d1aff  8b5034               mov edx, dword ptr [eax + 0x34]
// 004d1b02  3b542448             cmp edx, dword ptr [esp + 0x48]
// 004d1b06  0f8fbb010000         jg 0x4d1cc7
// 004d1b0c  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 004d1b10  7c0b                 jl 0x4d1b1d
// 004d1b12  8b4030               mov eax, dword ptr [eax + 0x30]
// 004d1b15  3bc5                 cmp eax, ebp
// 004d1b17  0f83aa010000         jae 0x4d1cc7
// 004d1b1d  ff4704               inc dword ptr [edi + 4]
// 004d1b20  8b4704               mov eax, dword ptr [edi + 4]
// 004d1b23  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004d1b26  3bc1                 cmp eax, ecx
// 004d1b28  7507                 jne 0x4d1b31
// 004d1b2a  c7470400000000       mov dword ptr [edi + 4], 0
// 004d1b31  8b4704               mov eax, dword ptr [edi + 4]
// 004d1b34  85c0                 test eax, eax
// 004d1b36  7508                 jne 0x4d1b40
// 004d1b38  8b17                 mov edx, dword ptr [edi]
// 004d1b3a  8b448afc             mov eax, dword ptr [edx + ecx*4 - 4]
// 004d1b3e  eb06                 jmp 0x4d1b46
// 004d1b40  8b0f                 mov ecx, dword ptr [edi]
// 004d1b42  8b4481fc             mov eax, dword ptr [ecx + eax*4 - 4]
// 004d1b46  89442414             mov dword ptr [esp + 0x14], eax
// 004d1b4a  8b5010               mov edx, dword ptr [eax + 0x10]
// 004d1b4d  b923000000           mov ecx, 0x23
// 004d1b52  83fa01               cmp edx, 1
// 004d1b55  740a                 je 0x4d1b61
// 004d1b57  83fa04               cmp edx, 4
// 004d1b5a  7405                 je 0x4d1b61
// 004d1b5c  83fa03               cmp edx, 3
// 004d1b5f  7505                 jne 0x4d1b66
// 004d1b61  b948000000           mov ecx, 0x48
// 004d1b66  41                   inc ecx
// 004d1b67  83782400             cmp dword ptr [eax + 0x24], 0
// 004d1b6b  7603                 jbe 0x4d1b70
// 004d1b6d  83c150               add ecx, 0x50
// 004d1b70  8b5038               mov edx, dword ptr [eax + 0x38]
// 004d1b73  8b442438             mov eax, dword ptr [esp + 0x38]
// 004d1b77  0310                 add edx, dword ptr [eax]
// 004d1b79  8d4c0a10             lea ecx, [edx + ecx + 0x10]
// 004d1b7d  3bcb                 cmp ecx, ebx
// 004d1b7f  0f8f2f010000         jg 0x4d1cb4
// 004d1b85  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 004d1b89  33ff                 xor edi, edi
// 004d1b8b  397b04               cmp dword ptr [ebx + 4], edi
// 004d1b8e  7645                 jbe 0x4d1bd5
// 004d1b90  8b542448             mov edx, dword ptr [esp + 0x48]
// 004d1b94  57                   push edi
// 004d1b95  68e8030000           push 0x3e8
// 004d1b9a  52                   push edx
// 004d1b9b  55                   push ebp
// 004d1b9c  e88f001d00           call 0x6a1c30
// 004d1ba1  8be8                 mov ebp, eax
// 004d1ba3  89542430             mov dword ptr [esp + 0x30], edx
// 004d1ba7  8b03                 mov eax, dword ptr [ebx]
// 004d1ba9  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 004d1bac  8b442450             mov eax, dword ptr [esp + 0x50]
// 004d1bb0  8b11                 mov edx, dword ptr [ecx]
// 004d1bb2  8b5228               mov edx, dword ptr [edx + 0x28]
// 004d1bb5  6a01                 push 1
// 004d1bb7  55                   push ebp
// 004d1bb8  50                   push eax
// 004d1bb9  8b442458             mov eax, dword ptr [esp + 0x58]
// 004d1bbd  50                   push eax
// 004d1bbe  8b8684070000         mov eax, dword ptr [esi + 0x784]
// 004d1bc4  50                   push eax
// 004d1bc5  ff742428             push dword ptr [esp + 0x28]
// 004d1bc9  ffd2                 call edx
// 004d1bcb  47                   inc edi
// 004d1bcc  3b7b04               cmp edi, dword ptr [ebx + 4]
// 004d1bcf  72d6                 jb 0x4d1ba7
// 004d1bd1  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 004d1bd5  ff8634040000         inc dword ptr [esi + 0x434]
// 004d1bdb  8b442414             mov eax, dword ptr [esp + 0x14]
// 004d1bdf  8b4838               mov ecx, dword ptr [eax + 0x38]
// 004d1be2  018e38040000         add dword ptr [esi + 0x438], ecx
// 004d1be8  807c243c00           cmp byte ptr [esp + 0x3c], 0
// 004d1bed  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 004d1bf1  7534                 jne 0x4d1c27
// 004d1bf3  8bcb                 mov ecx, ebx
// 004d1bf5  c644243c01           mov byte ptr [esp + 0x3c], 1
// 004d1bfa  e86139fdff           call 0x4a5560
// 004d1bff  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 004d1c03  6a00                 push 0
// 004d1c05  68e8030000           push 0x3e8
// 004d1c0a  57                   push edi
// 004d1c0b  55                   push ebp
// 004d1c0c  e81f001d00           call 0x6a1c30
// 004d1c11  6a01                 push 1
// 004d1c13  6a20                 push 0x20
// 004d1c15  8d542430             lea edx, [esp + 0x30]
// 004d1c19  52                   push edx
// 004d1c1a  8bcb                 mov ecx, ebx
// 004d1c1c  89442434             mov dword ptr [esp + 0x34], eax
// 004d1c20  e8db39fdff           call 0x4a5600
// 004d1c25  eb04                 jmp 0x4d1c2b
// 004d1c27  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 004d1c2b  8b442414             mov eax, dword ptr [esp + 0x14]
// 004d1c2f  57                   push edi
// 004d1c30  55                   push ebp
// 004d1c31  50                   push eax
// 004d1c32  53                   push ebx
// 004d1c33  8bce                 mov ecx, esi
// 004d1c35  e8b6dbffff           call 0x4cf7f0
// 004d1c3a  01863c040000         add dword ptr [esi + 0x43c], eax
// 004d1c40  8b8e84070000         mov ecx, dword ptr [esi + 0x784]
// 004d1c46  8b542414             mov edx, dword ptr [esp + 0x14]
// 004d1c4a  894a08               mov dword ptr [edx + 8], ecx
// 004d1c4d  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 004d1c51  b801000000           mov eax, 1
// 004d1c56  0144241c             add dword ptr [esp + 0x1c], eax
// 004d1c5a  8801                 mov byte ptr [ecx], al
// 004d1c5c  018630040000         add dword ptr [esi + 0x430], eax
// 004d1c62  8b96d8040000         mov edx, dword ptr [esi + 0x4d8]
// 004d1c68  8b86dc040000         mov eax, dword ptr [esi + 0x4dc]
// 004d1c6e  6a00                 push 0
// 004d1c70  81c2a0860100         add edx, 0x186a0
// 004d1c76  6a03                 push 3
// 004d1c78  83d000               adc eax, 0
// 004d1c7b  50                   push eax
// 004d1c7c  52                   push edx
// 004d1c7d  e84efa1c00           call 0x6a16d0
// 004d1c82  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004d1c86  03c5                 add eax, ebp
// 004d1c88  894130               mov dword ptr [ecx + 0x30], eax
// 004d1c8b  8b442414             mov eax, dword ptr [esp + 0x14]
// 004d1c8f  13d7                 adc edx, edi
// 004d1c91  895034               mov dword ptr [eax + 0x34], edx
// 004d1c94  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004d1c98  8d542428             lea edx, [esp + 0x28]
// 004d1c9c  894c2428             mov dword ptr [esp + 0x28], ecx
// 004d1ca0  8d7e54               lea edi, [esi + 0x54]
// 004d1ca3  52                   push edx
// 004d1ca4  8bcf                 mov ecx, edi
// 004d1ca6  e835d1ffff           call 0x4cede0
// 004d1cab  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004d1caf  e9e1fdffff           jmp 0x4d1a95
// 004d1cb4  6a00                 push 0
// 004d1cb6  8d442418             lea eax, [esp + 0x18]
// 004d1cba  50                   push eax
// 004d1cbb  8bcf                 mov ecx, edi
// 004d1cbd  e8eed1ffff           call 0x4ceeb0
// 004d1cc2  e905030000           jmp 0x4d1fcc
// 004d1cc7  8d8e00040000         lea ecx, [esi + 0x400]
// 004d1ccd  8d7e68               lea edi, [esi + 0x68]
// 004d1cd0  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004d1cd8  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004d1cdc  897c2418             mov dword ptr [esp + 0x18], edi
// 004d1ce0  8b17                 mov edx, dword ptr [edi]
// 004d1ce2  8b4f04               mov ecx, dword ptr [edi + 4]
// 004d1ce5  3bd1                 cmp edx, ecx
// 004d1ce7  7706                 ja 0x4d1cef
// 004d1ce9  2bca                 sub ecx, edx
// 004d1ceb  8bc1                 mov eax, ecx
// 004d1ced  eb07                 jmp 0x4d1cf6
// 004d1cef  8b4708               mov eax, dword ptr [edi + 8]
// 004d1cf2  2bc2                 sub eax, edx
// 004d1cf4  03c1                 add eax, ecx
// 004d1cf6  85c0                 test eax, eax
// 004d1cf8  0f84b0020000         je 0x4d1fae
// 004d1cfe  ff07                 inc dword ptr [edi]
// 004d1d00  8b07                 mov eax, dword ptr [edi]
// 004d1d02  8b4f08               mov ecx, dword ptr [edi + 8]
// 004d1d05  3bc1                 cmp eax, ecx
// 004d1d07  7512                 jne 0x4d1d1b
// 004d1d09  8b57fc               mov edx, dword ptr [edi - 4]
// 004d1d0c  c70700000000         mov dword ptr [edi], 0
// 004d1d12  8b448afc             mov eax, dword ptr [edx + ecx*4 - 4]
// 004d1d16  83c7fc               add edi, -4
// 004d1d19  eb1a                 jmp 0x4d1d35
// 004d1d1b  85c0                 test eax, eax
// 004d1d1d  750c                 jne 0x4d1d2b
// 004d1d1f  8b57fc               mov edx, dword ptr [edi - 4]
// 004d1d22  8b448afc             mov eax, dword ptr [edx + ecx*4 - 4]
// 004d1d26  83c7fc               add edi, -4
// 004d1d29  eb0a                 jmp 0x4d1d35
// 004d1d2b  8b4ffc               mov ecx, dword ptr [edi - 4]
// 004d1d2e  8b4481fc             mov eax, dword ptr [ecx + eax*4 - 4]
// 004d1d32  83c7fc               add edi, -4
// 004d1d35  89442414             mov dword ptr [esp + 0x14], eax
// 004d1d39  8b4810               mov ecx, dword ptr [eax + 0x10]
// 004d1d3c  ba23000000           mov edx, 0x23
// 004d1d41  83f901               cmp ecx, 1
// 004d1d44  740a                 je 0x4d1d50
// 004d1d46  83f904               cmp ecx, 4
// 004d1d49  7405                 je 0x4d1d50
// 004d1d4b  83f903               cmp ecx, 3
// 004d1d4e  7505                 jne 0x4d1d55
// 004d1d50  ba48000000           mov edx, 0x48
// 004d1d55  42                   inc edx
// 004d1d56  83782400             cmp dword ptr [eax + 0x24], 0
// 004d1d5a  7603                 jbe 0x4d1d5f
// 004d1d5c  83c250               add edx, 0x50
// 004d1d5f  8b7838               mov edi, dword ptr [eax + 0x38]
// 004d1d62  8b6e34               mov ebp, dword ptr [esi + 0x34]
// 004d1d65  8d5c3a10             lea ebx, [edx + edi + 0x10]
// 004d1d69  8b5630               mov edx, dword ptr [esi + 0x30]
// 004d1d6c  8bfa                 mov edi, edx
// 004d1d6e  0bfd                 or edi, ebp
// 004d1d70  7446                 je 0x4d1db8
// 004d1d72  85c9                 test ecx, ecx
// 004d1d74  7405                 je 0x4d1d7b
// 004d1d76  83f901               cmp ecx, 1
// 004d1d79  753d                 jne 0x4d1db8
// 004d1d7b  8b7828               mov edi, dword ptr [eax + 0x28]
// 004d1d7e  03fa                 add edi, edx
// 004d1d80  8b502c               mov edx, dword ptr [eax + 0x2c]
// 004d1d83  13d5                 adc edx, ebp
// 004d1d85  39542448             cmp dword ptr [esp + 0x48], edx
// 004d1d89  7c2d                 jl 0x4d1db8
// 004d1d8b  7f06                 jg 0x4d1d93
// 004d1d8d  397c2444             cmp dword ptr [esp + 0x44], edi
// 004d1d91  7625                 jbe 0x4d1db8
// 004d1d93  8b503c               mov edx, dword ptr [eax + 0x3c]
// 004d1d96  52                   push edx
// 004d1d97  e8dee81c00           call 0x6a067a
// 004d1d9c  8b442418             mov eax, dword ptr [esp + 0x18]
// 004d1da0  83c404               add esp, 4
// 004d1da3  50                   push eax
// 004d1da4  8d8eb0070000         lea ecx, [esi + 0x7b0]
// 004d1daa  e8f1dbffff           call 0x4cf9a0
// 004d1daf  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004d1db3  e928ffffff           jmp 0x4d1ce0
// 004d1db8  8b542438             mov edx, dword ptr [esp + 0x38]
// 004d1dbc  8b12                 mov edx, dword ptr [edx]
// 004d1dbe  03d3                 add edx, ebx
// 004d1dc0  3b542420             cmp edx, dword ptr [esp + 0x20]
// 004d1dc4  0f8fcd010000         jg 0x4d1f97
// 004d1dca  83f902               cmp ecx, 2
// 004d1dcd  740f                 je 0x4d1dde
// 004d1dcf  83f904               cmp ecx, 4
// 004d1dd2  740a                 je 0x4d1dde
// 004d1dd4  c644241200           mov byte ptr [esp + 0x12], 0
// 004d1dd9  83f903               cmp ecx, 3
// 004d1ddc  7505                 jne 0x4d1de3
// 004d1dde  c644241201           mov byte ptr [esp + 0x12], 1
// 004d1de3  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004d1de7  ff45f0               inc dword ptr [ebp - 0x10]
// 004d1dea  8b4038               mov eax, dword ptr [eax + 0x38]
// 004d1ded  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 004d1df1  014500               add dword ptr [ebp], eax
// 004d1df4  33ff                 xor edi, edi
// 004d1df6  397b04               cmp dword ptr [ebx + 4], edi
// 004d1df9  764a                 jbe 0x4d1e45
// 004d1dfb  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004d1dff  8b542444             mov edx, dword ptr [esp + 0x44]
// 004d1e03  57                   push edi
// 004d1e04  68e8030000           push 0x3e8
// 004d1e09  51                   push ecx
// 004d1e0a  52                   push edx
// 004d1e0b  e820fe1c00           call 0x6a1c30
// 004d1e10  8be8                 mov ebp, eax
// 004d1e12  89542430             mov dword ptr [esp + 0x30], edx
// 004d1e16  8b03                 mov eax, dword ptr [ebx]
// 004d1e18  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 004d1e1b  8b442450             mov eax, dword ptr [esp + 0x50]
// 004d1e1f  8b11                 mov edx, dword ptr [ecx]
// 004d1e21  8b5228               mov edx, dword ptr [edx + 0x28]
// 004d1e24  6a01                 push 1
// 004d1e26  55                   push ebp
// 004d1e27  50                   push eax
// 004d1e28  8b442458             mov eax, dword ptr [esp + 0x58]
// 004d1e2c  50                   push eax
// 004d1e2d  8b8684070000         mov eax, dword ptr [esi + 0x784]
// 004d1e33  50                   push eax
// 004d1e34  8b442428             mov eax, dword ptr [esp + 0x28]
// 004d1e38  50                   push eax
// 004d1e39  ffd2                 call edx
// 004d1e3b  47                   inc edi
// 004d1e3c  3b7b04               cmp edi, dword ptr [ebx + 4]
// 004d1e3f  72d5                 jb 0x4d1e16
// 004d1e41  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004d1e45  807c243c00           cmp byte ptr [esp + 0x3c], 0
// 004d1e4a  753c                 jne 0x4d1e88
// 004d1e4c  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004d1e50  c644243c01           mov byte ptr [esp + 0x3c], 1
// 004d1e55  e80637fdff           call 0x4a5560
// 004d1e5a  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 004d1e5e  8b442444             mov eax, dword ptr [esp + 0x44]
// 004d1e62  6a00                 push 0
// 004d1e64  68e8030000           push 0x3e8
// 004d1e69  53                   push ebx
// 004d1e6a  50                   push eax
// 004d1e6b  e8c0fd1c00           call 0x6a1c30
// 004d1e70  6a01                 push 1
// 004d1e72  6a20                 push 0x20
// 004d1e74  8d4c2434             lea ecx, [esp + 0x34]
// 004d1e78  51                   push ecx
// 004d1e79  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 004d1e7d  89442438             mov dword ptr [esp + 0x38], eax
// 004d1e81  e87a37fdff           call 0x4a5600
// 004d1e86  eb04                 jmp 0x4d1e8c
// 004d1e88  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 004d1e8c  8b542414             mov edx, dword ptr [esp + 0x14]
// 004d1e90  c6420401             mov byte ptr [edx + 4], 1
// 004d1e94  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 004d1e9a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004d1e9e  8b542444             mov edx, dword ptr [esp + 0x44]
// 004d1ea2  8901                 mov dword ptr [ecx], eax
// 004d1ea4  8b442414             mov eax, dword ptr [esp + 0x14]
// 004d1ea8  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004d1eac  ff86b0000000         inc dword ptr [esi + 0xb0]
// 004d1eb2  53                   push ebx
// 004d1eb3  52                   push edx
// 004d1eb4  50                   push eax
// 004d1eb5  51                   push ecx
// 004d1eb6  8bce                 mov ecx, esi
// 004d1eb8  e833d9ffff           call 0x4cf7f0
// 004d1ebd  014510               add dword ptr [ebp + 0x10], eax
// 004d1ec0  807c241200           cmp byte ptr [esp + 0x12], 0
// 004d1ec5  8b9684070000         mov edx, dword ptr [esi + 0x784]
// 004d1ecb  8b442414             mov eax, dword ptr [esp + 0x14]
// 004d1ecf  895008               mov dword ptr [eax + 8], edx
// 004d1ed2  0f8496000000         je 0x4d1f6e
// 004d1ed8  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004d1edc  8b4f38               mov ecx, dword ptr [edi + 0x38]
// 004d1edf  014c2424             add dword ptr [esp + 0x24], ecx
// 004d1ee3  8b96d8040000         mov edx, dword ptr [esi + 0x4d8]
// 004d1ee9  8b86dc040000         mov eax, dword ptr [esi + 0x4dc]
// 004d1eef  6a00                 push 0
// 004d1ef1  81c2a0860100         add edx, 0x186a0
// 004d1ef7  6a03                 push 3
// 004d1ef9  83d000               adc eax, 0
// 004d1efc  50                   push eax
// 004d1efd  52                   push edx
// 004d1efe  e8cdf71c00           call 0x6a16d0
// 004d1f03  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 004d1f07  03c5                 add eax, ebp
// 004d1f09  894730               mov dword ptr [edi + 0x30], eax
// 004d1f0c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004d1f10  13d3                 adc edx, ebx
// 004d1f12  895134               mov dword ptr [ecx + 0x34], edx
// 004d1f15  8b442414             mov eax, dword ptr [esp + 0x14]
// 004d1f19  8b08                 mov ecx, dword ptr [eax]
// 004d1f1b  8d542414             lea edx, [esp + 0x14]
// 004d1f1f  52                   push edx
// 004d1f20  51                   push ecx
// 004d1f21  8d4e38               lea ecx, [esi + 0x38]
// 004d1f24  e827f9ffff           call 0x4d1850
// 004d1f29  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 004d1f2f  0b86bc000000         or eax, dword ptr [esi + 0xbc]
// 004d1f35  8b542414             mov edx, dword ptr [esp + 0x14]
// 004d1f39  8954242c             mov dword ptr [esp + 0x2c], edx
// 004d1f3d  7406                 je 0x4d1f45
// 004d1f3f  837e4c00             cmp dword ptr [esi + 0x4c], 0
// 004d1f43  750c                 jne 0x4d1f51
// 004d1f45  89aeb8000000         mov dword ptr [esi + 0xb8], ebp
// 004d1f4b  899ebc000000         mov dword ptr [esi + 0xbc], ebx
// 004d1f51  8d4c242c             lea ecx, [esp + 0x2c]
// 004d1f55  51                   push ecx
// 004d1f56  8d4e54               lea ecx, [esi + 0x54]
// 004d1f59  e882ceffff           call 0x4cede0
// 004d1f5e  8b542440             mov edx, dword ptr [esp + 0x40]
// 004d1f62  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004d1f66  c60201               mov byte ptr [edx], 1
// 004d1f69  e972fdffff           jmp 0x4d1ce0
// 004d1f6e  8b442414             mov eax, dword ptr [esp + 0x14]
// 004d1f72  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 004d1f75  51                   push ecx
// 004d1f76  e8ffe61c00           call 0x6a067a
// 004d1f7b  8b542418             mov edx, dword ptr [esp + 0x18]
// 004d1f7f  83c404               add esp, 4
// 004d1f82  52                   push edx
// 004d1f83  8d8eb0070000         lea ecx, [esi + 0x7b0]
// 004d1f89  e812daffff           call 0x4cf9a0
// 004d1f8e  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004d1f92  e949fdffff           jmp 0x4d1ce0
// 004d1f97  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004d1f9b  6a00                 push 0
// 004d1f9d  8d442418             lea eax, [esp + 0x18]
// 004d1fa1  50                   push eax
// 004d1fa2  83c1fc               add ecx, -4
// 004d1fa5  e806cfffff           call 0x4ceeb0
// 004d1faa  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004d1fae  8b442428             mov eax, dword ptr [esp + 0x28]
// 004d1fb2  8344241c04           add dword ptr [esp + 0x1c], 4
// 004d1fb7  40                   inc eax
// 004d1fb8  83c710               add edi, 0x10
// 004d1fbb  89442428             mov dword ptr [esp + 0x28], eax
// 004d1fbf  897c2418             mov dword ptr [esp + 0x18], edi
// 004d1fc3  83f804               cmp eax, 4
// 004d1fc6  0f8214fdffff         jb 0x4d1ce0
// 004d1fcc  8a5c243c             mov bl, byte ptr [esp + 0x3c]
// 004d1fd0  84db                 test bl, bl
// 004d1fd2  7509                 jne 0x4d1fdd
// 004d1fd4  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004d1fd8  e86335fdff           call 0x4a5540
// 004d1fdd  8a442413             mov al, byte ptr [esp + 0x13]
// 004d1fe1  84c0                 test al, al
// 004d1fe3  7504                 jne 0x4d1fe9
// 004d1fe5  84db                 test bl, bl
// 004d1fe7  740e                 je 0x4d1ff7
// 004d1fe9  ff8684070000         inc dword ptr [esi + 0x784]
// 004d1fef  84c0                 test al, al
// 004d1ff1  7510                 jne 0x4d2003
// 004d1ff3  84db                 test bl, bl
// 004d1ff5  750c                 jne 0x4d2003
// 004d1ff7  5f                   pop edi
// 004d1ff8  5e                   pop esi
// 004d1ff9  5d                   pop ebp
// 004d1ffa  33c0                 xor eax, eax
// 004d1ffc  5b                   pop ebx
// 004d1ffd  83c424               add esp, 0x24
// 004d2000  c22000               ret 0x20
// 004d2003  5f                   pop edi
// 004d2004  5e                   pop esi
// 004d2005  5d                   pop ebp
// 004d2006  b801000000           mov eax, 1
// 004d200b  5b                   pop ebx
// 004d200c  83c424               add esp, 0x24
// 004d200f  c22000               ret 0x20
// library openrbx-raknet/ReliabilityLayer.cpp (function ?GenerateDatagram@ReliabilityLayer@@AAE_NPAVBitStream@RakNet@@HPA_N_JUSystemAddress@@AAV?$List@PAVPluginInterface@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
