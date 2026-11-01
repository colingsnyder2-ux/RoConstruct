// from server: 100% by auto
// roc 2011-06 004219f0  unit: RBX::FunctionMarshaller  size: 224 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004219f0
//
// 004219f0  56                   push esi
// 004219f1  8bf1                 mov esi, ecx
// 004219f3  837e1400             cmp dword ptr [esi + 0x14], 0
// 004219f7  750c                 jne 0x421a05
// 004219f9  e803224e00           call 0x903c01
// 004219fe  894614               mov dword ptr [esi + 0x14], eax
// 00421a01  85c0                 test eax, eax
// 00421a03  7440                 je 0x421a45
// 00421a05  8b4614               mov eax, dword ptr [esi + 0x14]
// 00421a08  b9f3ffffff           mov ecx, 0xfffffff3
// 00421a0d  6a0d                 push 0xd
// 00421a0f  2bc8                 sub ecx, eax
// 00421a11  50                   push eax
// 00421a12  c700c7442404         mov dword ptr [eax], 0x42444c7
// 00421a18  c7400400000000       mov dword ptr [eax + 4], 0
// 00421a1f  c64008e9             mov byte ptr [eax + 8], 0xe9
// 00421a23  894809               mov dword ptr [eax + 9], ecx
// 00421a26  ff150802a400         call dword ptr [0xa40208]
// 00421a2c  50                   push eax
// 00421a2d  ff152802a400         call dword ptr [0xa40228]
// 00421a33  55                   push ebp
// 00421a34  668b6c2424           mov bp, word ptr [esp + 0x24]
// 00421a39  6685ed               test bp, bp
// 00421a3c  7515                 jne 0x421a53
// 00421a3e  5d                   pop ebp
// 00421a3f  33c0                 xor eax, eax
// 00421a41  5e                   pop esi
// 00421a42  c22000               ret 0x20
// 00421a45  6a0e                 push 0xe
// 00421a47  ff152003a400         call dword ptr [0xa40320]
// 00421a4d  33c0                 xor eax, eax
// 00421a4f  5e                   pop esi
// 00421a50  c22000               ret 0x20
// 00421a53  53                   push ebx
// 00421a54  57                   push edi
// 00421a55  56                   push esi
// 00421a56  8d5608               lea edx, [esi + 8]
// 00421a59  52                   push edx
// 00421a5a  687c93d100           push 0xd1937c
// 00421a5f  e8ecfdffff           call 0x421850
// 00421a64  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00421a68  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00421a6c  85ff                 test edi, edi
// 00421a6e  750e                 jne 0x421a7e
// 00421a70  f7c300000040         test ebx, 0x40000000
// 00421a76  7406                 je 0x421a7e
// 00421a78  8bfe                 mov edi, esi
// 00421a7a  897c2428             mov dword ptr [esp + 0x28], edi
// 00421a7e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00421a82  85c0                 test eax, eax
// 00421a84  7509                 jne 0x421a8f
// 00421a86  b88064c000           mov eax, 0xc06480
// 00421a8b  89442418             mov dword ptr [esp + 0x18], eax
// 00421a8f  8b742430             mov esi, dword ptr [esp + 0x30]
// 00421a93  8b4804               mov ecx, dword ptr [eax + 4]
// 00421a96  8b10                 mov edx, dword ptr [eax]
// 00421a98  56                   push esi
// 00421a99  8b353c93d100         mov esi, dword ptr [0xd1933c]
// 00421a9f  56                   push esi
// 00421aa0  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00421aa4  57                   push edi
// 00421aa5  56                   push esi
// 00421aa6  8b700c               mov esi, dword ptr [eax + 0xc]
// 00421aa9  8b4008               mov eax, dword ptr [eax + 8]
// 00421aac  2bf1                 sub esi, ecx
// 00421aae  56                   push esi
// 00421aaf  2bc2                 sub eax, edx
// 00421ab1  50                   push eax
// 00421ab2  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00421ab6  51                   push ecx
// 00421ab7  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00421abb  52                   push edx
// 00421abc  53                   push ebx
// 00421abd  0fb7d5               movzx edx, bp
// 00421ac0  51                   push ecx
// 00421ac1  52                   push edx
// 00421ac2  50                   push eax
// 00421ac3  ff159c1ca400         call dword ptr [0xa41c9c]
// 00421ac9  5f                   pop edi
// 00421aca  5b                   pop ebx
// 00421acb  5d                   pop ebp
// 00421acc  5e                   pop esi
// 00421acd  c22000               ret 0x20
// library atl-9.0/atl.cpp (function ?Create@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@QAEPAUHWND__@@PAU3@V_U_RECT@2@PBDKKV_U_MENUorID@2@GPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
