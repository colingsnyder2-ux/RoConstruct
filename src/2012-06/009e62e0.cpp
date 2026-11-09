// roc 2012-06 009e62e0  unit: CXTSplitterWnd  size: 601 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e62e0
//
// 009e62e0  56                   push esi
// 009e62e1  8bf1                 mov esi, ecx
// 009e62e3  83befc00000000       cmp dword ptr [esi + 0xfc], 0
// 009e62ea  751a                 jne 0x9e6306
// 009e62ec  8b442410             mov eax, dword ptr [esp + 0x10]
// 009e62f0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009e62f4  8b542408             mov edx, dword ptr [esp + 8]
// 009e62f8  50                   push eax
// 009e62f9  51                   push ecx
// 009e62fa  52                   push edx
// 009e62fb  8bce                 mov ecx, esi
// 009e62fd  e846380b00           call 0xa99b48
// 009e6302  5e                   pop esi
// 009e6303  c20c00               ret 0xc
// 009e6306  ff157c3ab200         call dword ptr [0xb23a7c]
// 009e630c  50                   push eax
// 009e630d  e854c3f9ff           call 0x982666
// 009e6312  3bc6                 cmp eax, esi
// 009e6314  740e                 je 0x9e6324
// 009e6316  8b06                 mov eax, dword ptr [esi]
// 009e6318  8b90b0010000         mov edx, dword ptr [eax + 0x1b0]
// 009e631e  6a00                 push 0
// 009e6320  8bce                 mov ecx, esi
// 009e6322  ffd2                 call edx
// 009e6324  83be9800000000       cmp dword ptr [esi + 0x98], 0
// 009e632b  0f84e1010000         je 0x9e6512
// 009e6331  8b86a0000000         mov eax, dword ptr [esi + 0xa0]
// 009e6337  8b542410             mov edx, dword ptr [esp + 0x10]
// 009e633b  8b8ea4000000         mov ecx, dword ptr [esi + 0xa4]
// 009e6341  53                   push ebx
// 009e6342  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 009e6346  03d8                 add ebx, eax
// 009e6348  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 009e634e  03d1                 add edx, ecx
// 009e6350  3bd0                 cmp edx, eax
// 009e6352  57                   push edi
// 009e6353  895c2414             mov dword ptr [esp + 0x14], ebx
// 009e6357  89542418             mov dword ptr [esp + 0x18], edx
// 009e635b  7c0a                 jl 0x9e6367
// 009e635d  8b86b4000000         mov eax, dword ptr [esi + 0xb4]
// 009e6363  3bd0                 cmp edx, eax
// 009e6365  7e06                 jle 0x9e636d
// 009e6367  8bd0                 mov edx, eax
// 009e6369  89542418             mov dword ptr [esp + 0x18], edx
// 009e636d  8b86a8000000         mov eax, dword ptr [esi + 0xa8]
// 009e6373  3bd8                 cmp ebx, eax
// 009e6375  7c0a                 jl 0x9e6381
// 009e6377  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 009e637d  3bd8                 cmp ebx, eax
// 009e637f  7e06                 jle 0x9e6387
// 009e6381  8bd8                 mov ebx, eax
// 009e6383  895c2414             mov dword ptr [esp + 0x14], ebx
// 009e6387  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 009e638d  83f801               cmp eax, 1
// 009e6390  0f84d5000000         je 0x9e646b
// 009e6396  83f865               cmp eax, 0x65
// 009e6399  7c09                 jl 0x9e63a4
// 009e639b  83f873               cmp eax, 0x73
// 009e639e  0f8ec7000000         jle 0x9e646b
// 009e63a4  83f802               cmp eax, 2
// 009e63a7  0f8498000000         je 0x9e6445
// 009e63ad  3dc9000000           cmp eax, 0xc9
// 009e63b2  7c0b                 jl 0x9e63bf
// 009e63b4  3dd7000000           cmp eax, 0xd7
// 009e63b9  0f8e86000000         jle 0x9e6445
// 009e63bf  83f803               cmp eax, 3
// 009e63c2  7416                 je 0x9e63da
// 009e63c4  3d2d010000           cmp eax, 0x12d
// 009e63c9  0f8cd8000000         jl 0x9e64a7
// 009e63cf  3d0d020000           cmp eax, 0x20d
// 009e63d4  0f8fcd000000         jg 0x9e64a7
// 009e63da  8b1df43ab200         mov ebx, dword ptr [0xb23af4]
// 009e63e0  3996bc000000         cmp dword ptr [esi + 0xbc], edx
// 009e63e6  7430                 je 0x9e6418
// 009e63e8  8b06                 mov eax, dword ptr [esi]
// 009e63ea  8b9058010000         mov edx, dword ptr [eax + 0x158]
// 009e63f0  8dbeb8000000         lea edi, [esi + 0xb8]
// 009e63f6  57                   push edi
// 009e63f7  8bce                 mov ecx, esi
// 009e63f9  ffd2                 call edx
// 009e63fb  8b442418             mov eax, dword ptr [esp + 0x18]
// 009e63ff  2b86bc000000         sub eax, dword ptr [esi + 0xbc]
// 009e6405  50                   push eax
// 009e6406  6a00                 push 0
// 009e6408  57                   push edi
// 009e6409  ffd3                 call ebx
// 009e640b  8b16                 mov edx, dword ptr [esi]
// 009e640d  8b8258010000         mov eax, dword ptr [edx + 0x158]
// 009e6413  57                   push edi
// 009e6414  8bce                 mov ecx, esi
// 009e6416  ffd0                 call eax
// 009e6418  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009e641c  398ec8000000         cmp dword ptr [esi + 0xc8], ecx
// 009e6422  8dbec8000000         lea edi, [esi + 0xc8]
// 009e6428  747d                 je 0x9e64a7
// 009e642a  8b16                 mov edx, dword ptr [esi]
// 009e642c  8b8258010000         mov eax, dword ptr [edx + 0x158]
// 009e6432  57                   push edi
// 009e6433  8bce                 mov ecx, esi
// 009e6435  ffd0                 call eax
// 009e6437  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009e643b  2b0f                 sub ecx, dword ptr [edi]
// 009e643d  6a00                 push 0
// 009e643f  51                   push ecx
// 009e6440  57                   push edi
// 009e6441  ffd3                 call ebx
// 009e6443  eb55                 jmp 0x9e649a
// 009e6445  399eb8000000         cmp dword ptr [esi + 0xb8], ebx
// 009e644b  8dbeb8000000         lea edi, [esi + 0xb8]
// 009e6451  7454                 je 0x9e64a7
// 009e6453  8b16                 mov edx, dword ptr [esi]
// 009e6455  8b8258010000         mov eax, dword ptr [edx + 0x158]
// 009e645b  57                   push edi
// 009e645c  8bce                 mov ecx, esi
// 009e645e  ffd0                 call eax
// 009e6460  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009e6464  2b0f                 sub ecx, dword ptr [edi]
// 009e6466  6a00                 push 0
// 009e6468  51                   push ecx
// 009e6469  eb28                 jmp 0x9e6493
// 009e646b  3996bc000000         cmp dword ptr [esi + 0xbc], edx
// 009e6471  7434                 je 0x9e64a7
// 009e6473  8b16                 mov edx, dword ptr [esi]
// 009e6475  8b8258010000         mov eax, dword ptr [edx + 0x158]
// 009e647b  8dbeb8000000         lea edi, [esi + 0xb8]
// 009e6481  57                   push edi
// 009e6482  8bce                 mov ecx, esi
// 009e6484  ffd0                 call eax
// 009e6486  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 009e648a  2b8ebc000000         sub ecx, dword ptr [esi + 0xbc]
// 009e6490  51                   push ecx
// 009e6491  6a00                 push 0
// 009e6493  57                   push edi
// 009e6494  ff15f43ab200         call dword ptr [0xb23af4]
// 009e649a  8b16                 mov edx, dword ptr [esi]
// 009e649c  8b8258010000         mov eax, dword ptr [edx + 0x158]
// 009e64a2  57                   push edi
// 009e64a3  8bce                 mov ecx, esi
// 009e64a5  ffd0                 call eax
// 009e64a7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 009e64ab  8b542414             mov edx, dword ptr [esp + 0x14]
// 009e64af  51                   push ecx
// 009e64b0  52                   push edx
// 009e64b1  6a01                 push 1
// 009e64b3  8bce                 mov ecx, esi
// 009e64b5  e8f6fdffff           call 0x9e62b0
// 009e64ba  8b442418             mov eax, dword ptr [esp + 0x18]
// 009e64be  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009e64c2  50                   push eax
// 009e64c3  51                   push ecx
// 009e64c4  6a01                 push 1
// 009e64c6  8bce                 mov ecx, esi
// 009e64c8  e875360b00           call 0xa99b42
// 009e64cd  8b960c010000         mov edx, dword ptr [esi + 0x10c]
// 009e64d3  5f                   pop edi
// 009e64d4  5b                   pop ebx
// 009e64d5  3b54240c             cmp edx, dword ptr [esp + 0xc]
// 009e64d9  750c                 jne 0x9e64e7
// 009e64db  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 009e64e1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 009e64e5  744e                 je 0x9e6535
// 009e64e7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 009e64ea  6880010000           push 0x180
// 009e64ef  6a00                 push 0
// 009e64f1  6a00                 push 0
// 009e64f3  51                   push ecx
// 009e64f4  ff15403db200         call dword ptr [0xb23d40]
// 009e64fa  8b54240c             mov edx, dword ptr [esp + 0xc]
// 009e64fe  8b442410             mov eax, dword ptr [esp + 0x10]
// 009e6502  89960c010000         mov dword ptr [esi + 0x10c], edx
// 009e6508  898610010000         mov dword ptr [esi + 0x110], eax
// 009e650e  5e                   pop esi
// 009e650f  c20c00               ret 0xc
// 009e6512  8b442410             mov eax, dword ptr [esp + 0x10]
// 009e6516  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009e651a  8b16                 mov edx, dword ptr [esi]
// 009e651c  8b9290010000         mov edx, dword ptr [edx + 0x190]
// 009e6522  50                   push eax
// 009e6523  51                   push ecx
// 009e6524  8bce                 mov ecx, esi
// 009e6526  ffd2                 call edx
// 009e6528  8b16                 mov edx, dword ptr [esi]
// 009e652a  50                   push eax
// 009e652b  8b82a8010000         mov eax, dword ptr [edx + 0x1a8]
// 009e6531  8bce                 mov ecx, esi
// 009e6533  ffd0                 call eax
// 009e6535  5e                   pop esi
// 009e6536  c20c00               ret 0xc
// copied from an identical function in another client (function ?OnMouseMove@CXTSplitterWnd@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1