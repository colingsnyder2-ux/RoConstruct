// from server: 100% by auto
// roc 2008-06 004cdcc0  unit: RBX::Network::PhysicsSender  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cdcc0
//
// 004cdcc0  8b442408             mov eax, dword ptr [esp + 8]
// 004cdcc4  53                   push ebx
// 004cdcc5  56                   push esi
// 004cdcc6  57                   push edi
// 004cdcc7  8bd9                 mov ebx, ecx
// 004cdcc9  8b33                 mov esi, dword ptr [ebx]
// 004cdccb  33ff                 xor edi, edi
// 004cdccd  85c0                 test eax, eax
// 004cdccf  7646                 jbe 0x4cdd17
// 004cdcd1  55                   push ebp
// 004cdcd2  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004cdcd6  89442418             mov dword ptr [esp + 0x18], eax
// 004cdcda  8d9b00000000         lea ebx, [ebx]
// 004cdce0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004cdce4  e8f774fdff           call 0x4a51e0
// 004cdce9  84c0                 test al, al
// 004cdceb  7505                 jne 0x4cdcf2
// 004cdced  8b7608               mov esi, dword ptr [esi + 8]
// 004cdcf0  eb03                 jmp 0x4cdcf5
// 004cdcf2  8b760c               mov esi, dword ptr [esi + 0xc]
// 004cdcf5  837e0800             cmp dword ptr [esi + 8], 0
// 004cdcf9  7514                 jne 0x4cdd0f
// 004cdcfb  837e0c00             cmp dword ptr [esi + 0xc], 0
// 004cdcff  750e                 jne 0x4cdd0f
// 004cdd01  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 004cdd05  7305                 jae 0x4cdd0c
// 004cdd07  8a06                 mov al, byte ptr [esi]
// 004cdd09  88042f               mov byte ptr [edi + ebp], al
// 004cdd0c  8b33                 mov esi, dword ptr [ebx]
// 004cdd0e  47                   inc edi
// 004cdd0f  836c241801           sub dword ptr [esp + 0x18], 1
// 004cdd14  75ca                 jne 0x4cdce0
// 004cdd16  5d                   pop ebp
// 004cdd17  8bc7                 mov eax, edi
// 004cdd19  5f                   pop edi
// 004cdd1a  5e                   pop esi
// 004cdd1b  5b                   pop ebx
// 004cdd1c  c21000               ret 0x10
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?DecodeArray@HuffmanEncodingTree@@QAEIPAVBitStream@RakNet@@IIPAE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
