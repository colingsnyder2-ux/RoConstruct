// from server: 100% by auto
// roc 2010-06 004fdff0  unit: RBX::Network::IdSerializer  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004fdff0
//
// 004fdff0  57                   push edi
// 004fdff1  8bf9                 mov edi, ecx
// 004fdff3  837f0400             cmp dword ptr [edi + 4], 0
// 004fdff7  750d                 jne 0x4fe006
// 004fdff9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004fdffd  c60000               mov byte ptr [eax], 0
// 004fe000  33c0                 xor eax, eax
// 004fe002  5f                   pop edi
// 004fe003  c20c00               ret 0xc
// 004fe006  8b4704               mov eax, dword ptr [edi + 4]
// 004fe009  8b0f                 mov ecx, dword ptr [edi]
// 004fe00b  53                   push ebx
// 004fe00c  55                   push ebp
// 004fe00d  8d68ff               lea ebp, [eax - 1]
// 004fe010  99                   cdq 
// 004fe011  2bc2                 sub eax, edx
// 004fe013  8b542410             mov edx, dword ptr [esp + 0x10]
// 004fe017  56                   push esi
// 004fe018  8bf0                 mov esi, eax
// 004fe01a  d1fe                 sar esi, 1
// 004fe01c  8d04f1               lea eax, [ecx + esi*8]
// 004fe01f  50                   push eax
// 004fe020  52                   push edx
// 004fe021  33db                 xor ebx, ebx
// 004fe023  ff542424             call dword ptr [esp + 0x24]
// 004fe027  83c408               add esp, 8
// 004fe02a  85c0                 test eax, eax
// 004fe02c  7431                 je 0x4fe05f
// 004fe02e  7d05                 jge 0x4fe035
// 004fe030  8d6eff               lea ebp, [esi - 1]
// 004fe033  eb03                 jmp 0x4fe038
// 004fe035  8d5e01               lea ebx, [esi + 1]
// 004fe038  8bc5                 mov eax, ebp
// 004fe03a  2bc3                 sub eax, ebx
// 004fe03c  99                   cdq 
// 004fe03d  2bc2                 sub eax, edx
// 004fe03f  8bf0                 mov esi, eax
// 004fe041  d1fe                 sar esi, 1
// 004fe043  03f3                 add esi, ebx
// 004fe045  3bdd                 cmp ebx, ebp
// 004fe047  7f26                 jg 0x4fe06f
// 004fe049  8b07                 mov eax, dword ptr [edi]
// 004fe04b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004fe04f  8d04f0               lea eax, [eax + esi*8]
// 004fe052  50                   push eax
// 004fe053  51                   push ecx
// 004fe054  ff542424             call dword ptr [esp + 0x24]
// 004fe058  83c408               add esp, 8
// 004fe05b  85c0                 test eax, eax
// 004fe05d  75cf                 jne 0x4fe02e
// 004fe05f  8b542418             mov edx, dword ptr [esp + 0x18]
// 004fe063  8bc6                 mov eax, esi
// 004fe065  5e                   pop esi
// 004fe066  5d                   pop ebp
// 004fe067  5b                   pop ebx
// 004fe068  c60201               mov byte ptr [edx], 1
// 004fe06b  5f                   pop edi
// 004fe06c  c20c00               ret 0xc
// 004fe06f  8b442418             mov eax, dword ptr [esp + 0x18]
// 004fe073  5e                   pop esi
// 004fe074  5d                   pop ebp
// 004fe075  c60000               mov byte ptr [eax], 0
// 004fe078  8bc3                 mov eax, ebx
// 004fe07a  5b                   pop ebx
// 004fe07b  5f                   pop edi
// 004fe07c  c20c00               ret 0xc
// library openrbx-raknet/StringCompressor.cpp (function ?GetIndexFromKey@?$OrderedList@HUMapNode@?$Map@HPAVHuffmanEncodingTree@@$1??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z@DataStructures@@$1?NodeComparisonFunc@23@SAHABHABU123@@Z@DataStructures@@QBEIABHPA_NP6AH0ABUMapNode@?$Map@HPAVHuffmanEncodingTree@@$1??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z@2@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet StringCompressor.cpp
