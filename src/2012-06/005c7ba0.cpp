// roc 2012-06 005c7ba0  unit: RakNet::RakPeer  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c7ba0
//
// 005c7ba0  8b442408             mov eax, dword ptr [esp + 8]
// 005c7ba4  53                   push ebx
// 005c7ba5  56                   push esi
// 005c7ba6  57                   push edi
// 005c7ba7  8bd9                 mov ebx, ecx
// 005c7ba9  8b33                 mov esi, dword ptr [ebx]
// 005c7bab  33ff                 xor edi, edi
// 005c7bad  85c0                 test eax, eax
// 005c7baf  7646                 jbe 0x5c7bf7
// 005c7bb1  55                   push ebp
// 005c7bb2  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005c7bb6  89442418             mov dword ptr [esp + 0x18], eax
// 005c7bba  8d9b00000000         lea ebx, [ebx]
// 005c7bc0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005c7bc4  e827fbf9ff           call 0x5676f0
// 005c7bc9  84c0                 test al, al
// 005c7bcb  7505                 jne 0x5c7bd2
// 005c7bcd  8b7608               mov esi, dword ptr [esi + 8]
// 005c7bd0  eb03                 jmp 0x5c7bd5
// 005c7bd2  8b760c               mov esi, dword ptr [esi + 0xc]
// 005c7bd5  837e0800             cmp dword ptr [esi + 8], 0
// 005c7bd9  7514                 jne 0x5c7bef
// 005c7bdb  837e0c00             cmp dword ptr [esi + 0xc], 0
// 005c7bdf  750e                 jne 0x5c7bef
// 005c7be1  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 005c7be5  7305                 jae 0x5c7bec
// 005c7be7  8a06                 mov al, byte ptr [esi]
// 005c7be9  88042f               mov byte ptr [edi + ebp], al
// 005c7bec  8b33                 mov esi, dword ptr [ebx]
// 005c7bee  47                   inc edi
// 005c7bef  836c241801           sub dword ptr [esp + 0x18], 1
// 005c7bf4  75ca                 jne 0x5c7bc0
// 005c7bf6  5d                   pop ebp
// 005c7bf7  8bc7                 mov eax, edi
// 005c7bf9  5f                   pop edi
// 005c7bfa  5e                   pop esi
// 005c7bfb  5b                   pop ebx
// 005c7bfc  c21000               ret 0x10
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?DecodeArray@HuffmanEncodingTree@@QAEIPAVBitStream@RakNet@@IIPAE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
