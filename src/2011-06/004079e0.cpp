// from server: 100% by auto
// roc 2011-06 004079e0  unit: VCApp::?$CComObject  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004079e0
//
// 004079e0  83ec08               sub esp, 8
// 004079e3  53                   push ebx
// 004079e4  8bd9                 mov ebx, ecx
// 004079e6  33c0                 xor eax, eax
// 004079e8  39430c               cmp dword ptr [ebx + 0xc], eax
// 004079eb  7405                 je 0x4079f2
// 004079ed  394314               cmp dword ptr [ebx + 0x14], eax
// 004079f0  750a                 jne 0x4079fc
// 004079f2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004079f6  50                   push eax
// 004079f7  e844fdffff           call 0x407740
// 004079fc  837b0c00             cmp dword ptr [ebx + 0xc], 0
// 00407a00  0f84d1000000         je 0x407ad7
// 00407a06  837b1400             cmp dword ptr [ebx + 0x14], 0
// 00407a0a  55                   push ebp
// 00407a0b  56                   push esi
// 00407a0c  57                   push edi
// 00407a0d  0f84a7000000         je 0x407aba
// 00407a13  837c242401           cmp dword ptr [esp + 0x24], 1
// 00407a18  0f859c000000         jne 0x407aba
// 00407a1e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00407a22  8b01                 mov eax, dword ptr [ecx]
// 00407a24  50                   push eax
// 00407a25  ff155803a400         call dword ptr [0xa40358]
// 00407a2b  8b7b18               mov edi, dword ptr [ebx + 0x18]
// 00407a2e  83ef01               sub edi, 1
// 00407a31  89442410             mov dword ptr [esp + 0x10], eax
// 00407a35  0f887f000000         js 0x407aba
// 00407a3b  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00407a3e  8d2c7f               lea ebp, [edi + edi*2]
// 00407a41  03ed                 add ebp, ebp
// 00407a43  03ed                 add ebp, ebp
// 00407a45  8d542804             lea edx, [eax + ebp + 4]
// 00407a49  89442414             mov dword ptr [esp + 0x14], eax
// 00407a4d  89542428             mov dword ptr [esp + 0x28], edx
// 00407a51  8b442410             mov eax, dword ptr [esp + 0x10]
// 00407a55  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00407a59  3b01                 cmp eax, dword ptr [ecx]
// 00407a5b  7550                 jne 0x407aad
// 00407a5d  8b5314               mov edx, dword ptr [ebx + 0x14]
// 00407a60  8b4c2a04             mov ecx, dword ptr [edx + ebp + 4]
// 00407a64  8b442420             mov eax, dword ptr [esp + 0x20]
// 00407a68  8b30                 mov esi, dword ptr [eax]
// 00407a6a  03d5                 add edx, ebp
// 00407a6c  8b12                 mov edx, dword ptr [edx]
// 00407a6e  03c9                 add ecx, ecx
// 00407a70  83f904               cmp ecx, 4
// 00407a73  7214                 jb 0x407a89
// 00407a75  8b02                 mov eax, dword ptr [edx]
// 00407a77  3b06                 cmp eax, dword ptr [esi]
// 00407a79  7532                 jne 0x407aad
// 00407a7b  83e904               sub ecx, 4
// 00407a7e  83c604               add esi, 4
// 00407a81  83c204               add edx, 4
// 00407a84  83f904               cmp ecx, 4
// 00407a87  73ec                 jae 0x407a75
// 00407a89  85c9                 test ecx, ecx
// 00407a8b  7451                 je 0x407ade
// 00407a8d  8a06                 mov al, byte ptr [esi]
// 00407a8f  3a02                 cmp al, byte ptr [edx]
// 00407a91  751a                 jne 0x407aad
// 00407a93  83f901               cmp ecx, 1
// 00407a96  7646                 jbe 0x407ade
// 00407a98  8a4601               mov al, byte ptr [esi + 1]
// 00407a9b  3a4201               cmp al, byte ptr [edx + 1]
// 00407a9e  750d                 jne 0x407aad
// 00407aa0  83f902               cmp ecx, 2
// 00407aa3  7639                 jbe 0x407ade
// 00407aa5  8a4e02               mov cl, byte ptr [esi + 2]
// 00407aa8  3a4a02               cmp cl, byte ptr [edx + 2]
// 00407aab  7431                 je 0x407ade
// 00407aad  836c24280c           sub dword ptr [esp + 0x28], 0xc
// 00407ab2  4f                   dec edi
// 00407ab3  83ed0c               sub ebp, 0xc
// 00407ab6  85ff                 test edi, edi
// 00407ab8  7d97                 jge 0x407a51
// 00407aba  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00407abe  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00407ac1  8b08                 mov ecx, dword ptr [eax]
// 00407ac3  52                   push edx
// 00407ac4  8b542428             mov edx, dword ptr [esp + 0x28]
// 00407ac8  52                   push edx
// 00407ac9  8b542428             mov edx, dword ptr [esp + 0x28]
// 00407acd  52                   push edx
// 00407ace  50                   push eax
// 00407acf  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00407ad2  ffd0                 call eax
// 00407ad4  5f                   pop edi
// 00407ad5  5e                   pop esi
// 00407ad6  5d                   pop ebp
// 00407ad7  5b                   pop ebx
// 00407ad8  83c408               add esp, 8
// 00407adb  c21400               ret 0x14
// 00407ade  8b442414             mov eax, dword ptr [esp + 0x14]
// 00407ae2  8d147f               lea edx, [edi + edi*2]
// 00407ae5  8b4c9008             mov ecx, dword ptr [eax + edx*4 + 8]
// 00407ae9  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00407aed  5f                   pop edi
// 00407aee  5e                   pop esi
// 00407aef  5d                   pop ebp
// 00407af0  890a                 mov dword ptr [edx], ecx
// 00407af2  33c0                 xor eax, eax
// 00407af4  5b                   pop ebx
// 00407af5  83c408               add esp, 8
// 00407af8  c21400               ret 0x14
// library atl-9.0/atl.cpp (function ?GetIDsOfNames@CComTypeInfoHolder@ATL@@QAEJABU_GUID@@PAPA_WIKPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
