// from server: 100% by auto
// roc 2009-12 0088e410  unit: CXTPShortcutManager  size: 341 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088e410
//
// 0088e410  53                   push ebx
// 0088e411  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0088e415  56                   push esi
// 0088e416  57                   push edi
// 0088e417  33ff                 xor edi, edi
// 0088e419  3bdf                 cmp ebx, edi
// 0088e41b  8bf1                 mov esi, ecx
// 0088e41d  7d05                 jge 0x88e424
// 0088e41f  e8e856f6ff           call 0x7f3b0c
// 0088e424  8b442414             mov eax, dword ptr [esp + 0x14]
// 0088e428  3bc7                 cmp eax, edi
// 0088e42a  7c03                 jl 0x88e42f
// 0088e42c  894610               mov dword ptr [esi + 0x10], eax
// 0088e42f  3bdf                 cmp ebx, edi
// 0088e431  751f                 jne 0x88e452
// 0088e433  8b4604               mov eax, dword ptr [esi + 4]
// 0088e436  3bc7                 cmp eax, edi
// 0088e438  740c                 je 0x88e446
// 0088e43a  50                   push eax
// 0088e43b  e8c656f6ff           call 0x7f3b06
// 0088e440  83c404               add esp, 4
// 0088e443  897e04               mov dword ptr [esi + 4], edi
// 0088e446  897e0c               mov dword ptr [esi + 0xc], edi
// 0088e449  897e08               mov dword ptr [esi + 8], edi
// 0088e44c  5f                   pop edi
// 0088e44d  5e                   pop esi
// 0088e44e  5b                   pop ebx
// 0088e44f  c20800               ret 8
// 0088e452  8b5604               mov edx, dword ptr [esi + 4]
// 0088e455  55                   push ebp
// 0088e456  3bd7                 cmp edx, edi
// 0088e458  7531                 jne 0x88e48b
// 0088e45a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0088e45d  3bdd                 cmp ebx, ebp
// 0088e45f  7e02                 jle 0x88e463
// 0088e461  8beb                 mov ebp, ebx
// 0088e463  8d7c6d00             lea edi, [ebp + ebp*2]
// 0088e467  03ff                 add edi, edi
// 0088e469  57                   push edi
// 0088e46a  e8d356f6ff           call 0x7f3b42
// 0088e46f  57                   push edi
// 0088e470  6a00                 push 0
// 0088e472  50                   push eax
// 0088e473  894604               mov dword ptr [esi + 4], eax
// 0088e476  e82966f6ff           call 0x7f4aa4
// 0088e47b  83c410               add esp, 0x10
// 0088e47e  896e0c               mov dword ptr [esi + 0xc], ebp
// 0088e481  5d                   pop ebp
// 0088e482  5f                   pop edi
// 0088e483  895e08               mov dword ptr [esi + 8], ebx
// 0088e486  5e                   pop esi
// 0088e487  5b                   pop ebx
// 0088e488  c20800               ret 8
// 0088e48b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0088e48e  3bd9                 cmp ebx, ecx
// 0088e490  7f2f                 jg 0x88e4c1
// 0088e492  8b4e08               mov ecx, dword ptr [esi + 8]
// 0088e495  3bd9                 cmp ebx, ecx
// 0088e497  0f8ebe000000         jle 0x88e55b
// 0088e49d  8bc3                 mov eax, ebx
// 0088e49f  2bc1                 sub eax, ecx
// 0088e4a1  8d0440               lea eax, [eax + eax*2]
// 0088e4a4  03c0                 add eax, eax
// 0088e4a6  50                   push eax
// 0088e4a7  8d0c49               lea ecx, [ecx + ecx*2]
// 0088e4aa  8d144a               lea edx, [edx + ecx*2]
// 0088e4ad  57                   push edi
// 0088e4ae  52                   push edx
// 0088e4af  e8f065f6ff           call 0x7f4aa4
// 0088e4b4  83c40c               add esp, 0xc
// 0088e4b7  5d                   pop ebp
// 0088e4b8  5f                   pop edi
// 0088e4b9  895e08               mov dword ptr [esi + 8], ebx
// 0088e4bc  5e                   pop esi
// 0088e4bd  5b                   pop ebx
// 0088e4be  c20800               ret 8
// 0088e4c1  8b4610               mov eax, dword ptr [esi + 0x10]
// 0088e4c4  3bc7                 cmp eax, edi
// 0088e4c6  7524                 jne 0x88e4ec
// 0088e4c8  8b4608               mov eax, dword ptr [esi + 8]
// 0088e4cb  99                   cdq 
// 0088e4cc  83e207               and edx, 7
// 0088e4cf  03c2                 add eax, edx
// 0088e4d1  c1f803               sar eax, 3
// 0088e4d4  83f804               cmp eax, 4
// 0088e4d7  7d07                 jge 0x88e4e0
// 0088e4d9  b804000000           mov eax, 4
// 0088e4de  eb0c                 jmp 0x88e4ec
// 0088e4e0  3d00040000           cmp eax, 0x400
// 0088e4e5  7e05                 jle 0x88e4ec
// 0088e4e7  b800040000           mov eax, 0x400
// 0088e4ec  8d3c01               lea edi, [ecx + eax]
// 0088e4ef  3bdf                 cmp ebx, edi
// 0088e4f1  7d06                 jge 0x88e4f9
// 0088e4f3  897c2414             mov dword ptr [esp + 0x14], edi
// 0088e4f7  eb06                 jmp 0x88e4ff
// 0088e4f9  895c2414             mov dword ptr [esp + 0x14], ebx
// 0088e4fd  8bfb                 mov edi, ebx
// 0088e4ff  3bf9                 cmp edi, ecx
// 0088e501  7d05                 jge 0x88e508
// 0088e503  e80456f6ff           call 0x7f3b0c
// 0088e508  8d3c7f               lea edi, [edi + edi*2]
// 0088e50b  03ff                 add edi, edi
// 0088e50d  57                   push edi
// 0088e50e  e82f56f6ff           call 0x7f3b42
// 0088e513  8b4e04               mov ecx, dword ptr [esi + 4]
// 0088e516  8be8                 mov ebp, eax
// 0088e518  8b4608               mov eax, dword ptr [esi + 8]
// 0088e51b  8d0440               lea eax, [eax + eax*2]
// 0088e51e  03c0                 add eax, eax
// 0088e520  50                   push eax
// 0088e521  51                   push ecx
// 0088e522  57                   push edi
// 0088e523  55                   push ebp
// 0088e524  e87746b7ff           call 0x402ba0
// 0088e529  8b4e08               mov ecx, dword ptr [esi + 8]
// 0088e52c  8bc3                 mov eax, ebx
// 0088e52e  2bc1                 sub eax, ecx
// 0088e530  8d1440               lea edx, [eax + eax*2]
// 0088e533  03d2                 add edx, edx
// 0088e535  52                   push edx
// 0088e536  8d0449               lea eax, [ecx + ecx*2]
// 0088e539  8d4c4500             lea ecx, [ebp + eax*2]
// 0088e53d  6a00                 push 0
// 0088e53f  51                   push ecx
// 0088e540  e85f65f6ff           call 0x7f4aa4
// 0088e545  8b5604               mov edx, dword ptr [esi + 4]
// 0088e548  52                   push edx
// 0088e549  e8b855f6ff           call 0x7f3b06
// 0088e54e  8b442438             mov eax, dword ptr [esp + 0x38]
// 0088e552  83c424               add esp, 0x24
// 0088e555  896e04               mov dword ptr [esi + 4], ebp
// 0088e558  89460c               mov dword ptr [esi + 0xc], eax
// 0088e55b  5d                   pop ebp
// 0088e55c  5f                   pop edi
// 0088e55d  895e08               mov dword ptr [esi + 8], ebx
// 0088e560  5e                   pop esi
// 0088e561  5b                   pop ebx
// 0088e562  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPShortcutManager.cpp (function ?SetSize@?$CArray@UtagACCEL@@AAU1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPShortcutManager.cpp
