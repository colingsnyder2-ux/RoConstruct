// from server: 100% by auto
// roc 2012-06 00425a80  unit: RBX::FunctionMarshaller  size: 299 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00425a80
//
// 00425a80  83ec24               sub esp, 0x24
// 00425a83  53                   push ebx
// 00425a84  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00425a88  55                   push ebp
// 00425a89  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 00425a8d  56                   push esi
// 00425a8e  8b742434             mov esi, dword ptr [esp + 0x34]
// 00425a92  8b5618               mov edx, dword ptr [esi + 0x18]
// 00425a95  8b4604               mov eax, dword ptr [esi + 4]
// 00425a98  57                   push edi
// 00425a99  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00425a9d  33c9                 xor ecx, ecx
// 00425a9f  51                   push ecx
// 00425aa0  894c2424             mov dword ptr [esp + 0x24], ecx
// 00425aa4  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00425aa8  894c2428             mov dword ptr [esp + 0x28], ecx
// 00425aac  8d4c243c             lea ecx, [esp + 0x3c]
// 00425ab0  51                   push ecx
// 00425ab1  89542444             mov dword ptr [esp + 0x44], edx
// 00425ab5  55                   push ebp
// 00425ab6  8d54241c             lea edx, [esp + 0x1c]
// 00425aba  57                   push edi
// 00425abb  895618               mov dword ptr [esi + 0x18], edx
// 00425abe  8b16                 mov edx, dword ptr [esi]
// 00425ac0  8b12                 mov edx, dword ptr [edx]
// 00425ac2  53                   push ebx
// 00425ac3  50                   push eax
// 00425ac4  8bce                 mov ecx, esi
// 00425ac6  c744244424000000     mov dword ptr [esp + 0x44], 0x24
// 00425ace  c744244801000000     mov dword ptr [esp + 0x48], 1
// 00425ad6  89442428             mov dword ptr [esp + 0x28], eax
// 00425ada  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00425ade  897c2430             mov dword ptr [esp + 0x30], edi
// 00425ae2  896c2434             mov dword ptr [esp + 0x34], ebp
// 00425ae6  ffd2                 call edx
// 00425ae8  85c0                 test eax, eax
// 00425aea  7574                 jne 0x425b60
// 00425aec  8b4604               mov eax, dword ptr [esi + 4]
// 00425aef  81fb82000000         cmp ebx, 0x82
// 00425af5  7414                 je 0x425b0b
// 00425af7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00425afa  55                   push ebp
// 00425afb  57                   push edi
// 00425afc  53                   push ebx
// 00425afd  50                   push eax
// 00425afe  51                   push ecx
// 00425aff  ff15c03ab200         call dword ptr [0xb23ac0]
// 00425b05  89442438             mov dword ptr [esp + 0x38], eax
// 00425b09  eb55                 jmp 0x425b60
// 00425b0b  8b1dbc3ab200         mov ebx, dword ptr [0xb23abc]
// 00425b11  6afc                 push -4
// 00425b13  50                   push eax
// 00425b14  ffd3                 call ebx
// 00425b16  8b5604               mov edx, dword ptr [esi + 4]
// 00425b19  55                   push ebp
// 00425b1a  57                   push edi
// 00425b1b  6882000000           push 0x82
// 00425b20  8944244c             mov dword ptr [esp + 0x4c], eax
// 00425b24  8b4620               mov eax, dword ptr [esi + 0x20]
// 00425b27  52                   push edx
// 00425b28  50                   push eax
// 00425b29  ff15c03ab200         call dword ptr [0xb23ac0]
// 00425b2f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00425b32  89442438             mov dword ptr [esp + 0x38], eax
// 00425b36  3b0db43ab200         cmp ecx, dword ptr [0xb23ab4]
// 00425b3c  741e                 je 0x425b5c
// 00425b3e  8b4604               mov eax, dword ptr [esi + 4]
// 00425b41  6afc                 push -4
// 00425b43  50                   push eax
// 00425b44  ffd3                 call ebx
// 00425b46  3b442440             cmp eax, dword ptr [esp + 0x40]
// 00425b4a  7510                 jne 0x425b5c
// 00425b4c  8b5620               mov edx, dword ptr [esi + 0x20]
// 00425b4f  8b4604               mov eax, dword ptr [esi + 4]
// 00425b52  52                   push edx
// 00425b53  6afc                 push -4
// 00425b55  50                   push eax
// 00425b56  ff15943ab200         call dword ptr [0xb23a94]
// 00425b5c  834e1c01             or dword ptr [esi + 0x1c], 1
// 00425b60  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00425b63  a801                 test al, 1
// 00425b65  742f                 je 0x425b96
// 00425b67  33d2                 xor edx, edx
// 00425b69  3954243c             cmp dword ptr [esp + 0x3c], edx
// 00425b6d  7527                 jne 0x425b96
// 00425b6f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00425b72  83e0fe               and eax, 0xfffffffe
// 00425b75  895604               mov dword ptr [esi + 4], edx
// 00425b78  895618               mov dword ptr [esi + 0x18], edx
// 00425b7b  8b16                 mov edx, dword ptr [esi]
// 00425b7d  89461c               mov dword ptr [esi + 0x1c], eax
// 00425b80  8b420c               mov eax, dword ptr [edx + 0xc]
// 00425b83  51                   push ecx
// 00425b84  8bce                 mov ecx, esi
// 00425b86  ffd0                 call eax
// 00425b88  8b442438             mov eax, dword ptr [esp + 0x38]
// 00425b8c  5f                   pop edi
// 00425b8d  5e                   pop esi
// 00425b8e  5d                   pop ebp
// 00425b8f  5b                   pop ebx
// 00425b90  83c424               add esp, 0x24
// 00425b93  c21000               ret 0x10
// 00425b96  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00425b9a  8b442438             mov eax, dword ptr [esp + 0x38]
// 00425b9e  5f                   pop edi
// 00425b9f  894e18               mov dword ptr [esi + 0x18], ecx
// 00425ba2  5e                   pop esi
// 00425ba3  5d                   pop ebp
// 00425ba4  5b                   pop ebx
// 00425ba5  83c424               add esp, 0x24
// 00425ba8  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?WindowProc@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@SGJPAUHWND__@@IIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
