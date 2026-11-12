// from server: 100% by auto
// roc 2008-06 004cfa70  unit: RBX::Network::PhysicsSender  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cfa70
//
// 004cfa70  57                   push edi
// 004cfa71  8bf9                 mov edi, ecx
// 004cfa73  837f0400             cmp dword ptr [edi + 4], 0
// 004cfa77  750d                 jne 0x4cfa86
// 004cfa79  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004cfa7d  c60000               mov byte ptr [eax], 0
// 004cfa80  33c0                 xor eax, eax
// 004cfa82  5f                   pop edi
// 004cfa83  c20c00               ret 0xc
// 004cfa86  8b4704               mov eax, dword ptr [edi + 4]
// 004cfa89  8b0f                 mov ecx, dword ptr [edi]
// 004cfa8b  53                   push ebx
// 004cfa8c  55                   push ebp
// 004cfa8d  8d68ff               lea ebp, [eax - 1]
// 004cfa90  99                   cdq 
// 004cfa91  2bc2                 sub eax, edx
// 004cfa93  8b542410             mov edx, dword ptr [esp + 0x10]
// 004cfa97  56                   push esi
// 004cfa98  8bf0                 mov esi, eax
// 004cfa9a  d1fe                 sar esi, 1
// 004cfa9c  8d04f1               lea eax, [ecx + esi*8]
// 004cfa9f  50                   push eax
// 004cfaa0  52                   push edx
// 004cfaa1  33db                 xor ebx, ebx
// 004cfaa3  ff542424             call dword ptr [esp + 0x24]
// 004cfaa7  83c408               add esp, 8
// 004cfaaa  85c0                 test eax, eax
// 004cfaac  7431                 je 0x4cfadf
// 004cfaae  7d05                 jge 0x4cfab5
// 004cfab0  8d6eff               lea ebp, [esi - 1]
// 004cfab3  eb03                 jmp 0x4cfab8
// 004cfab5  8d5e01               lea ebx, [esi + 1]
// 004cfab8  8bc5                 mov eax, ebp
// 004cfaba  2bc3                 sub eax, ebx
// 004cfabc  99                   cdq 
// 004cfabd  2bc2                 sub eax, edx
// 004cfabf  8bf0                 mov esi, eax
// 004cfac1  d1fe                 sar esi, 1
// 004cfac3  03f3                 add esi, ebx
// 004cfac5  3bdd                 cmp ebx, ebp
// 004cfac7  7f26                 jg 0x4cfaef
// 004cfac9  8b07                 mov eax, dword ptr [edi]
// 004cfacb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004cfacf  8d04f0               lea eax, [eax + esi*8]
// 004cfad2  50                   push eax
// 004cfad3  51                   push ecx
// 004cfad4  ff542424             call dword ptr [esp + 0x24]
// 004cfad8  83c408               add esp, 8
// 004cfadb  85c0                 test eax, eax
// 004cfadd  75cf                 jne 0x4cfaae
// 004cfadf  8b542418             mov edx, dword ptr [esp + 0x18]
// 004cfae3  8bc6                 mov eax, esi
// 004cfae5  5e                   pop esi
// 004cfae6  5d                   pop ebp
// 004cfae7  5b                   pop ebx
// 004cfae8  c60201               mov byte ptr [edx], 1
// 004cfaeb  5f                   pop edi
// 004cfaec  c20c00               ret 0xc
// 004cfaef  8b442418             mov eax, dword ptr [esp + 0x18]
// 004cfaf3  5e                   pop esi
// 004cfaf4  5d                   pop ebp
// 004cfaf5  c60000               mov byte ptr [eax], 0
// 004cfaf8  8bc3                 mov eax, ebx
// 004cfafa  5b                   pop ebx
// 004cfafb  5f                   pop edi
// 004cfafc  c20c00               ret 0xc
// library openrbx-raknet/StringCompressor.cpp (function ?GetIndexFromKey@?$OrderedList@HUMapNode@?$Map@HPAVHuffmanEncodingTree@@$1??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z@DataStructures@@$1?NodeComparisonFunc@23@SAHABHABU123@@Z@DataStructures@@QBEIABHPA_NP6AH0ABUMapNode@?$Map@HPAVHuffmanEncodingTree@@$1??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z@2@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet StringCompressor.cpp
