// from server: 100% by auto
// roc 2011-06 0052f5b0  unit: RBX::Network::ProfiledRakPeer  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0052f5b0
//
// 0052f5b0  57                   push edi
// 0052f5b1  8bf9                 mov edi, ecx
// 0052f5b3  837f0400             cmp dword ptr [edi + 4], 0
// 0052f5b7  750d                 jne 0x52f5c6
// 0052f5b9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0052f5bd  c60000               mov byte ptr [eax], 0
// 0052f5c0  33c0                 xor eax, eax
// 0052f5c2  5f                   pop edi
// 0052f5c3  c20c00               ret 0xc
// 0052f5c6  8b4704               mov eax, dword ptr [edi + 4]
// 0052f5c9  8b0f                 mov ecx, dword ptr [edi]
// 0052f5cb  53                   push ebx
// 0052f5cc  55                   push ebp
// 0052f5cd  8d68ff               lea ebp, [eax - 1]
// 0052f5d0  99                   cdq 
// 0052f5d1  2bc2                 sub eax, edx
// 0052f5d3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0052f5d7  56                   push esi
// 0052f5d8  8bf0                 mov esi, eax
// 0052f5da  d1fe                 sar esi, 1
// 0052f5dc  8d04f1               lea eax, [ecx + esi*8]
// 0052f5df  50                   push eax
// 0052f5e0  52                   push edx
// 0052f5e1  33db                 xor ebx, ebx
// 0052f5e3  ff542424             call dword ptr [esp + 0x24]
// 0052f5e7  83c408               add esp, 8
// 0052f5ea  85c0                 test eax, eax
// 0052f5ec  7431                 je 0x52f61f
// 0052f5ee  7d05                 jge 0x52f5f5
// 0052f5f0  8d6eff               lea ebp, [esi - 1]
// 0052f5f3  eb03                 jmp 0x52f5f8
// 0052f5f5  8d5e01               lea ebx, [esi + 1]
// 0052f5f8  8bc5                 mov eax, ebp
// 0052f5fa  2bc3                 sub eax, ebx
// 0052f5fc  99                   cdq 
// 0052f5fd  2bc2                 sub eax, edx
// 0052f5ff  8bf0                 mov esi, eax
// 0052f601  d1fe                 sar esi, 1
// 0052f603  03f3                 add esi, ebx
// 0052f605  3bdd                 cmp ebx, ebp
// 0052f607  7f26                 jg 0x52f62f
// 0052f609  8b07                 mov eax, dword ptr [edi]
// 0052f60b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0052f60f  8d04f0               lea eax, [eax + esi*8]
// 0052f612  50                   push eax
// 0052f613  51                   push ecx
// 0052f614  ff542424             call dword ptr [esp + 0x24]
// 0052f618  83c408               add esp, 8
// 0052f61b  85c0                 test eax, eax
// 0052f61d  75cf                 jne 0x52f5ee
// 0052f61f  8b542418             mov edx, dword ptr [esp + 0x18]
// 0052f623  8bc6                 mov eax, esi
// 0052f625  5e                   pop esi
// 0052f626  5d                   pop ebp
// 0052f627  5b                   pop ebx
// 0052f628  c60201               mov byte ptr [edx], 1
// 0052f62b  5f                   pop edi
// 0052f62c  c20c00               ret 0xc
// 0052f62f  8b442418             mov eax, dword ptr [esp + 0x18]
// 0052f633  5e                   pop esi
// 0052f634  5d                   pop ebp
// 0052f635  c60000               mov byte ptr [eax], 0
// 0052f638  8bc3                 mov eax, ebx
// 0052f63a  5b                   pop ebx
// 0052f63b  5f                   pop edi
// 0052f63c  c20c00               ret 0xc
// library openrbx-raknet/StringCompressor.cpp (function ?GetIndexFromKey@?$OrderedList@HUMapNode@?$Map@HPAVHuffmanEncodingTree@@$1??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z@DataStructures@@$1?NodeComparisonFunc@23@SAHABHABU123@@Z@DataStructures@@QBEIABHPA_NP6AH0ABUMapNode@?$Map@HPAVHuffmanEncodingTree@@$1??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z@2@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet StringCompressor.cpp
