// from server: 100% by auto
// roc 2008-06 0041a2d0  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::V?$function::?$holder  size: 299 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041a2d0
//
// 0041a2d0  83ec24               sub esp, 0x24
// 0041a2d3  53                   push ebx
// 0041a2d4  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0041a2d8  55                   push ebp
// 0041a2d9  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 0041a2dd  56                   push esi
// 0041a2de  8b742434             mov esi, dword ptr [esp + 0x34]
// 0041a2e2  8b5618               mov edx, dword ptr [esi + 0x18]
// 0041a2e5  8b4604               mov eax, dword ptr [esi + 4]
// 0041a2e8  57                   push edi
// 0041a2e9  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0041a2ed  33c9                 xor ecx, ecx
// 0041a2ef  51                   push ecx
// 0041a2f0  894c2424             mov dword ptr [esp + 0x24], ecx
// 0041a2f4  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0041a2f8  894c2428             mov dword ptr [esp + 0x28], ecx
// 0041a2fc  8d4c243c             lea ecx, [esp + 0x3c]
// 0041a300  51                   push ecx
// 0041a301  89542444             mov dword ptr [esp + 0x44], edx
// 0041a305  55                   push ebp
// 0041a306  8d54241c             lea edx, [esp + 0x1c]
// 0041a30a  57                   push edi
// 0041a30b  895618               mov dword ptr [esi + 0x18], edx
// 0041a30e  8b16                 mov edx, dword ptr [esi]
// 0041a310  8b12                 mov edx, dword ptr [edx]
// 0041a312  53                   push ebx
// 0041a313  50                   push eax
// 0041a314  8bce                 mov ecx, esi
// 0041a316  c744244424000000     mov dword ptr [esp + 0x44], 0x24
// 0041a31e  c744244801000000     mov dword ptr [esp + 0x48], 1
// 0041a326  89442428             mov dword ptr [esp + 0x28], eax
// 0041a32a  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0041a32e  897c2430             mov dword ptr [esp + 0x30], edi
// 0041a332  896c2434             mov dword ptr [esp + 0x34], ebp
// 0041a336  ffd2                 call edx
// 0041a338  85c0                 test eax, eax
// 0041a33a  7574                 jne 0x41a3b0
// 0041a33c  8b4604               mov eax, dword ptr [esi + 4]
// 0041a33f  81fb82000000         cmp ebx, 0x82
// 0041a345  7414                 je 0x41a35b
// 0041a347  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0041a34a  55                   push ebp
// 0041a34b  57                   push edi
// 0041a34c  53                   push ebx
// 0041a34d  50                   push eax
// 0041a34e  51                   push ecx
// 0041a34f  ff15b82d8000         call dword ptr [0x802db8]
// 0041a355  89442438             mov dword ptr [esp + 0x38], eax
// 0041a359  eb55                 jmp 0x41a3b0
// 0041a35b  8b1dbc2d8000         mov ebx, dword ptr [0x802dbc]
// 0041a361  6afc                 push -4
// 0041a363  50                   push eax
// 0041a364  ffd3                 call ebx
// 0041a366  8b5604               mov edx, dword ptr [esi + 4]
// 0041a369  55                   push ebp
// 0041a36a  57                   push edi
// 0041a36b  6882000000           push 0x82
// 0041a370  8944244c             mov dword ptr [esp + 0x4c], eax
// 0041a374  8b4620               mov eax, dword ptr [esi + 0x20]
// 0041a377  52                   push edx
// 0041a378  50                   push eax
// 0041a379  ff15b82d8000         call dword ptr [0x802db8]
// 0041a37f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0041a382  89442438             mov dword ptr [esp + 0x38], eax
// 0041a386  3b0dc42d8000         cmp ecx, dword ptr [0x802dc4]
// 0041a38c  741e                 je 0x41a3ac
// 0041a38e  8b4604               mov eax, dword ptr [esi + 4]
// 0041a391  6afc                 push -4
// 0041a393  50                   push eax
// 0041a394  ffd3                 call ebx
// 0041a396  3b442440             cmp eax, dword ptr [esp + 0x40]
// 0041a39a  7510                 jne 0x41a3ac
// 0041a39c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0041a39f  8b4604               mov eax, dword ptr [esi + 4]
// 0041a3a2  52                   push edx
// 0041a3a3  6afc                 push -4
// 0041a3a5  50                   push eax
// 0041a3a6  ff15d82d8000         call dword ptr [0x802dd8]
// 0041a3ac  834e1c01             or dword ptr [esi + 0x1c], 1
// 0041a3b0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0041a3b3  a801                 test al, 1
// 0041a3b5  742f                 je 0x41a3e6
// 0041a3b7  33d2                 xor edx, edx
// 0041a3b9  3954243c             cmp dword ptr [esp + 0x3c], edx
// 0041a3bd  7527                 jne 0x41a3e6
// 0041a3bf  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041a3c2  83e0fe               and eax, 0xfffffffe
// 0041a3c5  895604               mov dword ptr [esi + 4], edx
// 0041a3c8  895618               mov dword ptr [esi + 0x18], edx
// 0041a3cb  8b16                 mov edx, dword ptr [esi]
// 0041a3cd  89461c               mov dword ptr [esi + 0x1c], eax
// 0041a3d0  8b420c               mov eax, dword ptr [edx + 0xc]
// 0041a3d3  51                   push ecx
// 0041a3d4  8bce                 mov ecx, esi
// 0041a3d6  ffd0                 call eax
// 0041a3d8  8b442438             mov eax, dword ptr [esp + 0x38]
// 0041a3dc  5f                   pop edi
// 0041a3dd  5e                   pop esi
// 0041a3de  5d                   pop ebp
// 0041a3df  5b                   pop ebx
// 0041a3e0  83c424               add esp, 0x24
// 0041a3e3  c21000               ret 0x10
// 0041a3e6  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0041a3ea  8b442438             mov eax, dword ptr [esp + 0x38]
// 0041a3ee  5f                   pop edi
// 0041a3ef  894e18               mov dword ptr [esi + 0x18], ecx
// 0041a3f2  5e                   pop esi
// 0041a3f3  5d                   pop ebp
// 0041a3f4  5b                   pop ebx
// 0041a3f5  83c424               add esp, 0x24
// 0041a3f8  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?WindowProc@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@SGJPAUHWND__@@IIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
