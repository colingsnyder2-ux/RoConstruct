// from server: 100% by auto
// roc 2012-06 00425450  unit: RBX::FunctionMarshaller  size: 224 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00425450
//
// 00425450  56                   push esi
// 00425451  8bf1                 mov esi, ecx
// 00425453  837e1400             cmp dword ptr [esi + 0x14], 0
// 00425457  750c                 jne 0x425465
// 00425459  e88b676500           call 0xa7bbe9
// 0042545e  894614               mov dword ptr [esi + 0x14], eax
// 00425461  85c0                 test eax, eax
// 00425463  7440                 je 0x4254a5
// 00425465  8b4614               mov eax, dword ptr [esi + 0x14]
// 00425468  b9f3ffffff           mov ecx, 0xfffffff3
// 0042546d  6a0d                 push 0xd
// 0042546f  2bc8                 sub ecx, eax
// 00425471  50                   push eax
// 00425472  c700c7442404         mov dword ptr [eax], 0x42444c7
// 00425478  c7400400000000       mov dword ptr [eax + 4], 0
// 0042547f  c64008e9             mov byte ptr [eax + 8], 0xe9
// 00425483  894809               mov dword ptr [eax + 9], ecx
// 00425486  ff159422b200         call dword ptr [0xb22294]
// 0042548c  50                   push eax
// 0042548d  ff159022b200         call dword ptr [0xb22290]
// 00425493  55                   push ebp
// 00425494  668b6c2424           mov bp, word ptr [esp + 0x24]
// 00425499  6685ed               test bp, bp
// 0042549c  7515                 jne 0x4254b3
// 0042549e  5d                   pop ebp
// 0042549f  33c0                 xor eax, eax
// 004254a1  5e                   pop esi
// 004254a2  c22000               ret 0x20
// 004254a5  6a0e                 push 0xe
// 004254a7  ff154c22b200         call dword ptr [0xb2224c]
// 004254ad  33c0                 xor eax, eax
// 004254af  5e                   pop esi
// 004254b0  c22000               ret 0x20
// 004254b3  53                   push ebx
// 004254b4  57                   push edi
// 004254b5  56                   push esi
// 004254b6  8d5608               lea edx, [esi + 8]
// 004254b9  52                   push edx
// 004254ba  68c4a4e500           push 0xe5a4c4
// 004254bf  e80cfdffff           call 0x4251d0
// 004254c4  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004254c8  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004254cc  85ff                 test edi, edi
// 004254ce  750e                 jne 0x4254de
// 004254d0  f7c300000040         test ebx, 0x40000000
// 004254d6  7406                 je 0x4254de
// 004254d8  8bfe                 mov edi, esi
// 004254da  897c2428             mov dword ptr [esp + 0x28], edi
// 004254de  8b442418             mov eax, dword ptr [esp + 0x18]
// 004254e2  85c0                 test eax, eax
// 004254e4  7509                 jne 0x4254ef
// 004254e6  b8a0f4d500           mov eax, 0xd5f4a0
// 004254eb  89442418             mov dword ptr [esp + 0x18], eax
// 004254ef  8b742430             mov esi, dword ptr [esp + 0x30]
// 004254f3  8b4804               mov ecx, dword ptr [eax + 4]
// 004254f6  8b10                 mov edx, dword ptr [eax]
// 004254f8  56                   push esi
// 004254f9  8b3584a4e500         mov esi, dword ptr [0xe5a484]
// 004254ff  56                   push esi
// 00425500  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00425504  57                   push edi
// 00425505  56                   push esi
// 00425506  8b700c               mov esi, dword ptr [eax + 0xc]
// 00425509  8b4008               mov eax, dword ptr [eax + 8]
// 0042550c  2bf1                 sub esi, ecx
// 0042550e  56                   push esi
// 0042550f  2bc2                 sub eax, edx
// 00425511  50                   push eax
// 00425512  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00425516  51                   push ecx
// 00425517  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0042551b  52                   push edx
// 0042551c  53                   push ebx
// 0042551d  0fb7d5               movzx edx, bp
// 00425520  51                   push ecx
// 00425521  52                   push edx
// 00425522  50                   push eax
// 00425523  ff15b83ab200         call dword ptr [0xb23ab8]
// 00425529  5f                   pop edi
// 0042552a  5b                   pop ebx
// 0042552b  5d                   pop ebp
// 0042552c  5e                   pop esi
// 0042552d  c22000               ret 0x20
// library atl-9.0/atl.cpp (function ?Create@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@QAEPAUHWND__@@PAU3@V_U_RECT@2@PBDKKV_U_MENUorID@2@GPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
