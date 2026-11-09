// from server: 100% by auto
// roc 2009-12 00564d40  unit: CXTPRichRender::XTextHost  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00564d40
//
// 00564d40  8b442408             mov eax, dword ptr [esp + 8]
// 00564d44  53                   push ebx
// 00564d45  56                   push esi
// 00564d46  57                   push edi
// 00564d47  8bd9                 mov ebx, ecx
// 00564d49  8b33                 mov esi, dword ptr [ebx]
// 00564d4b  33ff                 xor edi, edi
// 00564d4d  85c0                 test eax, eax
// 00564d4f  7646                 jbe 0x564d97
// 00564d51  55                   push ebp
// 00564d52  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00564d56  89442418             mov dword ptr [esp + 0x18], eax
// 00564d5a  8d9b00000000         lea ebx, [ebx]
// 00564d60  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00564d64  e8f79dfcff           call 0x52eb60
// 00564d69  84c0                 test al, al
// 00564d6b  7505                 jne 0x564d72
// 00564d6d  8b7608               mov esi, dword ptr [esi + 8]
// 00564d70  eb03                 jmp 0x564d75
// 00564d72  8b760c               mov esi, dword ptr [esi + 0xc]
// 00564d75  837e0800             cmp dword ptr [esi + 8], 0
// 00564d79  7514                 jne 0x564d8f
// 00564d7b  837e0c00             cmp dword ptr [esi + 0xc], 0
// 00564d7f  750e                 jne 0x564d8f
// 00564d81  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 00564d85  7305                 jae 0x564d8c
// 00564d87  8a06                 mov al, byte ptr [esi]
// 00564d89  88042f               mov byte ptr [edi + ebp], al
// 00564d8c  8b33                 mov esi, dword ptr [ebx]
// 00564d8e  47                   inc edi
// 00564d8f  836c241801           sub dword ptr [esp + 0x18], 1
// 00564d94  75ca                 jne 0x564d60
// 00564d96  5d                   pop ebp
// 00564d97  8bc7                 mov eax, edi
// 00564d99  5f                   pop edi
// 00564d9a  5e                   pop esi
// 00564d9b  5b                   pop ebx
// 00564d9c  c21000               ret 0x10
// library raknet-4.081/DS_HuffmanEncodingTree.cpp (function ?DecodeArray@HuffmanEncodingTree@RakNet@@QAEIPAVBitStream@2@IIPAE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DS_HuffmanEncodingTree.cpp
