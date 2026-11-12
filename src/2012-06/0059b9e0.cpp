// roc 2012-06 0059b9e0  unit: VAuthoringSettings::?$FactoryProduct  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059b9e0
//
// 0059b9e0  57                   push edi
// 0059b9e1  8bf9                 mov edi, ecx
// 0059b9e3  837f0400             cmp dword ptr [edi + 4], 0
// 0059b9e7  750d                 jne 0x59b9f6
// 0059b9e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0059b9ed  c60000               mov byte ptr [eax], 0
// 0059b9f0  33c0                 xor eax, eax
// 0059b9f2  5f                   pop edi
// 0059b9f3  c20c00               ret 0xc
// 0059b9f6  8b4704               mov eax, dword ptr [edi + 4]
// 0059b9f9  8b0f                 mov ecx, dword ptr [edi]
// 0059b9fb  53                   push ebx
// 0059b9fc  55                   push ebp
// 0059b9fd  8d68ff               lea ebp, [eax - 1]
// 0059ba00  99                   cdq 
// 0059ba01  2bc2                 sub eax, edx
// 0059ba03  8b542410             mov edx, dword ptr [esp + 0x10]
// 0059ba07  56                   push esi
// 0059ba08  8bf0                 mov esi, eax
// 0059ba0a  d1fe                 sar esi, 1
// 0059ba0c  8d04f1               lea eax, [ecx + esi*8]
// 0059ba0f  50                   push eax
// 0059ba10  52                   push edx
// 0059ba11  33db                 xor ebx, ebx
// 0059ba13  ff542424             call dword ptr [esp + 0x24]
// 0059ba17  83c408               add esp, 8
// 0059ba1a  85c0                 test eax, eax
// 0059ba1c  7431                 je 0x59ba4f
// 0059ba1e  7d05                 jge 0x59ba25
// 0059ba20  8d6eff               lea ebp, [esi - 1]
// 0059ba23  eb03                 jmp 0x59ba28
// 0059ba25  8d5e01               lea ebx, [esi + 1]
// 0059ba28  8bc5                 mov eax, ebp
// 0059ba2a  2bc3                 sub eax, ebx
// 0059ba2c  99                   cdq 
// 0059ba2d  2bc2                 sub eax, edx
// 0059ba2f  8bf0                 mov esi, eax
// 0059ba31  d1fe                 sar esi, 1
// 0059ba33  03f3                 add esi, ebx
// 0059ba35  3bdd                 cmp ebx, ebp
// 0059ba37  7f26                 jg 0x59ba5f
// 0059ba39  8b07                 mov eax, dword ptr [edi]
// 0059ba3b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0059ba3f  8d04f0               lea eax, [eax + esi*8]
// 0059ba42  50                   push eax
// 0059ba43  51                   push ecx
// 0059ba44  ff542424             call dword ptr [esp + 0x24]
// 0059ba48  83c408               add esp, 8
// 0059ba4b  85c0                 test eax, eax
// 0059ba4d  75cf                 jne 0x59ba1e
// 0059ba4f  8b542418             mov edx, dword ptr [esp + 0x18]
// 0059ba53  8bc6                 mov eax, esi
// 0059ba55  5e                   pop esi
// 0059ba56  5d                   pop ebp
// 0059ba57  5b                   pop ebx
// 0059ba58  c60201               mov byte ptr [edx], 1
// 0059ba5b  5f                   pop edi
// 0059ba5c  c20c00               ret 0xc
// 0059ba5f  8b442418             mov eax, dword ptr [esp + 0x18]
// 0059ba63  5e                   pop esi
// 0059ba64  5d                   pop ebp
// 0059ba65  c60000               mov byte ptr [eax], 0
// 0059ba68  8bc3                 mov eax, ebx
// 0059ba6a  5b                   pop ebx
// 0059ba6b  5f                   pop edi
// 0059ba6c  c20c00               ret 0xc
// library openrbx-raknet/StringCompressor.cpp (function ?GetIndexFromKey@?$OrderedList@HUMapNode@?$Map@HPAVHuffmanEncodingTree@@$1??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z@DataStructures@@$1?NodeComparisonFunc@23@SAHABHABU123@@Z@DataStructures@@QBEIABHPA_NP6AH0ABUMapNode@?$Map@HPAVHuffmanEncodingTree@@$1??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z@2@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet StringCompressor.cpp
