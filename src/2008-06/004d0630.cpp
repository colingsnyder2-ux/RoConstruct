// from server: 100% by auto
// roc 2008-06 004d0630  unit: RBX::Network::PhysicsSender  size: 404 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d0630
//
// 004d0630  51                   push ecx
// 004d0631  57                   push edi
// 004d0632  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004d0636  8b07                 mov eax, dword ptr [edi]
// 004d0638  2b4708               sub eax, dword ptr [edi + 8]
// 004d063b  83f820               cmp eax, 0x20
// 004d063e  7d07                 jge 0x4d0647
// 004d0640  33c0                 xor eax, eax
// 004d0642  5f                   pop edi
// 004d0643  59                   pop ecx
// 004d0644  c20c00               ret 0xc
// 004d0647  55                   push ebp
// 004d0648  8da9b0070000         lea ebp, [ecx + 0x7b0]
// 004d064e  56                   push esi
// 004d064f  8bcd                 mov ecx, ebp
// 004d0651  e8aaf2ffff           call 0x4cf900
// 004d0656  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004d065a  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004d065e  8bf0                 mov esi, eax
// 004d0660  6a01                 push 1
// 004d0662  6a20                 push 0x20
// 004d0664  894e28               mov dword ptr [esi + 0x28], ecx
// 004d0667  56                   push esi
// 004d0668  8bcf                 mov ecx, edi
// 004d066a  89562c               mov dword ptr [esi + 0x2c], edx
// 004d066d  e89e4bfdff           call 0x4a5210
// 004d0672  84c0                 test al, al
// 004d0674  0f84a5000000         je 0x4d071f
// 004d067a  6a01                 push 1
// 004d067c  6a03                 push 3
// 004d067e  8d44241c             lea eax, [esp + 0x1c]
// 004d0682  50                   push eax
// 004d0683  8bcf                 mov ecx, edi
// 004d0685  e8864bfdff           call 0x4a5210
// 004d068a  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 004d068f  894e10               mov dword ptr [esi + 0x10], ecx
// 004d0692  84c0                 test al, al
// 004d0694  0f8485000000         je 0x4d071f
// 004d069a  83f901               cmp ecx, 1
// 004d069d  740a                 je 0x4d06a9
// 004d069f  83f904               cmp ecx, 4
// 004d06a2  7405                 je 0x4d06a9
// 004d06a4  83f903               cmp ecx, 3
// 004d06a7  7526                 jne 0x4d06cf
// 004d06a9  6a01                 push 1
// 004d06ab  6a05                 push 5
// 004d06ad  8d4e14               lea ecx, [esi + 0x14]
// 004d06b0  51                   push ecx
// 004d06b1  8bcf                 mov ecx, edi
// 004d06b3  e8584bfdff           call 0x4a5210
// 004d06b8  84c0                 test al, al
// 004d06ba  7463                 je 0x4d071f
// 004d06bc  6a01                 push 1
// 004d06be  6a20                 push 0x20
// 004d06c0  8d5618               lea edx, [esi + 0x18]
// 004d06c3  52                   push edx
// 004d06c4  8bcf                 mov ecx, edi
// 004d06c6  e8454bfdff           call 0x4a5210
// 004d06cb  84c0                 test al, al
// 004d06cd  7450                 je 0x4d071f
// 004d06cf  8d442418             lea eax, [esp + 0x18]
// 004d06d3  50                   push eax
// 004d06d4  8bcf                 mov ecx, edi
// 004d06d6  e87549fdff           call 0x4a5050
// 004d06db  84c0                 test al, al
// 004d06dd  7440                 je 0x4d071f
// 004d06df  807c241800           cmp byte ptr [esp + 0x18], 0
// 004d06e4  744a                 je 0x4d0730
// 004d06e6  6a01                 push 1
// 004d06e8  6a10                 push 0x10
// 004d06ea  8d4e1c               lea ecx, [esi + 0x1c]
// 004d06ed  51                   push ecx
// 004d06ee  8bcf                 mov ecx, edi
// 004d06f0  e81b4bfdff           call 0x4a5210
// 004d06f5  84c0                 test al, al
// 004d06f7  7426                 je 0x4d071f
// 004d06f9  6a01                 push 1
// 004d06fb  6a20                 push 0x20
// 004d06fd  8d5620               lea edx, [esi + 0x20]
// 004d0700  52                   push edx
// 004d0701  8bcf                 mov ecx, edi
// 004d0703  e8b84bfdff           call 0x4a52c0
// 004d0708  84c0                 test al, al
// 004d070a  7413                 je 0x4d071f
// 004d070c  6a01                 push 1
// 004d070e  6a20                 push 0x20
// 004d0710  8d4624               lea eax, [esi + 0x24]
// 004d0713  50                   push eax
// 004d0714  8bcf                 mov ecx, edi
// 004d0716  e8a54bfdff           call 0x4a52c0
// 004d071b  84c0                 test al, al
// 004d071d  751f                 jne 0x4d073e
// 004d071f  56                   push esi
// 004d0720  8bcd                 mov ecx, ebp
// 004d0722  e879f2ffff           call 0x4cf9a0
// 004d0727  5e                   pop esi
// 004d0728  5d                   pop ebp
// 004d0729  33c0                 xor eax, eax
// 004d072b  5f                   pop edi
// 004d072c  59                   pop ecx
// 004d072d  c20c00               ret 0xc
// 004d0730  c7462400000000       mov dword ptr [esi + 0x24], 0
// 004d0737  c7462000000000       mov dword ptr [esi + 0x20], 0
// 004d073e  6a01                 push 1
// 004d0740  6a10                 push 0x10
// 004d0742  8d4c2414             lea ecx, [esp + 0x14]
// 004d0746  51                   push ecx
// 004d0747  8bcf                 mov ecx, edi
// 004d0749  e8724bfdff           call 0x4a52c0
// 004d074e  84c0                 test al, al
// 004d0750  74cd                 je 0x4d071f
// 004d0752  0fb744240c           movzx eax, word ptr [esp + 0xc]
// 004d0757  894638               mov dword ptr [esi + 0x38], eax
// 004d075a  85c0                 test eax, eax
// 004d075c  76c1                 jbe 0x4d071f
// 004d075e  83c007               add eax, 7
// 004d0761  c1e803               shr eax, 3
// 004d0764  3dd4050000           cmp eax, 0x5d4
// 004d0769  73b4                 jae 0x4d071f
// 004d076b  50                   push eax
// 004d076c  e8af011d00           call 0x6a0920
// 004d0771  8b5638               mov edx, dword ptr [esi + 0x38]
// 004d0774  89463c               mov dword ptr [esi + 0x3c], eax
// 004d0777  83c207               add edx, 7
// 004d077a  c1ea03               shr edx, 3
// 004d077d  c64402ff00           mov byte ptr [edx + eax - 1], 0
// 004d0782  8b4638               mov eax, dword ptr [esi + 0x38]
// 004d0785  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004d0788  83c007               add eax, 7
// 004d078b  83c404               add esp, 4
// 004d078e  c1e803               shr eax, 3
// 004d0791  50                   push eax
// 004d0792  51                   push ecx
// 004d0793  8bcf                 mov ecx, edi
// 004d0795  e8064efdff           call 0x4a55a0
// 004d079a  84c0                 test al, al
// 004d079c  751d                 jne 0x4d07bb
// 004d079e  8b563c               mov edx, dword ptr [esi + 0x3c]
// 004d07a1  52                   push edx
// 004d07a2  e8d3fe1c00           call 0x6a067a
// 004d07a7  83c404               add esp, 4
// 004d07aa  56                   push esi
// 004d07ab  8bcd                 mov ecx, ebp
// 004d07ad  e8eef1ffff           call 0x4cf9a0
// 004d07b2  5e                   pop esi
// 004d07b3  5d                   pop ebp
// 004d07b4  33c0                 xor eax, eax
// 004d07b6  5f                   pop edi
// 004d07b7  59                   pop ecx
// 004d07b8  c20c00               ret 0xc
// 004d07bb  8bc6                 mov eax, esi
// 004d07bd  5e                   pop esi
// 004d07be  5d                   pop ebp
// 004d07bf  5f                   pop edi
// 004d07c0  59                   pop ecx
// 004d07c1  c20c00               ret 0xc
// library openrbx-raknet/ReliabilityLayer.cpp (function ?CreateInternalPacketFromBitStream@ReliabilityLayer@@AAEPAUInternalPacket@@PAVBitStream@RakNet@@_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
