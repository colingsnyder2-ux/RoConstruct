// from server: 100% by auto
// roc 2010-06 00513780  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00513780
//
// 00513780  8b442408             mov eax, dword ptr [esp + 8]
// 00513784  53                   push ebx
// 00513785  56                   push esi
// 00513786  57                   push edi
// 00513787  8bd9                 mov ebx, ecx
// 00513789  8b33                 mov esi, dword ptr [ebx]
// 0051378b  33ff                 xor edi, edi
// 0051378d  85c0                 test eax, eax
// 0051378f  7646                 jbe 0x5137d7
// 00513791  55                   push ebp
// 00513792  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00513796  89442418             mov dword ptr [esp + 0x18], eax
// 0051379a  8d9b00000000         lea ebx, [ebx]
// 005137a0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005137a4  e8c797fcff           call 0x4dcf70
// 005137a9  84c0                 test al, al
// 005137ab  7505                 jne 0x5137b2
// 005137ad  8b7608               mov esi, dword ptr [esi + 8]
// 005137b0  eb03                 jmp 0x5137b5
// 005137b2  8b760c               mov esi, dword ptr [esi + 0xc]
// 005137b5  837e0800             cmp dword ptr [esi + 8], 0
// 005137b9  7514                 jne 0x5137cf
// 005137bb  837e0c00             cmp dword ptr [esi + 0xc], 0
// 005137bf  750e                 jne 0x5137cf
// 005137c1  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 005137c5  7305                 jae 0x5137cc
// 005137c7  8a06                 mov al, byte ptr [esi]
// 005137c9  88042f               mov byte ptr [edi + ebp], al
// 005137cc  8b33                 mov esi, dword ptr [ebx]
// 005137ce  47                   inc edi
// 005137cf  836c241801           sub dword ptr [esp + 0x18], 1
// 005137d4  75ca                 jne 0x5137a0
// 005137d6  5d                   pop ebp
// 005137d7  8bc7                 mov eax, edi
// 005137d9  5f                   pop edi
// 005137da  5e                   pop esi
// 005137db  5b                   pop ebx
// 005137dc  c21000               ret 0x10
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?DecodeArray@HuffmanEncodingTree@@QAEIPAVBitStream@RakNet@@IIPAE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
