// from server: 100% by auto
// roc 2012-06 00408210  unit: VCApp::?$CComObject  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00408210
//
// 00408210  83ec08               sub esp, 8
// 00408213  53                   push ebx
// 00408214  8bd9                 mov ebx, ecx
// 00408216  33c0                 xor eax, eax
// 00408218  39430c               cmp dword ptr [ebx + 0xc], eax
// 0040821b  7405                 je 0x408222
// 0040821d  394314               cmp dword ptr [ebx + 0x14], eax
// 00408220  750a                 jne 0x40822c
// 00408222  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00408226  50                   push eax
// 00408227  e834f7ffff           call 0x407960
// 0040822c  837b0c00             cmp dword ptr [ebx + 0xc], 0
// 00408230  0f84d1000000         je 0x408307
// 00408236  837b1400             cmp dword ptr [ebx + 0x14], 0
// 0040823a  55                   push ebp
// 0040823b  56                   push esi
// 0040823c  57                   push edi
// 0040823d  0f84a7000000         je 0x4082ea
// 00408243  837c242401           cmp dword ptr [esp + 0x24], 1
// 00408248  0f859c000000         jne 0x4082ea
// 0040824e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00408252  8b01                 mov eax, dword ptr [ecx]
// 00408254  50                   push eax
// 00408255  ff15c421b200         call dword ptr [0xb221c4]
// 0040825b  8b7b18               mov edi, dword ptr [ebx + 0x18]
// 0040825e  83ef01               sub edi, 1
// 00408261  89442410             mov dword ptr [esp + 0x10], eax
// 00408265  0f887f000000         js 0x4082ea
// 0040826b  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0040826e  8d2c7f               lea ebp, [edi + edi*2]
// 00408271  03ed                 add ebp, ebp
// 00408273  03ed                 add ebp, ebp
// 00408275  8d542804             lea edx, [eax + ebp + 4]
// 00408279  89442414             mov dword ptr [esp + 0x14], eax
// 0040827d  89542428             mov dword ptr [esp + 0x28], edx
// 00408281  8b442410             mov eax, dword ptr [esp + 0x10]
// 00408285  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00408289  3b01                 cmp eax, dword ptr [ecx]
// 0040828b  7550                 jne 0x4082dd
// 0040828d  8b5314               mov edx, dword ptr [ebx + 0x14]
// 00408290  8b4c2a04             mov ecx, dword ptr [edx + ebp + 4]
// 00408294  8b442420             mov eax, dword ptr [esp + 0x20]
// 00408298  8b30                 mov esi, dword ptr [eax]
// 0040829a  03d5                 add edx, ebp
// 0040829c  8b12                 mov edx, dword ptr [edx]
// 0040829e  03c9                 add ecx, ecx
// 004082a0  83f904               cmp ecx, 4
// 004082a3  7214                 jb 0x4082b9
// 004082a5  8b02                 mov eax, dword ptr [edx]
// 004082a7  3b06                 cmp eax, dword ptr [esi]
// 004082a9  7532                 jne 0x4082dd
// 004082ab  83e904               sub ecx, 4
// 004082ae  83c604               add esi, 4
// 004082b1  83c204               add edx, 4
// 004082b4  83f904               cmp ecx, 4
// 004082b7  73ec                 jae 0x4082a5
// 004082b9  85c9                 test ecx, ecx
// 004082bb  7451                 je 0x40830e
// 004082bd  8a06                 mov al, byte ptr [esi]
// 004082bf  3a02                 cmp al, byte ptr [edx]
// 004082c1  751a                 jne 0x4082dd
// 004082c3  83f901               cmp ecx, 1
// 004082c6  7646                 jbe 0x40830e
// 004082c8  8a4601               mov al, byte ptr [esi + 1]
// 004082cb  3a4201               cmp al, byte ptr [edx + 1]
// 004082ce  750d                 jne 0x4082dd
// 004082d0  83f902               cmp ecx, 2
// 004082d3  7639                 jbe 0x40830e
// 004082d5  8a4e02               mov cl, byte ptr [esi + 2]
// 004082d8  3a4a02               cmp cl, byte ptr [edx + 2]
// 004082db  7431                 je 0x40830e
// 004082dd  836c24280c           sub dword ptr [esp + 0x28], 0xc
// 004082e2  4f                   dec edi
// 004082e3  83ed0c               sub ebp, 0xc
// 004082e6  85ff                 test edi, edi
// 004082e8  7d97                 jge 0x408281
// 004082ea  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004082ee  8b430c               mov eax, dword ptr [ebx + 0xc]
// 004082f1  8b08                 mov ecx, dword ptr [eax]
// 004082f3  52                   push edx
// 004082f4  8b542428             mov edx, dword ptr [esp + 0x28]
// 004082f8  52                   push edx
// 004082f9  8b542428             mov edx, dword ptr [esp + 0x28]
// 004082fd  52                   push edx
// 004082fe  50                   push eax
// 004082ff  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00408302  ffd0                 call eax
// 00408304  5f                   pop edi
// 00408305  5e                   pop esi
// 00408306  5d                   pop ebp
// 00408307  5b                   pop ebx
// 00408308  83c408               add esp, 8
// 0040830b  c21400               ret 0x14
// 0040830e  8b442414             mov eax, dword ptr [esp + 0x14]
// 00408312  8d147f               lea edx, [edi + edi*2]
// 00408315  8b4c9008             mov ecx, dword ptr [eax + edx*4 + 8]
// 00408319  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0040831d  5f                   pop edi
// 0040831e  5e                   pop esi
// 0040831f  5d                   pop ebp
// 00408320  890a                 mov dword ptr [edx], ecx
// 00408322  33c0                 xor eax, eax
// 00408324  5b                   pop ebx
// 00408325  83c408               add esp, 8
// 00408328  c21400               ret 0x14
// library atl-9.0/atl.cpp (function ?GetIDsOfNames@CComTypeInfoHolder@ATL@@QAEJABU_GUID@@PAPA_WIKPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
