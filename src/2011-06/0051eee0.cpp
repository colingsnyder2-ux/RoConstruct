// from server: 100% by auto
// roc 2011-06 0051eee0  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 642 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0051eee0
//
// 0051eee0  6aff                 push -1
// 0051eee2  68c6df9d00           push 0x9ddfc6
// 0051eee7  64a100000000         mov eax, dword ptr fs:[0]
// 0051eeed  50                   push eax
// 0051eeee  64892500000000       mov dword ptr fs:[0], esp
// 0051eef5  81ec28060000         sub esp, 0x628
// 0051eefb  53                   push ebx
// 0051eefc  55                   push ebp
// 0051eefd  56                   push esi
// 0051eefe  57                   push edi
// 0051eeff  33ff                 xor edi, edi
// 0051ef01  8be9                 mov ebp, ecx
// 0051ef03  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0051ef07  897c2414             mov dword ptr [esp + 0x14], edi
// 0051ef0b  897c2418             mov dword ptr [esp + 0x18], edi
// 0051ef0f  897c2410             mov dword ptr [esp + 0x10], edi
// 0051ef13  89bc2440060000       mov dword ptr [esp + 0x640], edi
// 0051ef1a  e8c1fdffff           call 0x51ece0
// 0051ef1f  8bb42448060000       mov esi, dword ptr [esp + 0x648]
// 0051ef26  8d842438020000       lea eax, [esp + 0x238]
// 0051ef2d  33db                 xor ebx, ebx
// 0051ef2f  2bf0                 sub esi, eax
// 0051ef31  6a14                 push 0x14
// 0051ef33  e826b12e00           call 0x80a05e
// 0051ef38  8d0c9e               lea ecx, [esi + ebx*4]
// 0051ef3b  897808               mov dword ptr [eax + 8], edi
// 0051ef3e  89780c               mov dword ptr [eax + 0xc], edi
// 0051ef41  8818                 mov byte ptr [eax], bl
// 0051ef43  8b8c0c3c020000       mov ecx, dword ptr [esp + ecx + 0x23c]
// 0051ef4a  83c404               add esp, 4
// 0051ef4d  894804               mov dword ptr [eax + 4], ecx
// 0051ef50  3bcf                 cmp ecx, edi
// 0051ef52  7507                 jne 0x51ef5b
// 0051ef54  c7400401000000       mov dword ptr [eax + 4], 1
// 0051ef5b  8d542410             lea edx, [esp + 0x10]
// 0051ef5f  52                   push edx
// 0051ef60  50                   push eax
// 0051ef61  8bcd                 mov ecx, ebp
// 0051ef63  89849c40020000       mov dword ptr [esp + ebx*4 + 0x240], eax
// 0051ef6a  e8c1feffff           call 0x51ee30
// 0051ef6f  43                   inc ebx
// 0051ef70  81fb00010000         cmp ebx, 0x100
// 0051ef76  7cb9                 jl 0x51ef31
// 0051ef78  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0051ef7c  3bdf                 cmp ebx, edi
// 0051ef7e  7408                 je 0x51ef88
// 0051ef80  8bc3                 mov eax, ebx
// 0051ef82  89442418             mov dword ptr [esp + 0x18], eax
// 0051ef86  eb04                 jmp 0x51ef8c
// 0051ef88  8b442418             mov eax, dword ptr [esp + 0x18]
// 0051ef8c  8b742410             mov esi, dword ptr [esp + 0x10]
// 0051ef90  8b28                 mov ebp, dword ptr [eax]
// 0051ef92  896c2420             mov dword ptr [esp + 0x20], ebp
// 0051ef96  3bf7                 cmp esi, edi
// 0051ef98  744d                 je 0x51efe7
// 0051ef9a  83fe01               cmp esi, 1
// 0051ef9d  7515                 jne 0x51efb4
// 0051ef9f  53                   push ebx
// 0051efa0  e8b3b02e00           call 0x80a058
// 0051efa5  33db                 xor ebx, ebx
// 0051efa7  83c404               add esp, 4
// 0051efaa  33c0                 xor eax, eax
// 0051efac  895c2414             mov dword ptr [esp + 0x14], ebx
// 0051efb0  33f6                 xor esi, esi
// 0051efb2  eb2b                 jmp 0x51efdf
// 0051efb4  8b4804               mov ecx, dword ptr [eax + 4]
// 0051efb7  8b5008               mov edx, dword ptr [eax + 8]
// 0051efba  895108               mov dword ptr [ecx + 8], edx
// 0051efbd  8b4808               mov ecx, dword ptr [eax + 8]
// 0051efc0  8b5004               mov edx, dword ptr [eax + 4]
// 0051efc3  895104               mov dword ptr [ecx + 4], edx
// 0051efc6  8b7808               mov edi, dword ptr [eax + 8]
// 0051efc9  3bc3                 cmp eax, ebx
// 0051efcb  7506                 jne 0x51efd3
// 0051efcd  8bdf                 mov ebx, edi
// 0051efcf  895c2414             mov dword ptr [esp + 0x14], ebx
// 0051efd3  50                   push eax
// 0051efd4  e87fb02e00           call 0x80a058
// 0051efd9  83c404               add esp, 4
// 0051efdc  8bc7                 mov eax, edi
// 0051efde  4e                   dec esi
// 0051efdf  89742410             mov dword ptr [esp + 0x10], esi
// 0051efe3  89442418             mov dword ptr [esp + 0x18], eax
// 0051efe7  8b38                 mov edi, dword ptr [eax]
// 0051efe9  85f6                 test esi, esi
// 0051efeb  744d                 je 0x51f03a
// 0051efed  83fe01               cmp esi, 1
// 0051eff0  7515                 jne 0x51f007
// 0051eff2  53                   push ebx
// 0051eff3  e860b02e00           call 0x80a058
// 0051eff8  83c404               add esp, 4
// 0051effb  33f6                 xor esi, esi
// 0051effd  89742418             mov dword ptr [esp + 0x18], esi
// 0051f001  89742414             mov dword ptr [esp + 0x14], esi
// 0051f005  eb2f                 jmp 0x51f036
// 0051f007  8b4804               mov ecx, dword ptr [eax + 4]
// 0051f00a  8b5008               mov edx, dword ptr [eax + 8]
// 0051f00d  895108               mov dword ptr [ecx + 8], edx
// 0051f010  8b4808               mov ecx, dword ptr [eax + 8]
// 0051f013  8b5004               mov edx, dword ptr [eax + 4]
// 0051f016  895104               mov dword ptr [ecx + 4], edx
// 0051f019  8b6808               mov ebp, dword ptr [eax + 8]
// 0051f01c  3bc3                 cmp eax, ebx
// 0051f01e  7504                 jne 0x51f024
// 0051f020  896c2414             mov dword ptr [esp + 0x14], ebp
// 0051f024  50                   push eax
// 0051f025  e82eb02e00           call 0x80a058
// 0051f02a  83c404               add esp, 4
// 0051f02d  896c2418             mov dword ptr [esp + 0x18], ebp
// 0051f031  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0051f035  4e                   dec esi
// 0051f036  89742410             mov dword ptr [esp + 0x10], esi
// 0051f03a  6a14                 push 0x14
// 0051f03c  e81db02e00           call 0x80a05e
// 0051f041  896808               mov dword ptr [eax + 8], ebp
// 0051f044  89780c               mov dword ptr [eax + 0xc], edi
// 0051f047  8b4f04               mov ecx, dword ptr [edi + 4]
// 0051f04a  034d04               add ecx, dword ptr [ebp + 4]
// 0051f04d  83c404               add esp, 4
// 0051f050  894804               mov dword ptr [eax + 4], ecx
// 0051f053  894510               mov dword ptr [ebp + 0x10], eax
// 0051f056  894710               mov dword ptr [edi + 0x10], eax
// 0051f059  85f6                 test esi, esi
// 0051f05b  7416                 je 0x51f073
// 0051f05d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0051f061  8d542410             lea edx, [esp + 0x10]
// 0051f065  52                   push edx
// 0051f066  50                   push eax
// 0051f067  e8c4fdffff           call 0x51ee30
// 0051f06c  33ff                 xor edi, edi
// 0051f06e  e905ffffff           jmp 0x51ef78
// 0051f073  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0051f077  8907                 mov dword ptr [edi], eax
// 0051f079  8d4c2424             lea ecx, [esp + 0x24]
// 0051f07d  c7401000000000       mov dword ptr [eax + 0x10], 0
// 0051f084  e877d7fcff           call 0x4ec800
// 0051f089  c684244006000001     mov byte ptr [esp + 0x640], 1
// 0051f091  33db                 xor ebx, ebx
// 0051f093  8d6f08               lea ebp, [edi + 8]
// 0051f096  eb08                 jmp 0x51f0a0
// 0051f098  8da42400000000       lea esp, [esp]
// 0051f09f  90                   nop 
// 0051f0a0  8b849c38020000       mov eax, dword ptr [esp + ebx*4 + 0x238]
// 0051f0a7  8b17                 mov edx, dword ptr [edi]
// 0051f0a9  33f6                 xor esi, esi
// 0051f0ab  eb03                 jmp 0x51f0b0
// 0051f0ad  8d4900               lea ecx, [ecx]
// 0051f0b0  8b4810               mov ecx, dword ptr [eax + 0x10]
// 0051f0b3  394108               cmp dword ptr [ecx + 8], eax
// 0051f0b6  0fb7c6               movzx eax, si
// 0051f0b9  750a                 jne 0x51f0c5
// 0051f0bb  c684043801000000     mov byte ptr [esp + eax + 0x138], 0
// 0051f0c3  eb08                 jmp 0x51f0cd
// 0051f0c5  c684043801000001     mov byte ptr [esp + eax + 0x138], 1
// 0051f0cd  8bc1                 mov eax, ecx
// 0051f0cf  46                   inc esi
// 0051f0d0  3bc2                 cmp eax, edx
// 0051f0d2  75dc                 jne 0x51f0b0
// 0051f0d4  6685f6               test si, si
// 0051f0d7  762f                 jbe 0x51f108
// 0051f0d9  0fb7fe               movzx edi, si
// 0051f0dc  8dbc3c38010000       lea edi, [esp + edi + 0x138]
// 0051f0e3  4f                   dec edi
// 0051f0e4  81c6ffff0000         add esi, 0xffff
// 0051f0ea  803f00               cmp byte ptr [edi], 0
// 0051f0ed  8d4c2424             lea ecx, [esp + 0x24]
// 0051f0f1  7407                 je 0x51f0fa
// 0051f0f3  e898defcff           call 0x4ecf90
// 0051f0f8  eb05                 jmp 0x51f0ff
// 0051f0fa  e871defcff           call 0x4ecf70
// 0051f0ff  6685f6               test si, si
// 0051f102  77df                 ja 0x51f0e3
// 0051f104  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0051f108  8d4dfc               lea ecx, [ebp - 4]
// 0051f10b  51                   push ecx
// 0051f10c  8d4c2428             lea ecx, [esp + 0x28]
// 0051f110  e8cbdbfcff           call 0x4ecce0
// 0051f115  660fb6d0             movzx dx, al
// 0051f119  8d4c2424             lea ecx, [esp + 0x24]
// 0051f11d  66895500             mov word ptr [ebp], dx
// 0051f121  e81ad8fcff           call 0x4ec940
// 0051f126  43                   inc ebx
// 0051f127  83c508               add ebp, 8
// 0051f12a  81fb00010000         cmp ebx, 0x100
// 0051f130  0f8c6affffff         jl 0x51f0a0
// 0051f136  8d4c2424             lea ecx, [esp + 0x24]
// 0051f13a  c684244006000000     mov byte ptr [esp + 0x640], 0
// 0051f142  e8c9d7fcff           call 0x4ec910
// 0051f147  8b8c2438060000       mov ecx, dword ptr [esp + 0x638]
// 0051f14e  5f                   pop edi
// 0051f14f  5e                   pop esi
// 0051f150  5d                   pop ebp
// 0051f151  5b                   pop ebx
// 0051f152  64890d00000000       mov dword ptr fs:[0], ecx
// 0051f159  81c434060000         add esp, 0x634
// 0051f15f  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?GenerateFromFrequencyTable@HuffmanEncodingTree@@QAEXQAI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
