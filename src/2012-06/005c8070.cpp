// roc 2012-06 005c8070  unit: RakNet::RakPeer  size: 642 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c8070
//
// 005c8070  6aff                 push -1
// 005c8072  68762fab00           push 0xab2f76
// 005c8077  64a100000000         mov eax, dword ptr fs:[0]
// 005c807d  50                   push eax
// 005c807e  64892500000000       mov dword ptr fs:[0], esp
// 005c8085  81ec28060000         sub esp, 0x628
// 005c808b  53                   push ebx
// 005c808c  55                   push ebp
// 005c808d  56                   push esi
// 005c808e  57                   push edi
// 005c808f  33ff                 xor edi, edi
// 005c8091  8be9                 mov ebp, ecx
// 005c8093  896c241c             mov dword ptr [esp + 0x1c], ebp
// 005c8097  897c2414             mov dword ptr [esp + 0x14], edi
// 005c809b  897c2418             mov dword ptr [esp + 0x18], edi
// 005c809f  897c2410             mov dword ptr [esp + 0x10], edi
// 005c80a3  89bc2440060000       mov dword ptr [esp + 0x640], edi
// 005c80aa  e8c1fdffff           call 0x5c7e70
// 005c80af  8bb42448060000       mov esi, dword ptr [esp + 0x648]
// 005c80b6  8d842438020000       lea eax, [esp + 0x238]
// 005c80bd  33db                 xor ebx, ebx
// 005c80bf  2bf0                 sub esi, eax
// 005c80c1  6a14                 push 0x14
// 005c80c3  e852a03b00           call 0x98211a
// 005c80c8  8d0c9e               lea ecx, [esi + ebx*4]
// 005c80cb  897808               mov dword ptr [eax + 8], edi
// 005c80ce  89780c               mov dword ptr [eax + 0xc], edi
// 005c80d1  8818                 mov byte ptr [eax], bl
// 005c80d3  8b8c0c3c020000       mov ecx, dword ptr [esp + ecx + 0x23c]
// 005c80da  83c404               add esp, 4
// 005c80dd  894804               mov dword ptr [eax + 4], ecx
// 005c80e0  3bcf                 cmp ecx, edi
// 005c80e2  7507                 jne 0x5c80eb
// 005c80e4  c7400401000000       mov dword ptr [eax + 4], 1
// 005c80eb  8d542410             lea edx, [esp + 0x10]
// 005c80ef  52                   push edx
// 005c80f0  50                   push eax
// 005c80f1  8bcd                 mov ecx, ebp
// 005c80f3  89849c40020000       mov dword ptr [esp + ebx*4 + 0x240], eax
// 005c80fa  e8c1feffff           call 0x5c7fc0
// 005c80ff  43                   inc ebx
// 005c8100  81fb00010000         cmp ebx, 0x100
// 005c8106  7cb9                 jl 0x5c80c1
// 005c8108  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005c810c  3bdf                 cmp ebx, edi
// 005c810e  7408                 je 0x5c8118
// 005c8110  8bc3                 mov eax, ebx
// 005c8112  89442418             mov dword ptr [esp + 0x18], eax
// 005c8116  eb04                 jmp 0x5c811c
// 005c8118  8b442418             mov eax, dword ptr [esp + 0x18]
// 005c811c  8b742410             mov esi, dword ptr [esp + 0x10]
// 005c8120  8b28                 mov ebp, dword ptr [eax]
// 005c8122  896c2420             mov dword ptr [esp + 0x20], ebp
// 005c8126  3bf7                 cmp esi, edi
// 005c8128  744d                 je 0x5c8177
// 005c812a  83fe01               cmp esi, 1
// 005c812d  7515                 jne 0x5c8144
// 005c812f  53                   push ebx
// 005c8130  e8df9f3b00           call 0x982114
// 005c8135  33db                 xor ebx, ebx
// 005c8137  83c404               add esp, 4
// 005c813a  33c0                 xor eax, eax
// 005c813c  895c2414             mov dword ptr [esp + 0x14], ebx
// 005c8140  33f6                 xor esi, esi
// 005c8142  eb2b                 jmp 0x5c816f
// 005c8144  8b4804               mov ecx, dword ptr [eax + 4]
// 005c8147  8b5008               mov edx, dword ptr [eax + 8]
// 005c814a  895108               mov dword ptr [ecx + 8], edx
// 005c814d  8b4808               mov ecx, dword ptr [eax + 8]
// 005c8150  8b5004               mov edx, dword ptr [eax + 4]
// 005c8153  895104               mov dword ptr [ecx + 4], edx
// 005c8156  8b7808               mov edi, dword ptr [eax + 8]
// 005c8159  3bc3                 cmp eax, ebx
// 005c815b  7506                 jne 0x5c8163
// 005c815d  8bdf                 mov ebx, edi
// 005c815f  895c2414             mov dword ptr [esp + 0x14], ebx
// 005c8163  50                   push eax
// 005c8164  e8ab9f3b00           call 0x982114
// 005c8169  83c404               add esp, 4
// 005c816c  8bc7                 mov eax, edi
// 005c816e  4e                   dec esi
// 005c816f  89742410             mov dword ptr [esp + 0x10], esi
// 005c8173  89442418             mov dword ptr [esp + 0x18], eax
// 005c8177  8b38                 mov edi, dword ptr [eax]
// 005c8179  85f6                 test esi, esi
// 005c817b  744d                 je 0x5c81ca
// 005c817d  83fe01               cmp esi, 1
// 005c8180  7515                 jne 0x5c8197
// 005c8182  53                   push ebx
// 005c8183  e88c9f3b00           call 0x982114
// 005c8188  83c404               add esp, 4
// 005c818b  33f6                 xor esi, esi
// 005c818d  89742418             mov dword ptr [esp + 0x18], esi
// 005c8191  89742414             mov dword ptr [esp + 0x14], esi
// 005c8195  eb2f                 jmp 0x5c81c6
// 005c8197  8b4804               mov ecx, dword ptr [eax + 4]
// 005c819a  8b5008               mov edx, dword ptr [eax + 8]
// 005c819d  895108               mov dword ptr [ecx + 8], edx
// 005c81a0  8b4808               mov ecx, dword ptr [eax + 8]
// 005c81a3  8b5004               mov edx, dword ptr [eax + 4]
// 005c81a6  895104               mov dword ptr [ecx + 4], edx
// 005c81a9  8b6808               mov ebp, dword ptr [eax + 8]
// 005c81ac  3bc3                 cmp eax, ebx
// 005c81ae  7504                 jne 0x5c81b4
// 005c81b0  896c2414             mov dword ptr [esp + 0x14], ebp
// 005c81b4  50                   push eax
// 005c81b5  e85a9f3b00           call 0x982114
// 005c81ba  83c404               add esp, 4
// 005c81bd  896c2418             mov dword ptr [esp + 0x18], ebp
// 005c81c1  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005c81c5  4e                   dec esi
// 005c81c6  89742410             mov dword ptr [esp + 0x10], esi
// 005c81ca  6a14                 push 0x14
// 005c81cc  e8499f3b00           call 0x98211a
// 005c81d1  896808               mov dword ptr [eax + 8], ebp
// 005c81d4  89780c               mov dword ptr [eax + 0xc], edi
// 005c81d7  8b4f04               mov ecx, dword ptr [edi + 4]
// 005c81da  034d04               add ecx, dword ptr [ebp + 4]
// 005c81dd  83c404               add esp, 4
// 005c81e0  894804               mov dword ptr [eax + 4], ecx
// 005c81e3  894510               mov dword ptr [ebp + 0x10], eax
// 005c81e6  894710               mov dword ptr [edi + 0x10], eax
// 005c81e9  85f6                 test esi, esi
// 005c81eb  7416                 je 0x5c8203
// 005c81ed  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005c81f1  8d542410             lea edx, [esp + 0x10]
// 005c81f5  52                   push edx
// 005c81f6  50                   push eax
// 005c81f7  e8c4fdffff           call 0x5c7fc0
// 005c81fc  33ff                 xor edi, edi
// 005c81fe  e905ffffff           jmp 0x5c8108
// 005c8203  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005c8207  8907                 mov dword ptr [edi], eax
// 005c8209  8d4c2424             lea ecx, [esp + 0x24]
// 005c820d  c7401000000000       mov dword ptr [eax + 0x10], 0
// 005c8214  e887f3f9ff           call 0x5675a0
// 005c8219  c684244006000001     mov byte ptr [esp + 0x640], 1
// 005c8221  33db                 xor ebx, ebx
// 005c8223  8d6f08               lea ebp, [edi + 8]
// 005c8226  eb08                 jmp 0x5c8230
// 005c8228  8da42400000000       lea esp, [esp]
// 005c822f  90                   nop 
// 005c8230  8b849c38020000       mov eax, dword ptr [esp + ebx*4 + 0x238]
// 005c8237  8b17                 mov edx, dword ptr [edi]
// 005c8239  33f6                 xor esi, esi
// 005c823b  eb03                 jmp 0x5c8240
// 005c823d  8d4900               lea ecx, [ecx]
// 005c8240  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005c8243  394108               cmp dword ptr [ecx + 8], eax
// 005c8246  0fb7c6               movzx eax, si
// 005c8249  750a                 jne 0x5c8255
// 005c824b  c684043801000000     mov byte ptr [esp + eax + 0x138], 0
// 005c8253  eb08                 jmp 0x5c825d
// 005c8255  c684043801000001     mov byte ptr [esp + eax + 0x138], 1
// 005c825d  8bc1                 mov eax, ecx
// 005c825f  46                   inc esi
// 005c8260  3bc2                 cmp eax, edx
// 005c8262  75dc                 jne 0x5c8240
// 005c8264  6685f6               test si, si
// 005c8267  762f                 jbe 0x5c8298
// 005c8269  0fb7fe               movzx edi, si
// 005c826c  8dbc3c38010000       lea edi, [esp + edi + 0x138]
// 005c8273  4f                   dec edi
// 005c8274  81c6ffff0000         add esi, 0xffff
// 005c827a  803f00               cmp byte ptr [edi], 0
// 005c827d  8d4c2424             lea ecx, [esp + 0x24]
// 005c8281  7407                 je 0x5c828a
// 005c8283  e8c8faf9ff           call 0x567d50
// 005c8288  eb05                 jmp 0x5c828f
// 005c828a  e8a1faf9ff           call 0x567d30
// 005c828f  6685f6               test si, si
// 005c8292  77df                 ja 0x5c8273
// 005c8294  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005c8298  8d4dfc               lea ecx, [ebp - 4]
// 005c829b  51                   push ecx
// 005c829c  8d4c2428             lea ecx, [esp + 0x28]
// 005c82a0  e8dbf7f9ff           call 0x567a80
// 005c82a5  660fb6d0             movzx dx, al
// 005c82a9  8d4c2424             lea ecx, [esp + 0x24]
// 005c82ad  66895500             mov word ptr [ebp], dx
// 005c82b1  e82af4f9ff           call 0x5676e0
// 005c82b6  43                   inc ebx
// 005c82b7  83c508               add ebp, 8
// 005c82ba  81fb00010000         cmp ebx, 0x100
// 005c82c0  0f8c6affffff         jl 0x5c8230
// 005c82c6  8d4c2424             lea ecx, [esp + 0x24]
// 005c82ca  c684244006000000     mov byte ptr [esp + 0x640], 0
// 005c82d2  e8d9f3f9ff           call 0x5676b0
// 005c82d7  8b8c2438060000       mov ecx, dword ptr [esp + 0x638]
// 005c82de  5f                   pop edi
// 005c82df  5e                   pop esi
// 005c82e0  5d                   pop ebp
// 005c82e1  5b                   pop ebx
// 005c82e2  64890d00000000       mov dword ptr fs:[0], ecx
// 005c82e9  81c434060000         add esp, 0x634
// 005c82ef  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?GenerateFromFrequencyTable@HuffmanEncodingTree@@QAEXQAI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
