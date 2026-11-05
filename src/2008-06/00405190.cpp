// from server: 100% by auto
// roc 2008-06 00405190  unit: VCWorkspace::?$CComObject  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00405190
//
// 00405190  83ec08               sub esp, 8
// 00405193  53                   push ebx
// 00405194  8bd9                 mov ebx, ecx
// 00405196  33c0                 xor eax, eax
// 00405198  39430c               cmp dword ptr [ebx + 0xc], eax
// 0040519b  7405                 je 0x4051a2
// 0040519d  394314               cmp dword ptr [ebx + 0x14], eax
// 004051a0  750a                 jne 0x4051ac
// 004051a2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004051a6  50                   push eax
// 004051a7  e8d4f8ffff           call 0x404a80
// 004051ac  837b0c00             cmp dword ptr [ebx + 0xc], 0
// 004051b0  0f84d1000000         je 0x405287
// 004051b6  837b1400             cmp dword ptr [ebx + 0x14], 0
// 004051ba  55                   push ebp
// 004051bb  56                   push esi
// 004051bc  57                   push edi
// 004051bd  0f84a7000000         je 0x40526a
// 004051c3  837c242401           cmp dword ptr [esp + 0x24], 1
// 004051c8  0f859c000000         jne 0x40526a
// 004051ce  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004051d2  8b01                 mov eax, dword ptr [ecx]
// 004051d4  50                   push eax
// 004051d5  ff15e8228000         call dword ptr [0x8022e8]
// 004051db  8b7b18               mov edi, dword ptr [ebx + 0x18]
// 004051de  83ef01               sub edi, 1
// 004051e1  89442410             mov dword ptr [esp + 0x10], eax
// 004051e5  0f887f000000         js 0x40526a
// 004051eb  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004051ee  8d2c7f               lea ebp, [edi + edi*2]
// 004051f1  03ed                 add ebp, ebp
// 004051f3  03ed                 add ebp, ebp
// 004051f5  8d542804             lea edx, [eax + ebp + 4]
// 004051f9  89442414             mov dword ptr [esp + 0x14], eax
// 004051fd  89542428             mov dword ptr [esp + 0x28], edx
// 00405201  8b442410             mov eax, dword ptr [esp + 0x10]
// 00405205  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00405209  3b01                 cmp eax, dword ptr [ecx]
// 0040520b  7550                 jne 0x40525d
// 0040520d  8b5314               mov edx, dword ptr [ebx + 0x14]
// 00405210  8b4c2a04             mov ecx, dword ptr [edx + ebp + 4]
// 00405214  8b442420             mov eax, dword ptr [esp + 0x20]
// 00405218  8b30                 mov esi, dword ptr [eax]
// 0040521a  03d5                 add edx, ebp
// 0040521c  8b12                 mov edx, dword ptr [edx]
// 0040521e  03c9                 add ecx, ecx
// 00405220  83f904               cmp ecx, 4
// 00405223  7214                 jb 0x405239
// 00405225  8b02                 mov eax, dword ptr [edx]
// 00405227  3b06                 cmp eax, dword ptr [esi]
// 00405229  7532                 jne 0x40525d
// 0040522b  83e904               sub ecx, 4
// 0040522e  83c604               add esi, 4
// 00405231  83c204               add edx, 4
// 00405234  83f904               cmp ecx, 4
// 00405237  73ec                 jae 0x405225
// 00405239  85c9                 test ecx, ecx
// 0040523b  7451                 je 0x40528e
// 0040523d  8a06                 mov al, byte ptr [esi]
// 0040523f  3a02                 cmp al, byte ptr [edx]
// 00405241  751a                 jne 0x40525d
// 00405243  83f901               cmp ecx, 1
// 00405246  7646                 jbe 0x40528e
// 00405248  8a4601               mov al, byte ptr [esi + 1]
// 0040524b  3a4201               cmp al, byte ptr [edx + 1]
// 0040524e  750d                 jne 0x40525d
// 00405250  83f902               cmp ecx, 2
// 00405253  7639                 jbe 0x40528e
// 00405255  8a4e02               mov cl, byte ptr [esi + 2]
// 00405258  3a4a02               cmp cl, byte ptr [edx + 2]
// 0040525b  7431                 je 0x40528e
// 0040525d  836c24280c           sub dword ptr [esp + 0x28], 0xc
// 00405262  4f                   dec edi
// 00405263  83ed0c               sub ebp, 0xc
// 00405266  85ff                 test edi, edi
// 00405268  7d97                 jge 0x405201
// 0040526a  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0040526e  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00405271  8b08                 mov ecx, dword ptr [eax]
// 00405273  52                   push edx
// 00405274  8b542428             mov edx, dword ptr [esp + 0x28]
// 00405278  52                   push edx
// 00405279  8b542428             mov edx, dword ptr [esp + 0x28]
// 0040527d  52                   push edx
// 0040527e  50                   push eax
// 0040527f  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00405282  ffd0                 call eax
// 00405284  5f                   pop edi
// 00405285  5e                   pop esi
// 00405286  5d                   pop ebp
// 00405287  5b                   pop ebx
// 00405288  83c408               add esp, 8
// 0040528b  c21400               ret 0x14
// 0040528e  8b442414             mov eax, dword ptr [esp + 0x14]
// 00405292  8d147f               lea edx, [edi + edi*2]
// 00405295  8b4c9008             mov ecx, dword ptr [eax + edx*4 + 8]
// 00405299  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0040529d  5f                   pop edi
// 0040529e  5e                   pop esi
// 0040529f  5d                   pop ebp
// 004052a0  890a                 mov dword ptr [edx], ecx
// 004052a2  33c0                 xor eax, eax
// 004052a4  5b                   pop ebx
// 004052a5  83c408               add esp, 8
// 004052a8  c21400               ret 0x14
// library atl-9.0/atl.cpp (function ?GetIDsOfNames@CComTypeInfoHolder@ATL@@QAEJABU_GUID@@PAPA_WIKPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
