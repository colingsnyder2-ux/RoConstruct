// from server: 100% by auto
// roc 2007-03 00417350  unit: seg_00410000  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00417350
//
// 00417350  56                   push esi
// 00417351  8bf1                 mov esi, ecx
// 00417353  837e1400             cmp dword ptr [esi + 0x14], 0
// 00417357  750c                 jne 0x417365
// 00417359  e8b9f33000           call 0x726717
// 0041735e  85c0                 test eax, eax
// 00417360  894614               mov dword ptr [esi + 0x14], eax
// 00417363  7440                 je 0x4173a5
// 00417365  8b4614               mov eax, dword ptr [esi + 0x14]
// 00417368  b9f3ffffff           mov ecx, 0xfffffff3
// 0041736d  6a0d                 push 0xd
// 0041736f  2bc8                 sub ecx, eax
// 00417371  50                   push eax
// 00417372  c700c7442404         mov dword ptr [eax], 0x42444c7
// 00417378  c7400400000000       mov dword ptr [eax + 4], 0
// 0041737f  c64008e9             mov byte ptr [eax + 8], 0xe9
// 00417383  894809               mov dword ptr [eax + 9], ecx
// 00417386  ff1554d27700         call dword ptr [0x77d254]
// 0041738c  50                   push eax
// 0041738d  ff1558d27700         call dword ptr [0x77d258]
// 00417393  55                   push ebp
// 00417394  668b6c2424           mov bp, word ptr [esp + 0x24]
// 00417399  6685ed               test bp, bp
// 0041739c  7515                 jne 0x4173b3
// 0041739e  5d                   pop ebp
// 0041739f  33c0                 xor eax, eax
// 004173a1  5e                   pop esi
// 004173a2  c22000               ret 0x20
// 004173a5  6a0e                 push 0xe
// 004173a7  ff1550d27700         call dword ptr [0x77d250]
// 004173ad  33c0                 xor eax, eax
// 004173af  5e                   pop esi
// 004173b0  c22000               ret 0x20
// 004173b3  53                   push ebx
// 004173b4  57                   push edi
// 004173b5  56                   push esi
// 004173b6  8d5608               lea edx, [esi + 8]
// 004173b9  52                   push edx
// 004173ba  6814298c00           push 0x8c2914
// 004173bf  e87ce4ffff           call 0x415840
// 004173c4  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004173c8  85ff                 test edi, edi
// 004173ca  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004173ce  750a                 jne 0x4173da
// 004173d0  f7c300000040         test ebx, 0x40000000
// 004173d6  7402                 je 0x4173da
// 004173d8  8bfe                 mov edi, esi
// 004173da  8b442418             mov eax, dword ptr [esp + 0x18]
// 004173de  85c0                 test eax, eax
// 004173e0  7505                 jne 0x4173e7
// 004173e2  b87cf18700           mov eax, 0x87f17c
// 004173e7  8b742430             mov esi, dword ptr [esp + 0x30]
// 004173eb  8b4804               mov ecx, dword ptr [eax + 4]
// 004173ee  8b10                 mov edx, dword ptr [eax]
// 004173f0  56                   push esi
// 004173f1  8b35dc288c00         mov esi, dword ptr [0x8c28dc]
// 004173f7  56                   push esi
// 004173f8  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004173fc  57                   push edi
// 004173fd  56                   push esi
// 004173fe  8b700c               mov esi, dword ptr [eax + 0xc]
// 00417401  8b4008               mov eax, dword ptr [eax + 8]
// 00417404  2bf1                 sub esi, ecx
// 00417406  56                   push esi
// 00417407  2bc2                 sub eax, edx
// 00417409  50                   push eax
// 0041740a  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0041740e  51                   push ecx
// 0041740f  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00417413  52                   push edx
// 00417414  53                   push ebx
// 00417415  0fb7d5               movzx edx, bp
// 00417418  51                   push ecx
// 00417419  52                   push edx
// 0041741a  50                   push eax
// 0041741b  ff1500ed7700         call dword ptr [0x77ed00]
// 00417421  5f                   pop edi
// 00417422  5b                   pop ebx
// 00417423  5d                   pop ebp
// 00417424  5e                   pop esi
// 00417425  c22000               ret 0x20
// library atl-8.0/atl.cpp (function ?Create@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@QAEPAUHWND__@@PAU3@V_U_RECT@2@PBDKKV_U_MENUorID@2@GPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
