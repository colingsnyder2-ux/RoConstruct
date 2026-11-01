// from server: 100% by auto
// roc 2007-03 00418390  unit: seg_00410000  size: 299 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00418390
//
// 00418390  83ec24               sub esp, 0x24
// 00418393  53                   push ebx
// 00418394  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00418398  55                   push ebp
// 00418399  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 0041839d  56                   push esi
// 0041839e  8b742434             mov esi, dword ptr [esp + 0x34]
// 004183a2  8b5618               mov edx, dword ptr [esi + 0x18]
// 004183a5  8b4604               mov eax, dword ptr [esi + 4]
// 004183a8  57                   push edi
// 004183a9  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 004183ad  33c9                 xor ecx, ecx
// 004183af  51                   push ecx
// 004183b0  894c2424             mov dword ptr [esp + 0x24], ecx
// 004183b4  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004183b8  894c2428             mov dword ptr [esp + 0x28], ecx
// 004183bc  8d4c243c             lea ecx, [esp + 0x3c]
// 004183c0  51                   push ecx
// 004183c1  89542444             mov dword ptr [esp + 0x44], edx
// 004183c5  55                   push ebp
// 004183c6  8d54241c             lea edx, [esp + 0x1c]
// 004183ca  57                   push edi
// 004183cb  895618               mov dword ptr [esi + 0x18], edx
// 004183ce  8b16                 mov edx, dword ptr [esi]
// 004183d0  8b12                 mov edx, dword ptr [edx]
// 004183d2  53                   push ebx
// 004183d3  50                   push eax
// 004183d4  8bce                 mov ecx, esi
// 004183d6  c744244424000000     mov dword ptr [esp + 0x44], 0x24
// 004183de  c744244801000000     mov dword ptr [esp + 0x48], 1
// 004183e6  89442428             mov dword ptr [esp + 0x28], eax
// 004183ea  895c242c             mov dword ptr [esp + 0x2c], ebx
// 004183ee  897c2430             mov dword ptr [esp + 0x30], edi
// 004183f2  896c2434             mov dword ptr [esp + 0x34], ebp
// 004183f6  ffd2                 call edx
// 004183f8  85c0                 test eax, eax
// 004183fa  7574                 jne 0x418470
// 004183fc  81fb82000000         cmp ebx, 0x82
// 00418402  8b4604               mov eax, dword ptr [esi + 4]
// 00418405  7414                 je 0x41841b
// 00418407  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0041840a  55                   push ebp
// 0041840b  57                   push edi
// 0041840c  53                   push ebx
// 0041840d  50                   push eax
// 0041840e  51                   push ecx
// 0041840f  ff1508ed7700         call dword ptr [0x77ed08]
// 00418415  89442438             mov dword ptr [esp + 0x38], eax
// 00418419  eb55                 jmp 0x418470
// 0041841b  8b1d04ed7700         mov ebx, dword ptr [0x77ed04]
// 00418421  6afc                 push -4
// 00418423  50                   push eax
// 00418424  ffd3                 call ebx
// 00418426  8b5604               mov edx, dword ptr [esi + 4]
// 00418429  55                   push ebp
// 0041842a  57                   push edi
// 0041842b  6882000000           push 0x82
// 00418430  8944244c             mov dword ptr [esp + 0x4c], eax
// 00418434  8b4620               mov eax, dword ptr [esi + 0x20]
// 00418437  52                   push edx
// 00418438  50                   push eax
// 00418439  ff1508ed7700         call dword ptr [0x77ed08]
// 0041843f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00418442  3b0dfcec7700         cmp ecx, dword ptr [0x77ecfc]
// 00418448  89442438             mov dword ptr [esp + 0x38], eax
// 0041844c  741e                 je 0x41846c
// 0041844e  8b4604               mov eax, dword ptr [esi + 4]
// 00418451  6afc                 push -4
// 00418453  50                   push eax
// 00418454  ffd3                 call ebx
// 00418456  3b442440             cmp eax, dword ptr [esp + 0x40]
// 0041845a  7510                 jne 0x41846c
// 0041845c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0041845f  8b4604               mov eax, dword ptr [esi + 4]
// 00418462  52                   push edx
// 00418463  6afc                 push -4
// 00418465  50                   push eax
// 00418466  ff15e8ec7700         call dword ptr [0x77ece8]
// 0041846c  834e1c01             or dword ptr [esi + 0x1c], 1
// 00418470  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00418473  a801                 test al, 1
// 00418475  742f                 je 0x4184a6
// 00418477  33d2                 xor edx, edx
// 00418479  3954243c             cmp dword ptr [esp + 0x3c], edx
// 0041847d  7527                 jne 0x4184a6
// 0041847f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00418482  83e0fe               and eax, 0xfffffffe
// 00418485  895604               mov dword ptr [esi + 4], edx
// 00418488  895618               mov dword ptr [esi + 0x18], edx
// 0041848b  8b16                 mov edx, dword ptr [esi]
// 0041848d  89461c               mov dword ptr [esi + 0x1c], eax
// 00418490  8b420c               mov eax, dword ptr [edx + 0xc]
// 00418493  51                   push ecx
// 00418494  8bce                 mov ecx, esi
// 00418496  ffd0                 call eax
// 00418498  8b442438             mov eax, dword ptr [esp + 0x38]
// 0041849c  5f                   pop edi
// 0041849d  5e                   pop esi
// 0041849e  5d                   pop ebp
// 0041849f  5b                   pop ebx
// 004184a0  83c424               add esp, 0x24
// 004184a3  c21000               ret 0x10
// 004184a6  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004184aa  8b442438             mov eax, dword ptr [esp + 0x38]
// 004184ae  5f                   pop edi
// 004184af  894e18               mov dword ptr [esi + 0x18], ecx
// 004184b2  5e                   pop esi
// 004184b3  5d                   pop ebp
// 004184b4  5b                   pop ebx
// 004184b5  83c424               add esp, 0x24
// 004184b8  c21000               ret 0x10
// library atl-8.0/atl.cpp (function ?WindowProc@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@SGJPAUHWND__@@IIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
