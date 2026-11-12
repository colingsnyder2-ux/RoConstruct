// from server: 100% by auto
// roc 2008-06 004d07d0  unit: RBX::Network::PhysicsSender  size: 553 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d07d0
//
// 004d07d0  55                   push ebp
// 004d07d1  8bec                 mov ebp, esp
// 004d07d3  83ec14               sub esp, 0x14
// 004d07d6  53                   push ebx
// 004d07d7  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004d07da  56                   push esi
// 004d07db  8bf1                 mov esi, ecx
// 004d07dd  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004d07e0  57                   push edi
// 004d07e1  8975fc               mov dword ptr [ebp - 4], esi
// 004d07e4  c7432401000000       mov dword ptr [ebx + 0x24], 1
// 004d07eb  b823000000           mov eax, 0x23
// 004d07f0  83f901               cmp ecx, 1
// 004d07f3  740a                 je 0x4d07ff
// 004d07f5  83f904               cmp ecx, 4
// 004d07f8  7405                 je 0x4d07ff
// 004d07fa  83f903               cmp ecx, 3
// 004d07fd  7505                 jne 0x4d0804
// 004d07ff  b848000000           mov eax, 0x48
// 004d0804  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004d0807  83c068               add eax, 0x68
// 004d080a  c1f803               sar eax, 3
// 004d080d  894508               mov dword ptr [ebp + 8], eax
// 004d0810  8b4338               mov eax, dword ptr [ebx + 0x38]
// 004d0813  83c007               add eax, 7
// 004d0816  c1e803               shr eax, 3
// 004d0819  8d8e28050000         lea ecx, [esi + 0x528]
// 004d081f  8945f0               mov dword ptr [ebp - 0x10], eax
// 004d0822  83c7e4               add edi, -0x1c
// 004d0825  e866510000           call 0x4d5990
// 004d082a  84c0                 test al, al
// 004d082c  7403                 je 0x4d0831
// 004d082e  83ef10               sub edi, 0x10
// 004d0831  2b7d08               sub edi, dword ptr [ebp + 8]
// 004d0834  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004d0837  48                   dec eax
// 004d0838  99                   cdq 
// 004d0839  f7ff                 idiv edi
// 004d083b  897df4               mov dword ptr [ebp - 0xc], edi
// 004d083e  c6450b00             mov byte ptr [ebp + 0xb], 0
// 004d0842  40                   inc eax
// 004d0843  894324               mov dword ptr [ebx + 0x24], eax
// 004d0846  01864c040000         add dword ptr [esi + 0x44c], eax
// 004d084c  8b7b24               mov edi, dword ptr [ebx + 0x24]
// 004d084f  8d04bd00000000       lea eax, [edi*4]
// 004d0856  3d00001000           cmp eax, 0x100000
// 004d085b  7310                 jae 0x4d086d
// 004d085d  e8fe0c1d00           call 0x6a1560
// 004d0862  8bfc                 mov edi, esp
// 004d0864  897d0c               mov dword ptr [ebp + 0xc], edi
// 004d0867  c6450b01             mov byte ptr [ebp + 0xb], 1
// 004d086b  eb20                 jmp 0x4d088d
// 004d086d  33c9                 xor ecx, ecx
// 004d086f  8bc7                 mov eax, edi
// 004d0871  ba04000000           mov edx, 4
// 004d0876  f7e2                 mul edx
// 004d0878  0f90c1               seto cl
// 004d087b  f7d9                 neg ecx
// 004d087d  0bc8                 or ecx, eax
// 004d087f  51                   push ecx
// 004d0880  e89b001d00           call 0x6a0920
// 004d0885  83c404               add esp, 4
// 004d0888  89450c               mov dword ptr [ebp + 0xc], eax
// 004d088b  8bf8                 mov edi, eax
// 004d088d  837b2400             cmp dword ptr [ebx + 0x24], 0
// 004d0891  c745f800000000       mov dword ptr [ebp - 8], 0
// 004d0898  7e34                 jle 0x4d08ce
// 004d089a  eb07                 jmp 0x4d08a3
// 004d089c  8d642400             lea esp, [esp]
// 004d08a0  8b75fc               mov esi, dword ptr [ebp - 4]
// 004d08a3  8d8eb0070000         lea ecx, [esi + 0x7b0]
// 004d08a9  e852f0ffff           call 0x4cf900
// 004d08ae  8b4df8               mov ecx, dword ptr [ebp - 8]
// 004d08b1  89048f               mov dword ptr [edi + ecx*4], eax
// 004d08b4  8bf8                 mov edi, eax
// 004d08b6  8b45f8               mov eax, dword ptr [ebp - 8]
// 004d08b9  b910000000           mov ecx, 0x10
// 004d08be  8bf3                 mov esi, ebx
// 004d08c0  40                   inc eax
// 004d08c1  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004d08c3  3b4324               cmp eax, dword ptr [ebx + 0x24]
// 004d08c6  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004d08c9  8945f8               mov dword ptr [ebp - 8], eax
// 004d08cc  7cd2                 jl 0x4d08a0
// 004d08ce  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004d08d1  33f6                 xor esi, esi
// 004d08d3  8bc1                 mov eax, ecx
// 004d08d5  f7d8                 neg eax
// 004d08d7  8945ec               mov dword ptr [ebp - 0x14], eax
// 004d08da  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004d08dd  8975f8               mov dword ptr [ebp - 8], esi
// 004d08e0  8945f0               mov dword ptr [ebp - 0x10], eax
// 004d08e3  eb06                 jmp 0x4d08eb
// 004d08e5  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004d08e8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004d08eb  3bc1                 cmp eax, ecx
// 004d08ed  89450c               mov dword ptr [ebp + 0xc], eax
// 004d08f0  7e03                 jle 0x4d08f5
// 004d08f2  894d0c               mov dword ptr [ebp + 0xc], ecx
// 004d08f5  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004d08f8  52                   push edx
// 004d08f9  e822001d00           call 0x6a0920
// 004d08fe  8b0cb7               mov ecx, dword ptr [edi + esi*4]
// 004d0901  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004d0904  89413c               mov dword ptr [ecx + 0x3c], eax
// 004d0907  8b433c               mov eax, dword ptr [ebx + 0x3c]
// 004d090a  0345f8               add eax, dword ptr [ebp - 8]
// 004d090d  8b0cb7               mov ecx, dword ptr [edi + esi*4]
// 004d0910  52                   push edx
// 004d0911  8b513c               mov edx, dword ptr [ecx + 0x3c]
// 004d0914  50                   push eax
// 004d0915  52                   push edx
// 004d0916  e8c50e1d00           call 0x6a17e0
// 004d091b  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004d091e  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 004d0921  83c410               add esp, 0x10
// 004d0924  3bc8                 cmp ecx, eax
// 004d0926  7411                 je 0x4d0939
// 004d0928  8b5338               mov edx, dword ptr [ebx + 0x38]
// 004d092b  8d0cc500000000       lea ecx, [eax*8]
// 004d0932  0fafce               imul ecx, esi
// 004d0935  2bd1                 sub edx, ecx
// 004d0937  eb07                 jmp 0x4d0940
// 004d0939  8d14cd00000000       lea edx, [ecx*8]
// 004d0940  8b0cb7               mov ecx, dword ptr [edi + esi*4]
// 004d0943  895138               mov dword ptr [ecx + 0x38], edx
// 004d0946  8b14b7               mov edx, dword ptr [edi + esi*4]
// 004d0949  897220               mov dword ptr [edx + 0x20], esi
// 004d094c  8b55fc               mov edx, dword ptr [ebp - 4]
// 004d094f  8b0cb7               mov ecx, dword ptr [edi + esi*4]
// 004d0952  668b92d6030000       mov dx, word ptr [edx + 0x3d6]
// 004d0959  6689511c             mov word ptr [ecx + 0x1c], dx
// 004d095d  8b0cb7               mov ecx, dword ptr [edi + esi*4]
// 004d0960  8b5324               mov edx, dword ptr [ebx + 0x24]
// 004d0963  895124               mov dword ptr [ecx + 0x24], edx
// 004d0966  85f6                 test esi, esi
// 004d0968  7610                 jbe 0x4d097a
// 004d096a  8b0cb7               mov ecx, dword ptr [edi + esi*4]
// 004d096d  c701ffffffff         mov dword ptr [ecx], 0xffffffff
// 004d0973  8b14b7               mov edx, dword ptr [edi + esi*4]
// 004d0976  c6420400             mov byte ptr [edx + 4], 0
// 004d097a  0145f8               add dword ptr [ebp - 8], eax
// 004d097d  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004d0980  0145f0               add dword ptr [ebp - 0x10], eax
// 004d0983  46                   inc esi
// 004d0984  3b7324               cmp esi, dword ptr [ebx + 0x24]
// 004d0987  0f8258ffffff         jb 0x4d08e5
// 004d098d  8b45fc               mov eax, dword ptr [ebp - 4]
// 004d0990  66ff80d6030000       inc word ptr [eax + 0x3d6]
// 004d0997  33f6                 xor esi, esi
// 004d0999  397324               cmp dword ptr [ebx + 0x24], esi
// 004d099c  7e25                 jle 0x4d09c3
// 004d099e  897d0c               mov dword ptr [ebp + 0xc], edi
// 004d09a1  eb03                 jmp 0x4d09a6
// 004d09a3  8b45fc               mov eax, dword ptr [ebp - 4]
// 004d09a6  8b530c               mov edx, dword ptr [ebx + 0xc]
// 004d09a9  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004d09ac  c1e204               shl edx, 4
// 004d09af  51                   push ecx
// 004d09b0  8d4c0264             lea ecx, [edx + eax + 0x64]
// 004d09b4  e827e4ffff           call 0x4cede0
// 004d09b9  83450c04             add dword ptr [ebp + 0xc], 4
// 004d09bd  46                   inc esi
// 004d09be  3b7324               cmp esi, dword ptr [ebx + 0x24]
// 004d09c1  7ce0                 jl 0x4d09a3
// 004d09c3  8b433c               mov eax, dword ptr [ebx + 0x3c]
// 004d09c6  50                   push eax
// 004d09c7  e8aefc1c00           call 0x6a067a
// 004d09cc  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004d09cf  83c404               add esp, 4
// 004d09d2  53                   push ebx
// 004d09d3  81c1b0070000         add ecx, 0x7b0
// 004d09d9  e8c2efffff           call 0x4cf9a0
// 004d09de  807d0b00             cmp byte ptr [ebp + 0xb], 0
// 004d09e2  7509                 jne 0x4d09ed
// 004d09e4  57                   push edi
// 004d09e5  e890fc1c00           call 0x6a067a
// 004d09ea  83c404               add esp, 4
// 004d09ed  8d65e0               lea esp, [ebp - 0x20]
// 004d09f0  5f                   pop edi
// 004d09f1  5e                   pop esi
// 004d09f2  5b                   pop ebx
// 004d09f3  8be5                 mov esp, ebp
// 004d09f5  5d                   pop ebp
// 004d09f6  c20800               ret 8
// library openrbx-raknet/ReliabilityLayer.cpp (function ?SplitPacket@ReliabilityLayer@@AAEXPAUInternalPacket@@H@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
