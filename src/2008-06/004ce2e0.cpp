// from server: 100% by auto
// roc 2008-06 004ce2e0  unit: RBX::Network::PhysicsSender  size: 642 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ce2e0
//
// 004ce2e0  6aff                 push -1
// 004ce2e2  68e19a7c00           push 0x7c9ae1
// 004ce2e7  64a100000000         mov eax, dword ptr fs:[0]
// 004ce2ed  50                   push eax
// 004ce2ee  64892500000000       mov dword ptr fs:[0], esp
// 004ce2f5  81ec28060000         sub esp, 0x628
// 004ce2fb  53                   push ebx
// 004ce2fc  55                   push ebp
// 004ce2fd  56                   push esi
// 004ce2fe  57                   push edi
// 004ce2ff  33ff                 xor edi, edi
// 004ce301  8be9                 mov ebp, ecx
// 004ce303  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004ce307  897c2414             mov dword ptr [esp + 0x14], edi
// 004ce30b  897c2418             mov dword ptr [esp + 0x18], edi
// 004ce30f  897c2410             mov dword ptr [esp + 0x10], edi
// 004ce313  89bc2440060000       mov dword ptr [esp + 0x640], edi
// 004ce31a  e8c1fcffff           call 0x4cdfe0
// 004ce31f  8bb42448060000       mov esi, dword ptr [esp + 0x648]
// 004ce326  8d842438020000       lea eax, [esp + 0x238]
// 004ce32d  33db                 xor ebx, ebx
// 004ce32f  2bf0                 sub esi, eax
// 004ce331  6a14                 push 0x14
// 004ce333  e8e8251d00           call 0x6a0920
// 004ce338  8d0c9e               lea ecx, [esi + ebx*4]
// 004ce33b  897808               mov dword ptr [eax + 8], edi
// 004ce33e  89780c               mov dword ptr [eax + 0xc], edi
// 004ce341  8818                 mov byte ptr [eax], bl
// 004ce343  8b8c0c3c020000       mov ecx, dword ptr [esp + ecx + 0x23c]
// 004ce34a  83c404               add esp, 4
// 004ce34d  894804               mov dword ptr [eax + 4], ecx
// 004ce350  3bcf                 cmp ecx, edi
// 004ce352  7507                 jne 0x4ce35b
// 004ce354  c7400401000000       mov dword ptr [eax + 4], 1
// 004ce35b  8d542410             lea edx, [esp + 0x10]
// 004ce35f  52                   push edx
// 004ce360  50                   push eax
// 004ce361  8bcd                 mov ecx, ebp
// 004ce363  89849c40020000       mov dword ptr [esp + ebx*4 + 0x240], eax
// 004ce36a  e871feffff           call 0x4ce1e0
// 004ce36f  43                   inc ebx
// 004ce370  81fb00010000         cmp ebx, 0x100
// 004ce376  7cb9                 jl 0x4ce331
// 004ce378  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 004ce37c  3bdf                 cmp ebx, edi
// 004ce37e  7408                 je 0x4ce388
// 004ce380  8bc3                 mov eax, ebx
// 004ce382  89442418             mov dword ptr [esp + 0x18], eax
// 004ce386  eb04                 jmp 0x4ce38c
// 004ce388  8b442418             mov eax, dword ptr [esp + 0x18]
// 004ce38c  8b742410             mov esi, dword ptr [esp + 0x10]
// 004ce390  8b28                 mov ebp, dword ptr [eax]
// 004ce392  896c2420             mov dword ptr [esp + 0x20], ebp
// 004ce396  3bf7                 cmp esi, edi
// 004ce398  744d                 je 0x4ce3e7
// 004ce39a  83fe01               cmp esi, 1
// 004ce39d  7515                 jne 0x4ce3b4
// 004ce39f  53                   push ebx
// 004ce3a0  e8d5221d00           call 0x6a067a
// 004ce3a5  33db                 xor ebx, ebx
// 004ce3a7  83c404               add esp, 4
// 004ce3aa  33c0                 xor eax, eax
// 004ce3ac  895c2414             mov dword ptr [esp + 0x14], ebx
// 004ce3b0  33f6                 xor esi, esi
// 004ce3b2  eb2b                 jmp 0x4ce3df
// 004ce3b4  8b4804               mov ecx, dword ptr [eax + 4]
// 004ce3b7  8b5008               mov edx, dword ptr [eax + 8]
// 004ce3ba  895108               mov dword ptr [ecx + 8], edx
// 004ce3bd  8b4808               mov ecx, dword ptr [eax + 8]
// 004ce3c0  8b5004               mov edx, dword ptr [eax + 4]
// 004ce3c3  895104               mov dword ptr [ecx + 4], edx
// 004ce3c6  8b7808               mov edi, dword ptr [eax + 8]
// 004ce3c9  3bc3                 cmp eax, ebx
// 004ce3cb  7506                 jne 0x4ce3d3
// 004ce3cd  8bdf                 mov ebx, edi
// 004ce3cf  895c2414             mov dword ptr [esp + 0x14], ebx
// 004ce3d3  50                   push eax
// 004ce3d4  e8a1221d00           call 0x6a067a
// 004ce3d9  83c404               add esp, 4
// 004ce3dc  8bc7                 mov eax, edi
// 004ce3de  4e                   dec esi
// 004ce3df  89742410             mov dword ptr [esp + 0x10], esi
// 004ce3e3  89442418             mov dword ptr [esp + 0x18], eax
// 004ce3e7  8b38                 mov edi, dword ptr [eax]
// 004ce3e9  85f6                 test esi, esi
// 004ce3eb  744d                 je 0x4ce43a
// 004ce3ed  83fe01               cmp esi, 1
// 004ce3f0  7515                 jne 0x4ce407
// 004ce3f2  53                   push ebx
// 004ce3f3  e882221d00           call 0x6a067a
// 004ce3f8  83c404               add esp, 4
// 004ce3fb  33f6                 xor esi, esi
// 004ce3fd  89742418             mov dword ptr [esp + 0x18], esi
// 004ce401  89742414             mov dword ptr [esp + 0x14], esi
// 004ce405  eb2f                 jmp 0x4ce436
// 004ce407  8b4804               mov ecx, dword ptr [eax + 4]
// 004ce40a  8b5008               mov edx, dword ptr [eax + 8]
// 004ce40d  895108               mov dword ptr [ecx + 8], edx
// 004ce410  8b4808               mov ecx, dword ptr [eax + 8]
// 004ce413  8b5004               mov edx, dword ptr [eax + 4]
// 004ce416  895104               mov dword ptr [ecx + 4], edx
// 004ce419  8b6808               mov ebp, dword ptr [eax + 8]
// 004ce41c  3bc3                 cmp eax, ebx
// 004ce41e  7504                 jne 0x4ce424
// 004ce420  896c2414             mov dword ptr [esp + 0x14], ebp
// 004ce424  50                   push eax
// 004ce425  e850221d00           call 0x6a067a
// 004ce42a  83c404               add esp, 4
// 004ce42d  896c2418             mov dword ptr [esp + 0x18], ebp
// 004ce431  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004ce435  4e                   dec esi
// 004ce436  89742410             mov dword ptr [esp + 0x10], esi
// 004ce43a  6a14                 push 0x14
// 004ce43c  e8df241d00           call 0x6a0920
// 004ce441  896808               mov dword ptr [eax + 8], ebp
// 004ce444  89780c               mov dword ptr [eax + 0xc], edi
// 004ce447  8b4f04               mov ecx, dword ptr [edi + 4]
// 004ce44a  034d04               add ecx, dword ptr [ebp + 4]
// 004ce44d  83c404               add esp, 4
// 004ce450  894804               mov dword ptr [eax + 4], ecx
// 004ce453  894510               mov dword ptr [ebp + 0x10], eax
// 004ce456  894710               mov dword ptr [edi + 0x10], eax
// 004ce459  85f6                 test esi, esi
// 004ce45b  7416                 je 0x4ce473
// 004ce45d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004ce461  8d542410             lea edx, [esp + 0x10]
// 004ce465  52                   push edx
// 004ce466  50                   push eax
// 004ce467  e874fdffff           call 0x4ce1e0
// 004ce46c  33ff                 xor edi, edi
// 004ce46e  e905ffffff           jmp 0x4ce378
// 004ce473  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004ce477  8907                 mov dword ptr [edi], eax
// 004ce479  8d4c2424             lea ecx, [esp + 0x24]
// 004ce47d  c7401000000000       mov dword ptr [eax + 0x10], 0
// 004ce484  e8076cfdff           call 0x4a5090
// 004ce489  c684244006000001     mov byte ptr [esp + 0x640], 1
// 004ce491  33db                 xor ebx, ebx
// 004ce493  8d6f08               lea ebp, [edi + 8]
// 004ce496  eb08                 jmp 0x4ce4a0
// 004ce498  8da42400000000       lea esp, [esp]
// 004ce49f  90                   nop 
// 004ce4a0  8b849c38020000       mov eax, dword ptr [esp + ebx*4 + 0x238]
// 004ce4a7  8b17                 mov edx, dword ptr [edi]
// 004ce4a9  33f6                 xor esi, esi
// 004ce4ab  eb03                 jmp 0x4ce4b0
// 004ce4ad  8d4900               lea ecx, [ecx]
// 004ce4b0  8b4810               mov ecx, dword ptr [eax + 0x10]
// 004ce4b3  394108               cmp dword ptr [ecx + 8], eax
// 004ce4b6  0fb7c6               movzx eax, si
// 004ce4b9  750a                 jne 0x4ce4c5
// 004ce4bb  c684043801000000     mov byte ptr [esp + eax + 0x138], 0
// 004ce4c3  eb08                 jmp 0x4ce4cd
// 004ce4c5  c684043801000001     mov byte ptr [esp + eax + 0x138], 1
// 004ce4cd  8bc1                 mov eax, ecx
// 004ce4cf  46                   inc esi
// 004ce4d0  3bc2                 cmp eax, edx
// 004ce4d2  75dc                 jne 0x4ce4b0
// 004ce4d4  6685f6               test si, si
// 004ce4d7  762f                 jbe 0x4ce508
// 004ce4d9  0fb7fe               movzx edi, si
// 004ce4dc  8dbc3c38010000       lea edi, [esp + edi + 0x138]
// 004ce4e3  4f                   dec edi
// 004ce4e4  81c6ffff0000         add esi, 0xffff
// 004ce4ea  803f00               cmp byte ptr [edi], 0
// 004ce4ed  8d4c2424             lea ecx, [esp + 0x24]
// 004ce4f1  7407                 je 0x4ce4fa
// 004ce4f3  e86870fdff           call 0x4a5560
// 004ce4f8  eb05                 jmp 0x4ce4ff
// 004ce4fa  e84170fdff           call 0x4a5540
// 004ce4ff  6685f6               test si, si
// 004ce502  77df                 ja 0x4ce4e3
// 004ce504  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004ce508  8d4dfc               lea ecx, [ebp - 4]
// 004ce50b  51                   push ecx
// 004ce50c  8d4c2428             lea ecx, [esp + 0x28]
// 004ce510  e81b6ffdff           call 0x4a5430
// 004ce515  660fb6d0             movzx dx, al
// 004ce519  8d4c2424             lea ecx, [esp + 0x24]
// 004ce51d  66895500             mov word ptr [ebp], dx
// 004ce521  e89a6cfdff           call 0x4a51c0
// 004ce526  43                   inc ebx
// 004ce527  83c508               add ebp, 8
// 004ce52a  81fb00010000         cmp ebx, 0x100
// 004ce530  0f8c6affffff         jl 0x4ce4a0
// 004ce536  8d4c2424             lea ecx, [esp + 0x24]
// 004ce53a  c684244006000000     mov byte ptr [esp + 0x640], 0
// 004ce542  e8596cfdff           call 0x4a51a0
// 004ce547  8b8c2438060000       mov ecx, dword ptr [esp + 0x638]
// 004ce54e  5f                   pop edi
// 004ce54f  5e                   pop esi
// 004ce550  5d                   pop ebp
// 004ce551  5b                   pop ebx
// 004ce552  64890d00000000       mov dword ptr fs:[0], ecx
// 004ce559  81c434060000         add esp, 0x634
// 004ce55f  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?GenerateFromFrequencyTable@HuffmanEncodingTree@@QAEXQAI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
