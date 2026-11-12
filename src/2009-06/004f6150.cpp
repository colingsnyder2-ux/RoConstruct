// from server: 100% by auto
// roc 2009-06 004f6150  unit: RBX::Network::ClientReplicator  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f6150
//
// 004f6150  57                   push edi
// 004f6151  8bf9                 mov edi, ecx
// 004f6153  837f0400             cmp dword ptr [edi + 4], 0
// 004f6157  750d                 jne 0x4f6166
// 004f6159  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004f615d  c60000               mov byte ptr [eax], 0
// 004f6160  33c0                 xor eax, eax
// 004f6162  5f                   pop edi
// 004f6163  c20c00               ret 0xc
// 004f6166  8b4704               mov eax, dword ptr [edi + 4]
// 004f6169  8b0f                 mov ecx, dword ptr [edi]
// 004f616b  53                   push ebx
// 004f616c  55                   push ebp
// 004f616d  8d68ff               lea ebp, [eax - 1]
// 004f6170  99                   cdq 
// 004f6171  2bc2                 sub eax, edx
// 004f6173  8b542410             mov edx, dword ptr [esp + 0x10]
// 004f6177  56                   push esi
// 004f6178  8bf0                 mov esi, eax
// 004f617a  d1fe                 sar esi, 1
// 004f617c  8d04f1               lea eax, [ecx + esi*8]
// 004f617f  50                   push eax
// 004f6180  52                   push edx
// 004f6181  33db                 xor ebx, ebx
// 004f6183  ff542424             call dword ptr [esp + 0x24]
// 004f6187  83c408               add esp, 8
// 004f618a  85c0                 test eax, eax
// 004f618c  7431                 je 0x4f61bf
// 004f618e  7d05                 jge 0x4f6195
// 004f6190  8d6eff               lea ebp, [esi - 1]
// 004f6193  eb03                 jmp 0x4f6198
// 004f6195  8d5e01               lea ebx, [esi + 1]
// 004f6198  8bc5                 mov eax, ebp
// 004f619a  2bc3                 sub eax, ebx
// 004f619c  99                   cdq 
// 004f619d  2bc2                 sub eax, edx
// 004f619f  8bf0                 mov esi, eax
// 004f61a1  d1fe                 sar esi, 1
// 004f61a3  03f3                 add esi, ebx
// 004f61a5  3bdd                 cmp ebx, ebp
// 004f61a7  7f26                 jg 0x4f61cf
// 004f61a9  8b07                 mov eax, dword ptr [edi]
// 004f61ab  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004f61af  8d04f0               lea eax, [eax + esi*8]
// 004f61b2  50                   push eax
// 004f61b3  51                   push ecx
// 004f61b4  ff542424             call dword ptr [esp + 0x24]
// 004f61b8  83c408               add esp, 8
// 004f61bb  85c0                 test eax, eax
// 004f61bd  75cf                 jne 0x4f618e
// 004f61bf  8b542418             mov edx, dword ptr [esp + 0x18]
// 004f61c3  8bc6                 mov eax, esi
// 004f61c5  5e                   pop esi
// 004f61c6  5d                   pop ebp
// 004f61c7  5b                   pop ebx
// 004f61c8  c60201               mov byte ptr [edx], 1
// 004f61cb  5f                   pop edi
// 004f61cc  c20c00               ret 0xc
// 004f61cf  8b442418             mov eax, dword ptr [esp + 0x18]
// 004f61d3  5e                   pop esi
// 004f61d4  5d                   pop ebp
// 004f61d5  c60000               mov byte ptr [eax], 0
// 004f61d8  8bc3                 mov eax, ebx
// 004f61da  5b                   pop ebx
// 004f61db  5f                   pop edi
// 004f61dc  c20c00               ret 0xc
// library openrbx-raknet/StringCompressor.cpp (function ?GetIndexFromKey@?$OrderedList@HUMapNode@?$Map@HPAVHuffmanEncodingTree@@$1??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z@DataStructures@@$1?NodeComparisonFunc@23@SAHABHABU123@@Z@DataStructures@@QBEIABHPA_NP6AH0ABUMapNode@?$Map@HPAVHuffmanEncodingTree@@$1??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z@2@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet StringCompressor.cpp
