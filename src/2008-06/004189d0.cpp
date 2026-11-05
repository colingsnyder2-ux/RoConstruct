// from server: 100% by auto
// roc 2008-06 004189d0  unit: VCLuaFunction::?$CComAggObject  size: 224 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004189d0
//
// 004189d0  56                   push esi
// 004189d1  8bf1                 mov esi, ecx
// 004189d3  837e1400             cmp dword ptr [esi + 0x14], 0
// 004189d7  750c                 jne 0x4189e5
// 004189d9  e8dfd63800           call 0x7a60bd
// 004189de  894614               mov dword ptr [esi + 0x14], eax
// 004189e1  85c0                 test eax, eax
// 004189e3  7440                 je 0x418a25
// 004189e5  8b4614               mov eax, dword ptr [esi + 0x14]
// 004189e8  b9f3ffffff           mov ecx, 0xfffffff3
// 004189ed  6a0d                 push 0xd
// 004189ef  2bc8                 sub ecx, eax
// 004189f1  50                   push eax
// 004189f2  c700c7442404         mov dword ptr [eax], 0x42444c7
// 004189f8  c7400400000000       mov dword ptr [eax + 4], 0
// 004189ff  c64008e9             mov byte ptr [eax + 8], 0xe9
// 00418a03  894809               mov dword ptr [eax + 9], ecx
// 00418a06  ff15e4218000         call dword ptr [0x8021e4]
// 00418a0c  50                   push eax
// 00418a0d  ff15e0218000         call dword ptr [0x8021e0]
// 00418a13  55                   push ebp
// 00418a14  668b6c2424           mov bp, word ptr [esp + 0x24]
// 00418a19  6685ed               test bp, bp
// 00418a1c  7515                 jne 0x418a33
// 00418a1e  5d                   pop ebp
// 00418a1f  33c0                 xor eax, eax
// 00418a21  5e                   pop esi
// 00418a22  c22000               ret 0x20
// 00418a25  6a0e                 push 0xe
// 00418a27  ff15d0218000         call dword ptr [0x8021d0]
// 00418a2d  33c0                 xor eax, eax
// 00418a2f  5e                   pop esi
// 00418a30  c22000               ret 0x20
// 00418a33  53                   push ebx
// 00418a34  57                   push edi
// 00418a35  56                   push esi
// 00418a36  8d5608               lea edx, [esi + 8]
// 00418a39  52                   push edx
// 00418a3a  6814f39700           push 0x97f314
// 00418a3f  e86ceeffff           call 0x4178b0
// 00418a44  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00418a48  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00418a4c  85ff                 test edi, edi
// 00418a4e  750e                 jne 0x418a5e
// 00418a50  f7c300000040         test ebx, 0x40000000
// 00418a56  7406                 je 0x418a5e
// 00418a58  8bfe                 mov edi, esi
// 00418a5a  897c2428             mov dword ptr [esp + 0x28], edi
// 00418a5e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00418a62  85c0                 test eax, eax
// 00418a64  7509                 jne 0x418a6f
// 00418a66  b87c819200           mov eax, 0x92817c
// 00418a6b  89442418             mov dword ptr [esp + 0x18], eax
// 00418a6f  8b742430             mov esi, dword ptr [esp + 0x30]
// 00418a73  8b4804               mov ecx, dword ptr [eax + 4]
// 00418a76  8b10                 mov edx, dword ptr [eax]
// 00418a78  56                   push esi
// 00418a79  8b35acf29700         mov esi, dword ptr [0x97f2ac]
// 00418a7f  56                   push esi
// 00418a80  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00418a84  57                   push edi
// 00418a85  56                   push esi
// 00418a86  8b700c               mov esi, dword ptr [eax + 0xc]
// 00418a89  8b4008               mov eax, dword ptr [eax + 8]
// 00418a8c  2bf1                 sub esi, ecx
// 00418a8e  56                   push esi
// 00418a8f  2bc2                 sub eax, edx
// 00418a91  50                   push eax
// 00418a92  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00418a96  51                   push ecx
// 00418a97  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00418a9b  52                   push edx
// 00418a9c  53                   push ebx
// 00418a9d  0fb7d5               movzx edx, bp
// 00418aa0  51                   push ecx
// 00418aa1  52                   push edx
// 00418aa2  50                   push eax
// 00418aa3  ff15c02d8000         call dword ptr [0x802dc0]
// 00418aa9  5f                   pop edi
// 00418aaa  5b                   pop ebx
// 00418aab  5d                   pop ebp
// 00418aac  5e                   pop esi
// 00418aad  c22000               ret 0x20
// library atl-9.0/atl.cpp (function ?Create@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@QAEPAUHWND__@@PAU3@V_U_RECT@2@PBDKKV_U_MENUorID@2@GPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
