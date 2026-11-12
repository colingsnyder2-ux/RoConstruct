// from server: 100% by auto
// roc 2011-06 0051ea00  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0051ea00
//
// 0051ea00  8b442408             mov eax, dword ptr [esp + 8]
// 0051ea04  53                   push ebx
// 0051ea05  56                   push esi
// 0051ea06  57                   push edi
// 0051ea07  8bd9                 mov ebx, ecx
// 0051ea09  8b33                 mov esi, dword ptr [ebx]
// 0051ea0b  33ff                 xor edi, edi
// 0051ea0d  85c0                 test eax, eax
// 0051ea0f  7646                 jbe 0x51ea57
// 0051ea11  55                   push ebp
// 0051ea12  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0051ea16  89442418             mov dword ptr [esp + 0x18], eax
// 0051ea1a  8d9b00000000         lea ebx, [ebx]
// 0051ea20  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0051ea24  e827dffcff           call 0x4ec950
// 0051ea29  84c0                 test al, al
// 0051ea2b  7505                 jne 0x51ea32
// 0051ea2d  8b7608               mov esi, dword ptr [esi + 8]
// 0051ea30  eb03                 jmp 0x51ea35
// 0051ea32  8b760c               mov esi, dword ptr [esi + 0xc]
// 0051ea35  837e0800             cmp dword ptr [esi + 8], 0
// 0051ea39  7514                 jne 0x51ea4f
// 0051ea3b  837e0c00             cmp dword ptr [esi + 0xc], 0
// 0051ea3f  750e                 jne 0x51ea4f
// 0051ea41  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 0051ea45  7305                 jae 0x51ea4c
// 0051ea47  8a06                 mov al, byte ptr [esi]
// 0051ea49  88042f               mov byte ptr [edi + ebp], al
// 0051ea4c  8b33                 mov esi, dword ptr [ebx]
// 0051ea4e  47                   inc edi
// 0051ea4f  836c241801           sub dword ptr [esp + 0x18], 1
// 0051ea54  75ca                 jne 0x51ea20
// 0051ea56  5d                   pop ebp
// 0051ea57  8bc7                 mov eax, edi
// 0051ea59  5f                   pop edi
// 0051ea5a  5e                   pop esi
// 0051ea5b  5b                   pop ebx
// 0051ea5c  c21000               ret 0x10
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?DecodeArray@HuffmanEncodingTree@@QAEIPAVBitStream@RakNet@@IIPAE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
