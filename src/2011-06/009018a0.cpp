// from server: 100% by auto
// roc 2011-06 009018a0  unit: CXTButtonTheme  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009018a0
//
// 009018a0  53                   push ebx
// 009018a1  56                   push esi
// 009018a2  57                   push edi
// 009018a3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 009018a7  8bf1                 mov esi, ecx
// 009018a9  8b06                 mov eax, dword ptr [esi]
// 009018ab  8b5014               mov edx, dword ptr [eax + 0x14]
// 009018ae  57                   push edi
// 009018af  ffd2                 call edx
// 009018b1  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 009018b5  85c0                 test eax, eax
// 009018b7  747c                 je 0x901935
// 009018b9  55                   push ebp
// 009018ba  8bcf                 mov ecx, edi
// 009018bc  bd01000000           mov ebp, 1
// 009018c1  e8aa0affff           call 0x8f2370
// 009018c6  3c01                 cmp al, 1
// 009018c8  7505                 jne 0x9018cf
// 009018ca  bd05000000           mov ebp, 5
// 009018cf  83bfa000000000       cmp dword ptr [edi + 0xa0], 0
// 009018d6  750b                 jne 0x9018e3
// 009018d8  ff15381ba400         call dword ptr [0xa41b38]
// 009018de  3b4720               cmp eax, dword ptr [edi + 0x20]
// 009018e1  7505                 jne 0x9018e8
// 009018e3  bd02000000           mov ebp, 2
// 009018e8  f6c301               test bl, 1
// 009018eb  7506                 jne 0x9018f3
// 009018ed  837f7c00             cmp dword ptr [edi + 0x7c], 0
// 009018f1  7405                 je 0x9018f8
// 009018f3  bd03000000           mov ebp, 3
// 009018f8  f6c304               test bl, 4
// 009018fb  7405                 je 0x901902
// 009018fd  bd04000000           mov ebp, 4
// 00901902  8b4634               mov eax, dword ptr [esi + 0x34]
// 00901905  83f8ff               cmp eax, -1
// 00901908  7503                 jne 0x90190d
// 0090190a  8b4630               mov eax, dword ptr [esi + 0x30]
// 0090190d  8d4c2418             lea ecx, [esp + 0x18]
// 00901911  51                   push ecx
// 00901912  68db0e0000           push 0xedb
// 00901917  55                   push ebp
// 00901918  6a01                 push 1
// 0090191a  8d4e74               lea ecx, [esi + 0x74]
// 0090191d  89442428             mov dword ptr [esp + 0x28], eax
// 00901921  e84ab8f7ff           call 0x87d170
// 00901926  5d                   pop ebp
// 00901927  85c0                 test eax, eax
// 00901929  7c0a                 jl 0x901935
// 0090192b  8b442414             mov eax, dword ptr [esp + 0x14]
// 0090192f  5f                   pop edi
// 00901930  5e                   pop esi
// 00901931  5b                   pop ebx
// 00901932  c20800               ret 8
// 00901935  f6c304               test bl, 4
// 00901938  7411                 je 0x90194b
// 0090193a  8b4640               mov eax, dword ptr [esi + 0x40]
// 0090193d  83f8ff               cmp eax, -1
// 00901940  7514                 jne 0x901956
// 00901942  8b463c               mov eax, dword ptr [esi + 0x3c]
// 00901945  5f                   pop edi
// 00901946  5e                   pop esi
// 00901947  5b                   pop ebx
// 00901948  c20800               ret 8
// 0090194b  8b4634               mov eax, dword ptr [esi + 0x34]
// 0090194e  83f8ff               cmp eax, -1
// 00901951  7503                 jne 0x901956
// 00901953  8b4630               mov eax, dword ptr [esi + 0x30]
// 00901956  5f                   pop edi
// 00901957  5e                   pop esi
// 00901958  5b                   pop ebx
// 00901959  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?GetTextColor@CXTButtonTheme@@MAEKIPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
