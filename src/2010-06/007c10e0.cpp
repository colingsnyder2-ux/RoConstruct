// from server: 100% by auto
// roc 2010-06 007c10e0  unit: HH::?$CArray  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c10e0
//
// 007c10e0  83ec08               sub esp, 8
// 007c10e3  56                   push esi
// 007c10e4  8bf1                 mov esi, ecx
// 007c10e6  8b4608               mov eax, dword ptr [esi + 8]
// 007c10e9  85c0                 test eax, eax
// 007c10eb  756d                 jne 0x7c115a
// 007c10ed  8b4604               mov eax, dword ptr [esi + 4]
// 007c10f0  85c0                 test eax, eax
// 007c10f2  7505                 jne 0x7c10f9
// 007c10f4  5e                   pop esi
// 007c10f5  83c408               add esp, 8
// 007c10f8  c3                   ret 
// 007c10f9  53                   push ebx
// 007c10fa  57                   push edi
// 007c10fb  8d4c240c             lea ecx, [esp + 0xc]
// 007c10ff  51                   push ecx
// 007c1100  6a00                 push 0
// 007c1102  50                   push eax
// 007c1103  c744241800000000     mov dword ptr [esp + 0x18], 0
// 007c110b  e800f4ffff           call 0x7c0510
// 007c1110  8bf8                 mov edi, eax
// 007c1112  83c40c               add esp, 0xc
// 007c1115  85ff                 test edi, edi
// 007c1117  743d                 je 0x7c1156
// 007c1119  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007c111d  85db                 test ebx, ebx
// 007c111f  7435                 je 0x7c1156
// 007c1121  8bce                 mov ecx, esi
// 007c1123  e888f1ffff           call 0x7c02b0
// 007c1128  8d54240c             lea edx, [esp + 0xc]
// 007c112c  52                   push edx
// 007c112d  8bce                 mov ecx, esi
// 007c112f  897e04               mov dword ptr [esi + 4], edi
// 007c1132  895e08               mov dword ptr [esi + 8], ebx
// 007c1135  c7460c01000000       mov dword ptr [esi + 0xc], 1
// 007c113c  e8bff1ffff           call 0x7c0300
// 007c1141  8b08                 mov ecx, dword ptr [eax]
// 007c1143  894e18               mov dword ptr [esi + 0x18], ecx
// 007c1146  8b5004               mov edx, dword ptr [eax + 4]
// 007c1149  8b4608               mov eax, dword ptr [esi + 8]
// 007c114c  5f                   pop edi
// 007c114d  5b                   pop ebx
// 007c114e  89561c               mov dword ptr [esi + 0x1c], edx
// 007c1151  5e                   pop esi
// 007c1152  83c408               add esp, 8
// 007c1155  c3                   ret 
// 007c1156  5f                   pop edi
// 007c1157  33c0                 xor eax, eax
// 007c1159  5b                   pop ebx
// 007c115a  5e                   pop esi
// 007c115b  83c408               add esp, 8
// 007c115e  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?PreMultiply@CXTPImageManagerIconHandle@@QAEPAEXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
