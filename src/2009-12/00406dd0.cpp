// from server: 100% by auto
// roc 2009-12 00406dd0  unit: VCApp::?$CComObject  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00406dd0
//
// 00406dd0  83ec08               sub esp, 8
// 00406dd3  53                   push ebx
// 00406dd4  8bd9                 mov ebx, ecx
// 00406dd6  33c0                 xor eax, eax
// 00406dd8  39430c               cmp dword ptr [ebx + 0xc], eax
// 00406ddb  7405                 je 0x406de2
// 00406ddd  394314               cmp dword ptr [ebx + 0x14], eax
// 00406de0  750a                 jne 0x406dec
// 00406de2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00406de6  50                   push eax
// 00406de7  e844fdffff           call 0x406b30
// 00406dec  837b0c00             cmp dword ptr [ebx + 0xc], 0
// 00406df0  0f84d1000000         je 0x406ec7
// 00406df6  837b1400             cmp dword ptr [ebx + 0x14], 0
// 00406dfa  55                   push ebp
// 00406dfb  56                   push esi
// 00406dfc  57                   push edi
// 00406dfd  0f84a7000000         je 0x406eaa
// 00406e03  837c242401           cmp dword ptr [esp + 0x24], 1
// 00406e08  0f859c000000         jne 0x406eaa
// 00406e0e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00406e12  8b01                 mov eax, dword ptr [ecx]
// 00406e14  50                   push eax
// 00406e15  ff1538b29800         call dword ptr [0x98b238]
// 00406e1b  8b7b18               mov edi, dword ptr [ebx + 0x18]
// 00406e1e  83ef01               sub edi, 1
// 00406e21  89442410             mov dword ptr [esp + 0x10], eax
// 00406e25  0f887f000000         js 0x406eaa
// 00406e2b  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00406e2e  8d2c7f               lea ebp, [edi + edi*2]
// 00406e31  03ed                 add ebp, ebp
// 00406e33  03ed                 add ebp, ebp
// 00406e35  8d542804             lea edx, [eax + ebp + 4]
// 00406e39  89442414             mov dword ptr [esp + 0x14], eax
// 00406e3d  89542428             mov dword ptr [esp + 0x28], edx
// 00406e41  8b442410             mov eax, dword ptr [esp + 0x10]
// 00406e45  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00406e49  3b01                 cmp eax, dword ptr [ecx]
// 00406e4b  7550                 jne 0x406e9d
// 00406e4d  8b5314               mov edx, dword ptr [ebx + 0x14]
// 00406e50  8b4c2a04             mov ecx, dword ptr [edx + ebp + 4]
// 00406e54  8b442420             mov eax, dword ptr [esp + 0x20]
// 00406e58  8b30                 mov esi, dword ptr [eax]
// 00406e5a  03d5                 add edx, ebp
// 00406e5c  8b12                 mov edx, dword ptr [edx]
// 00406e5e  03c9                 add ecx, ecx
// 00406e60  83f904               cmp ecx, 4
// 00406e63  7214                 jb 0x406e79
// 00406e65  8b02                 mov eax, dword ptr [edx]
// 00406e67  3b06                 cmp eax, dword ptr [esi]
// 00406e69  7532                 jne 0x406e9d
// 00406e6b  83e904               sub ecx, 4
// 00406e6e  83c604               add esi, 4
// 00406e71  83c204               add edx, 4
// 00406e74  83f904               cmp ecx, 4
// 00406e77  73ec                 jae 0x406e65
// 00406e79  85c9                 test ecx, ecx
// 00406e7b  7451                 je 0x406ece
// 00406e7d  8a06                 mov al, byte ptr [esi]
// 00406e7f  3a02                 cmp al, byte ptr [edx]
// 00406e81  751a                 jne 0x406e9d
// 00406e83  83f901               cmp ecx, 1
// 00406e86  7646                 jbe 0x406ece
// 00406e88  8a4601               mov al, byte ptr [esi + 1]
// 00406e8b  3a4201               cmp al, byte ptr [edx + 1]
// 00406e8e  750d                 jne 0x406e9d
// 00406e90  83f902               cmp ecx, 2
// 00406e93  7639                 jbe 0x406ece
// 00406e95  8a4e02               mov cl, byte ptr [esi + 2]
// 00406e98  3a4a02               cmp cl, byte ptr [edx + 2]
// 00406e9b  7431                 je 0x406ece
// 00406e9d  836c24280c           sub dword ptr [esp + 0x28], 0xc
// 00406ea2  4f                   dec edi
// 00406ea3  83ed0c               sub ebp, 0xc
// 00406ea6  85ff                 test edi, edi
// 00406ea8  7d97                 jge 0x406e41
// 00406eaa  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00406eae  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00406eb1  8b08                 mov ecx, dword ptr [eax]
// 00406eb3  52                   push edx
// 00406eb4  8b542428             mov edx, dword ptr [esp + 0x28]
// 00406eb8  52                   push edx
// 00406eb9  8b542428             mov edx, dword ptr [esp + 0x28]
// 00406ebd  52                   push edx
// 00406ebe  50                   push eax
// 00406ebf  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00406ec2  ffd0                 call eax
// 00406ec4  5f                   pop edi
// 00406ec5  5e                   pop esi
// 00406ec6  5d                   pop ebp
// 00406ec7  5b                   pop ebx
// 00406ec8  83c408               add esp, 8
// 00406ecb  c21400               ret 0x14
// 00406ece  8b442414             mov eax, dword ptr [esp + 0x14]
// 00406ed2  8d147f               lea edx, [edi + edi*2]
// 00406ed5  8b4c9008             mov ecx, dword ptr [eax + edx*4 + 8]
// 00406ed9  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00406edd  5f                   pop edi
// 00406ede  5e                   pop esi
// 00406edf  5d                   pop ebp
// 00406ee0  890a                 mov dword ptr [edx], ecx
// 00406ee2  33c0                 xor eax, eax
// 00406ee4  5b                   pop ebx
// 00406ee5  83c408               add esp, 8
// 00406ee8  c21400               ret 0x14
// library atl-9.0/atl.cpp (function ?GetIDsOfNames@CComTypeInfoHolder@ATL@@QAEJABU_GUID@@PAPA_WIKPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
