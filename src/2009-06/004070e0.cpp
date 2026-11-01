// from server: 100% by auto
// roc 2009-06 004070e0  unit: VCApp::?$CComObject  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004070e0
//
// 004070e0  83ec08               sub esp, 8
// 004070e3  53                   push ebx
// 004070e4  8bd9                 mov ebx, ecx
// 004070e6  33c0                 xor eax, eax
// 004070e8  39430c               cmp dword ptr [ebx + 0xc], eax
// 004070eb  7405                 je 0x4070f2
// 004070ed  394314               cmp dword ptr [ebx + 0x14], eax
// 004070f0  750a                 jne 0x4070fc
// 004070f2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004070f6  50                   push eax
// 004070f7  e844fdffff           call 0x406e40
// 004070fc  837b0c00             cmp dword ptr [ebx + 0xc], 0
// 00407100  0f84d1000000         je 0x4071d7
// 00407106  837b1400             cmp dword ptr [ebx + 0x14], 0
// 0040710a  55                   push ebp
// 0040710b  56                   push esi
// 0040710c  57                   push edi
// 0040710d  0f84a7000000         je 0x4071ba
// 00407113  837c242401           cmp dword ptr [esp + 0x24], 1
// 00407118  0f859c000000         jne 0x4071ba
// 0040711e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00407122  8b01                 mov eax, dword ptr [ecx]
// 00407124  50                   push eax
// 00407125  ff1500e28900         call dword ptr [0x89e200]
// 0040712b  8b7b18               mov edi, dword ptr [ebx + 0x18]
// 0040712e  83ef01               sub edi, 1
// 00407131  89442410             mov dword ptr [esp + 0x10], eax
// 00407135  0f887f000000         js 0x4071ba
// 0040713b  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0040713e  8d2c7f               lea ebp, [edi + edi*2]
// 00407141  03ed                 add ebp, ebp
// 00407143  03ed                 add ebp, ebp
// 00407145  8d542804             lea edx, [eax + ebp + 4]
// 00407149  89442414             mov dword ptr [esp + 0x14], eax
// 0040714d  89542428             mov dword ptr [esp + 0x28], edx
// 00407151  8b442410             mov eax, dword ptr [esp + 0x10]
// 00407155  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00407159  3b01                 cmp eax, dword ptr [ecx]
// 0040715b  7550                 jne 0x4071ad
// 0040715d  8b5314               mov edx, dword ptr [ebx + 0x14]
// 00407160  8b4c2a04             mov ecx, dword ptr [edx + ebp + 4]
// 00407164  8b442420             mov eax, dword ptr [esp + 0x20]
// 00407168  8b30                 mov esi, dword ptr [eax]
// 0040716a  03d5                 add edx, ebp
// 0040716c  8b12                 mov edx, dword ptr [edx]
// 0040716e  03c9                 add ecx, ecx
// 00407170  83f904               cmp ecx, 4
// 00407173  7214                 jb 0x407189
// 00407175  8b02                 mov eax, dword ptr [edx]
// 00407177  3b06                 cmp eax, dword ptr [esi]
// 00407179  7532                 jne 0x4071ad
// 0040717b  83e904               sub ecx, 4
// 0040717e  83c604               add esi, 4
// 00407181  83c204               add edx, 4
// 00407184  83f904               cmp ecx, 4
// 00407187  73ec                 jae 0x407175
// 00407189  85c9                 test ecx, ecx
// 0040718b  7451                 je 0x4071de
// 0040718d  8a06                 mov al, byte ptr [esi]
// 0040718f  3a02                 cmp al, byte ptr [edx]
// 00407191  751a                 jne 0x4071ad
// 00407193  83f901               cmp ecx, 1
// 00407196  7646                 jbe 0x4071de
// 00407198  8a4601               mov al, byte ptr [esi + 1]
// 0040719b  3a4201               cmp al, byte ptr [edx + 1]
// 0040719e  750d                 jne 0x4071ad
// 004071a0  83f902               cmp ecx, 2
// 004071a3  7639                 jbe 0x4071de
// 004071a5  8a4e02               mov cl, byte ptr [esi + 2]
// 004071a8  3a4a02               cmp cl, byte ptr [edx + 2]
// 004071ab  7431                 je 0x4071de
// 004071ad  836c24280c           sub dword ptr [esp + 0x28], 0xc
// 004071b2  4f                   dec edi
// 004071b3  83ed0c               sub ebp, 0xc
// 004071b6  85ff                 test edi, edi
// 004071b8  7d97                 jge 0x407151
// 004071ba  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004071be  8b430c               mov eax, dword ptr [ebx + 0xc]
// 004071c1  8b08                 mov ecx, dword ptr [eax]
// 004071c3  52                   push edx
// 004071c4  8b542428             mov edx, dword ptr [esp + 0x28]
// 004071c8  52                   push edx
// 004071c9  8b542428             mov edx, dword ptr [esp + 0x28]
// 004071cd  52                   push edx
// 004071ce  50                   push eax
// 004071cf  8b4128               mov eax, dword ptr [ecx + 0x28]
// 004071d2  ffd0                 call eax
// 004071d4  5f                   pop edi
// 004071d5  5e                   pop esi
// 004071d6  5d                   pop ebp
// 004071d7  5b                   pop ebx
// 004071d8  83c408               add esp, 8
// 004071db  c21400               ret 0x14
// 004071de  8b442414             mov eax, dword ptr [esp + 0x14]
// 004071e2  8d147f               lea edx, [edi + edi*2]
// 004071e5  8b4c9008             mov ecx, dword ptr [eax + edx*4 + 8]
// 004071e9  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004071ed  5f                   pop edi
// 004071ee  5e                   pop esi
// 004071ef  5d                   pop ebp
// 004071f0  890a                 mov dword ptr [edx], ecx
// 004071f2  33c0                 xor eax, eax
// 004071f4  5b                   pop ebx
// 004071f5  83c408               add esp, 8
// 004071f8  c21400               ret 0x14
// library atl-9.0/atl.cpp (function ?GetIDsOfNames@CComTypeInfoHolder@ATL@@QAEJABU_GUID@@PAPA_WIKPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
