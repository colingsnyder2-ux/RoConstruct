// from server: 100% by auto
// roc 2011-06 005b2050  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005b2050
//
// 005b2050  53                   push ebx
// 005b2051  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005b2055  57                   push edi
// 005b2056  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b205a  57                   push edi
// 005b205b  53                   push ebx
// 005b205c  ff153c03a400         call dword ptr [0xa4033c]
// 005b2062  85c0                 test eax, eax
// 005b2064  7503                 jne 0x5b2069
// 005b2066  5f                   pop edi
// 005b2067  5b                   pop ebx
// 005b2068  c3                   ret 
// 005b2069  56                   push esi
// 005b206a  50                   push eax
// 005b206b  ff15d001a400         call dword ptr [0xa401d0]
// 005b2071  8bf0                 mov esi, eax
// 005b2073  85f6                 test esi, esi
// 005b2075  742d                 je 0x5b20a4
// 005b2077  57                   push edi
// 005b2078  53                   push ebx
// 005b2079  ff154003a400         call dword ptr [0xa40340]
// 005b207f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005b2083  03c6                 add eax, esi
// 005b2085  83e10f               and ecx, 0xf
// 005b2088  7616                 jbe 0x5b20a0
// 005b208a  8d9b00000000         lea ebx, [ebx]
// 005b2090  3bf0                 cmp esi, eax
// 005b2092  7310                 jae 0x5b20a4
// 005b2094  83e901               sub ecx, 1
// 005b2097  0fb716               movzx edx, word ptr [esi]
// 005b209a  8d745602             lea esi, [esi + edx*2 + 2]
// 005b209e  75f0                 jne 0x5b2090
// 005b20a0  3bf0                 cmp esi, eax
// 005b20a2  7206                 jb 0x5b20aa
// 005b20a4  5e                   pop esi
// 005b20a5  5f                   pop edi
// 005b20a6  33c0                 xor eax, eax
// 005b20a8  5b                   pop ebx
// 005b20a9  c3                   ret 
// 005b20aa  0fb706               movzx eax, word ptr [esi]
// 005b20ad  f7d8                 neg eax
// 005b20af  1bc0                 sbb eax, eax
// 005b20b1  23c6                 and eax, esi
// 005b20b3  5e                   pop esi
// 005b20b4  5f                   pop edi
// 005b20b5  5b                   pop ebx
// 005b20b6  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?_AtlGetStringResourceImage@ATL@@YAPBUATLSTRINGRESOURCEIMAGE@1@PAUHINSTANCE__@@PAUHRSRC__@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
