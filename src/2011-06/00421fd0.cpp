// from server: 100% by auto
// roc 2011-06 00421fd0  unit: RBX::FunctionMarshaller  size: 299 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00421fd0
//
// 00421fd0  83ec24               sub esp, 0x24
// 00421fd3  53                   push ebx
// 00421fd4  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00421fd8  55                   push ebp
// 00421fd9  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 00421fdd  56                   push esi
// 00421fde  8b742434             mov esi, dword ptr [esp + 0x34]
// 00421fe2  8b5618               mov edx, dword ptr [esi + 0x18]
// 00421fe5  8b4604               mov eax, dword ptr [esi + 4]
// 00421fe8  57                   push edi
// 00421fe9  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00421fed  33c9                 xor ecx, ecx
// 00421fef  51                   push ecx
// 00421ff0  894c2424             mov dword ptr [esp + 0x24], ecx
// 00421ff4  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00421ff8  894c2428             mov dword ptr [esp + 0x28], ecx
// 00421ffc  8d4c243c             lea ecx, [esp + 0x3c]
// 00422000  51                   push ecx
// 00422001  89542444             mov dword ptr [esp + 0x44], edx
// 00422005  55                   push ebp
// 00422006  8d54241c             lea edx, [esp + 0x1c]
// 0042200a  57                   push edi
// 0042200b  895618               mov dword ptr [esi + 0x18], edx
// 0042200e  8b16                 mov edx, dword ptr [esi]
// 00422010  8b12                 mov edx, dword ptr [edx]
// 00422012  53                   push ebx
// 00422013  50                   push eax
// 00422014  8bce                 mov ecx, esi
// 00422016  c744244424000000     mov dword ptr [esp + 0x44], 0x24
// 0042201e  c744244801000000     mov dword ptr [esp + 0x48], 1
// 00422026  89442428             mov dword ptr [esp + 0x28], eax
// 0042202a  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0042202e  897c2430             mov dword ptr [esp + 0x30], edi
// 00422032  896c2434             mov dword ptr [esp + 0x34], ebp
// 00422036  ffd2                 call edx
// 00422038  85c0                 test eax, eax
// 0042203a  7574                 jne 0x4220b0
// 0042203c  8b4604               mov eax, dword ptr [esi + 4]
// 0042203f  81fb82000000         cmp ebx, 0x82
// 00422045  7414                 je 0x42205b
// 00422047  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0042204a  55                   push ebp
// 0042204b  57                   push edi
// 0042204c  53                   push ebx
// 0042204d  50                   push eax
// 0042204e  51                   push ecx
// 0042204f  ff15941ca400         call dword ptr [0xa41c94]
// 00422055  89442438             mov dword ptr [esp + 0x38], eax
// 00422059  eb55                 jmp 0x4220b0
// 0042205b  8b1d981ca400         mov ebx, dword ptr [0xa41c98]
// 00422061  6afc                 push -4
// 00422063  50                   push eax
// 00422064  ffd3                 call ebx
// 00422066  8b5604               mov edx, dword ptr [esi + 4]
// 00422069  55                   push ebp
// 0042206a  57                   push edi
// 0042206b  6882000000           push 0x82
// 00422070  8944244c             mov dword ptr [esp + 0x4c], eax
// 00422074  8b4620               mov eax, dword ptr [esi + 0x20]
// 00422077  52                   push edx
// 00422078  50                   push eax
// 00422079  ff15941ca400         call dword ptr [0xa41c94]
// 0042207f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00422082  89442438             mov dword ptr [esp + 0x38], eax
// 00422086  3b0da01ca400         cmp ecx, dword ptr [0xa41ca0]
// 0042208c  741e                 je 0x4220ac
// 0042208e  8b4604               mov eax, dword ptr [esi + 4]
// 00422091  6afc                 push -4
// 00422093  50                   push eax
// 00422094  ffd3                 call ebx
// 00422096  3b442440             cmp eax, dword ptr [esp + 0x40]
// 0042209a  7510                 jne 0x4220ac
// 0042209c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0042209f  8b4604               mov eax, dword ptr [esi + 4]
// 004220a2  52                   push edx
// 004220a3  6afc                 push -4
// 004220a5  50                   push eax
// 004220a6  ff15001aa400         call dword ptr [0xa41a00]
// 004220ac  834e1c01             or dword ptr [esi + 0x1c], 1
// 004220b0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004220b3  a801                 test al, 1
// 004220b5  742f                 je 0x4220e6
// 004220b7  33d2                 xor edx, edx
// 004220b9  3954243c             cmp dword ptr [esp + 0x3c], edx
// 004220bd  7527                 jne 0x4220e6
// 004220bf  8b4e04               mov ecx, dword ptr [esi + 4]
// 004220c2  83e0fe               and eax, 0xfffffffe
// 004220c5  895604               mov dword ptr [esi + 4], edx
// 004220c8  895618               mov dword ptr [esi + 0x18], edx
// 004220cb  8b16                 mov edx, dword ptr [esi]
// 004220cd  89461c               mov dword ptr [esi + 0x1c], eax
// 004220d0  8b420c               mov eax, dword ptr [edx + 0xc]
// 004220d3  51                   push ecx
// 004220d4  8bce                 mov ecx, esi
// 004220d6  ffd0                 call eax
// 004220d8  8b442438             mov eax, dword ptr [esp + 0x38]
// 004220dc  5f                   pop edi
// 004220dd  5e                   pop esi
// 004220de  5d                   pop ebp
// 004220df  5b                   pop ebx
// 004220e0  83c424               add esp, 0x24
// 004220e3  c21000               ret 0x10
// 004220e6  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004220ea  8b442438             mov eax, dword ptr [esp + 0x38]
// 004220ee  5f                   pop edi
// 004220ef  894e18               mov dword ptr [esi + 0x18], ecx
// 004220f2  5e                   pop esi
// 004220f3  5d                   pop ebp
// 004220f4  5b                   pop ebx
// 004220f5  83c424               add esp, 0x24
// 004220f8  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?WindowProc@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@SGJPAUHWND__@@IIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
