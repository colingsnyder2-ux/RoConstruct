// from server: 100% by auto
// roc 2009-06 004fd680  unit: RBX::Network::NetworkOwnerJob  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fd680
//
// 004fd680  8b442408             mov eax, dword ptr [esp + 8]
// 004fd684  53                   push ebx
// 004fd685  56                   push esi
// 004fd686  57                   push edi
// 004fd687  8bd9                 mov ebx, ecx
// 004fd689  8b33                 mov esi, dword ptr [ebx]
// 004fd68b  33ff                 xor edi, edi
// 004fd68d  85c0                 test eax, eax
// 004fd68f  7646                 jbe 0x4fd6d7
// 004fd691  55                   push ebp
// 004fd692  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004fd696  89442418             mov dword ptr [esp + 0x18], eax
// 004fd69a  8d9b00000000         lea ebx, [ebx]
// 004fd6a0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004fd6a4  e8b7c0fdff           call 0x4d9760
// 004fd6a9  84c0                 test al, al
// 004fd6ab  7505                 jne 0x4fd6b2
// 004fd6ad  8b7608               mov esi, dword ptr [esi + 8]
// 004fd6b0  eb03                 jmp 0x4fd6b5
// 004fd6b2  8b760c               mov esi, dword ptr [esi + 0xc]
// 004fd6b5  837e0800             cmp dword ptr [esi + 8], 0
// 004fd6b9  7514                 jne 0x4fd6cf
// 004fd6bb  837e0c00             cmp dword ptr [esi + 0xc], 0
// 004fd6bf  750e                 jne 0x4fd6cf
// 004fd6c1  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 004fd6c5  7305                 jae 0x4fd6cc
// 004fd6c7  8a06                 mov al, byte ptr [esi]
// 004fd6c9  88042f               mov byte ptr [edi + ebp], al
// 004fd6cc  8b33                 mov esi, dword ptr [ebx]
// 004fd6ce  47                   inc edi
// 004fd6cf  836c241801           sub dword ptr [esp + 0x18], 1
// 004fd6d4  75ca                 jne 0x4fd6a0
// 004fd6d6  5d                   pop ebp
// 004fd6d7  8bc7                 mov eax, edi
// 004fd6d9  5f                   pop edi
// 004fd6da  5e                   pop esi
// 004fd6db  5b                   pop ebx
// 004fd6dc  c21000               ret 0x10
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?DecodeArray@HuffmanEncodingTree@@QAEIPAVBitStream@RakNet@@IIPAE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
