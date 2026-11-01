// from server: 100% by auto
// roc 2007-08 00416e60  unit: VCLuaFunction::?$CComObject  size: 299 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00416e60
//
// 00416e60  83ec24               sub esp, 0x24
// 00416e63  53                   push ebx
// 00416e64  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00416e68  55                   push ebp
// 00416e69  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 00416e6d  56                   push esi
// 00416e6e  8b742434             mov esi, dword ptr [esp + 0x34]
// 00416e72  8b5618               mov edx, dword ptr [esi + 0x18]
// 00416e75  8b4604               mov eax, dword ptr [esi + 4]
// 00416e78  57                   push edi
// 00416e79  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00416e7d  33c9                 xor ecx, ecx
// 00416e7f  51                   push ecx
// 00416e80  894c2424             mov dword ptr [esp + 0x24], ecx
// 00416e84  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00416e88  894c2428             mov dword ptr [esp + 0x28], ecx
// 00416e8c  8d4c243c             lea ecx, [esp + 0x3c]
// 00416e90  51                   push ecx
// 00416e91  89542444             mov dword ptr [esp + 0x44], edx
// 00416e95  55                   push ebp
// 00416e96  8d54241c             lea edx, [esp + 0x1c]
// 00416e9a  57                   push edi
// 00416e9b  895618               mov dword ptr [esi + 0x18], edx
// 00416e9e  8b16                 mov edx, dword ptr [esi]
// 00416ea0  8b12                 mov edx, dword ptr [edx]
// 00416ea2  53                   push ebx
// 00416ea3  50                   push eax
// 00416ea4  8bce                 mov ecx, esi
// 00416ea6  c744244424000000     mov dword ptr [esp + 0x44], 0x24
// 00416eae  c744244801000000     mov dword ptr [esp + 0x48], 1
// 00416eb6  89442428             mov dword ptr [esp + 0x28], eax
// 00416eba  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00416ebe  897c2430             mov dword ptr [esp + 0x30], edi
// 00416ec2  896c2434             mov dword ptr [esp + 0x34], ebp
// 00416ec6  ffd2                 call edx
// 00416ec8  85c0                 test eax, eax
// 00416eca  7574                 jne 0x416f40
// 00416ecc  81fb82000000         cmp ebx, 0x82
// 00416ed2  8b4604               mov eax, dword ptr [esi + 4]
// 00416ed5  7414                 je 0x416eeb
// 00416ed7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00416eda  55                   push ebp
// 00416edb  57                   push edi
// 00416edc  53                   push ebx
// 00416edd  50                   push eax
// 00416ede  51                   push ecx
// 00416edf  ff1538ec7700         call dword ptr [0x77ec38]
// 00416ee5  89442438             mov dword ptr [esp + 0x38], eax
// 00416ee9  eb55                 jmp 0x416f40
// 00416eeb  8b1d34ec7700         mov ebx, dword ptr [0x77ec34]
// 00416ef1  6afc                 push -4
// 00416ef3  50                   push eax
// 00416ef4  ffd3                 call ebx
// 00416ef6  8b5604               mov edx, dword ptr [esi + 4]
// 00416ef9  55                   push ebp
// 00416efa  57                   push edi
// 00416efb  6882000000           push 0x82
// 00416f00  8944244c             mov dword ptr [esp + 0x4c], eax
// 00416f04  8b4620               mov eax, dword ptr [esi + 0x20]
// 00416f07  52                   push edx
// 00416f08  50                   push eax
// 00416f09  ff1538ec7700         call dword ptr [0x77ec38]
// 00416f0f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00416f12  3b0d2cec7700         cmp ecx, dword ptr [0x77ec2c]
// 00416f18  89442438             mov dword ptr [esp + 0x38], eax
// 00416f1c  741e                 je 0x416f3c
// 00416f1e  8b4604               mov eax, dword ptr [esi + 4]
// 00416f21  6afc                 push -4
// 00416f23  50                   push eax
// 00416f24  ffd3                 call ebx
// 00416f26  3b442440             cmp eax, dword ptr [esp + 0x40]
// 00416f2a  7510                 jne 0x416f3c
// 00416f2c  8b5620               mov edx, dword ptr [esi + 0x20]
// 00416f2f  8b4604               mov eax, dword ptr [esi + 4]
// 00416f32  52                   push edx
// 00416f33  6afc                 push -4
// 00416f35  50                   push eax
// 00416f36  ff1518ec7700         call dword ptr [0x77ec18]
// 00416f3c  834e1c01             or dword ptr [esi + 0x1c], 1
// 00416f40  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00416f43  a801                 test al, 1
// 00416f45  742f                 je 0x416f76
// 00416f47  33d2                 xor edx, edx
// 00416f49  3954243c             cmp dword ptr [esp + 0x3c], edx
// 00416f4d  7527                 jne 0x416f76
// 00416f4f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00416f52  83e0fe               and eax, 0xfffffffe
// 00416f55  895604               mov dword ptr [esi + 4], edx
// 00416f58  895618               mov dword ptr [esi + 0x18], edx
// 00416f5b  8b16                 mov edx, dword ptr [esi]
// 00416f5d  89461c               mov dword ptr [esi + 0x1c], eax
// 00416f60  8b420c               mov eax, dword ptr [edx + 0xc]
// 00416f63  51                   push ecx
// 00416f64  8bce                 mov ecx, esi
// 00416f66  ffd0                 call eax
// 00416f68  8b442438             mov eax, dword ptr [esp + 0x38]
// 00416f6c  5f                   pop edi
// 00416f6d  5e                   pop esi
// 00416f6e  5d                   pop ebp
// 00416f6f  5b                   pop ebx
// 00416f70  83c424               add esp, 0x24
// 00416f73  c21000               ret 0x10
// 00416f76  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00416f7a  8b442438             mov eax, dword ptr [esp + 0x38]
// 00416f7e  5f                   pop edi
// 00416f7f  894e18               mov dword ptr [esi + 0x18], ecx
// 00416f82  5e                   pop esi
// 00416f83  5d                   pop ebp
// 00416f84  5b                   pop ebx
// 00416f85  83c424               add esp, 0x24
// 00416f88  c21000               ret 0x10
// library atl-8.0/atl.cpp (function ?WindowProc@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@SGJPAUHWND__@@IIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
