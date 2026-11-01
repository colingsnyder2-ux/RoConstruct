// from server: 100% by auto
// roc 2009-12 007dd510  unit: RBX::GroupDragTool  size: 576 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dd510
//
// 007dd510  8b442408             mov eax, dword ptr [esp + 8]
// 007dd514  83f80e               cmp eax, 0xe
// 007dd517  0f87f5010000         ja 0x7dd712
// 007dd51d  53                   push ebx
// 007dd51e  56                   push esi
// 007dd51f  57                   push edi
// 007dd520  ff248514d77d00       jmp dword ptr [eax*4 + 0x7dd714]
// 007dd527  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007dd52b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007dd52f  56                   push esi
// 007dd530  53                   push ebx
// 007dd531  e84af3ffff           call 0x7dc880
// 007dd536  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007dd53a  8b4714               mov eax, dword ptr [edi + 0x14]
// 007dd53d  50                   push eax
// 007dd53e  8d4e14               lea ecx, [esi + 0x14]
// 007dd541  51                   push ecx
// 007dd542  53                   push ebx
// 007dd543  e888ebffff           call 0x7dc0d0
// 007dd548  8b16                 mov edx, dword ptr [esi]
// 007dd54a  8917                 mov dword ptr [edi], edx
// 007dd54c  8b4604               mov eax, dword ptr [esi + 4]
// 007dd54f  894704               mov dword ptr [edi + 4], eax
// 007dd552  8b4e08               mov ecx, dword ptr [esi + 8]
// 007dd555  894f08               mov dword ptr [edi + 8], ecx
// 007dd558  8b560c               mov edx, dword ptr [esi + 0xc]
// 007dd55b  89570c               mov dword ptr [edi + 0xc], edx
// 007dd55e  8b4610               mov eax, dword ptr [esi + 0x10]
// 007dd561  894710               mov dword ptr [edi + 0x10], eax
// 007dd564  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007dd567  83c414               add esp, 0x14
// 007dd56a  894f14               mov dword ptr [edi + 0x14], ecx
// 007dd56d  5f                   pop edi
// 007dd56e  5e                   pop esi
// 007dd56f  5b                   pop ebx
// 007dd570  c3                   ret 
// 007dd571  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007dd575  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007dd579  56                   push esi
// 007dd57a  53                   push ebx
// 007dd57b  e800f3ffff           call 0x7dc880
// 007dd580  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007dd584  8b5710               mov edx, dword ptr [edi + 0x10]
// 007dd587  52                   push edx
// 007dd588  8d4610               lea eax, [esi + 0x10]
// 007dd58b  50                   push eax
// 007dd58c  53                   push ebx
// 007dd58d  e83eebffff           call 0x7dc0d0
// 007dd592  8b0e                 mov ecx, dword ptr [esi]
// 007dd594  890f                 mov dword ptr [edi], ecx
// 007dd596  8b5604               mov edx, dword ptr [esi + 4]
// 007dd599  895704               mov dword ptr [edi + 4], edx
// 007dd59c  8b4608               mov eax, dword ptr [esi + 8]
// 007dd59f  894708               mov dword ptr [edi + 8], eax
// 007dd5a2  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007dd5a5  894f0c               mov dword ptr [edi + 0xc], ecx
// 007dd5a8  8b5610               mov edx, dword ptr [esi + 0x10]
// 007dd5ab  895710               mov dword ptr [edi + 0x10], edx
// 007dd5ae  8b4614               mov eax, dword ptr [esi + 0x14]
// 007dd5b1  83c414               add esp, 0x14
// 007dd5b4  894714               mov dword ptr [edi + 0x14], eax
// 007dd5b7  5f                   pop edi
// 007dd5b8  5e                   pop esi
// 007dd5b9  5b                   pop ebx
// 007dd5ba  c3                   ret 
// 007dd5bb  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007dd5bf  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dd5c3  56                   push esi
// 007dd5c4  57                   push edi
// 007dd5c5  e816f7ffff           call 0x7dcce0
// 007dd5ca  83c408               add esp, 8
// 007dd5cd  833e0b               cmp dword ptr [esi], 0xb
// 007dd5d0  754d                 jne 0x7dd61f
// 007dd5d2  8b0f                 mov ecx, dword ptr [edi]
// 007dd5d4  8b410c               mov eax, dword ptr [ecx + 0xc]
// 007dd5d7  8b5608               mov edx, dword ptr [esi + 8]
// 007dd5da  8b0c90               mov ecx, dword ptr [eax + edx*4]
// 007dd5dd  83e13f               and ecx, 0x3f
// 007dd5e0  80f915               cmp cl, 0x15
// 007dd5e3  753a                 jne 0x7dd61f
// 007dd5e5  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007dd5e9  8bc3                 mov eax, ebx
// 007dd5eb  8bcf                 mov ecx, edi
// 007dd5ed  e8aeebffff           call 0x7dc1a0
// 007dd5f2  8b17                 mov edx, dword ptr [edi]
// 007dd5f4  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 007dd5f7  8b4608               mov eax, dword ptr [esi + 8]
// 007dd5fa  8b5308               mov edx, dword ptr [ebx + 8]
// 007dd5fd  8d0481               lea eax, [ecx + eax*4]
// 007dd600  8b08                 mov ecx, dword ptr [eax]
// 007dd602  c1e217               shl edx, 0x17
// 007dd605  81e1ffff7f00         and ecx, 0x7fffff
// 007dd60b  0bd1                 or edx, ecx
// 007dd60d  8910                 mov dword ptr [eax], edx
// 007dd60f  c7030b000000         mov dword ptr [ebx], 0xb
// 007dd615  8b5608               mov edx, dword ptr [esi + 8]
// 007dd618  5f                   pop edi
// 007dd619  5e                   pop esi
// 007dd61a  895308               mov dword ptr [ebx + 8], edx
// 007dd61d  5b                   pop ebx
// 007dd61e  c3                   ret 
// 007dd61f  56                   push esi
// 007dd620  57                   push edi
// 007dd621  e8eaf5ffff           call 0x7dcc10
// 007dd626  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 007dd62a  56                   push esi
// 007dd62b  6a15                 push 0x15
// 007dd62d  e80efcffff           call 0x7dd240
// 007dd632  83c410               add esp, 0x10
// 007dd635  5f                   pop edi
// 007dd636  5e                   pop esi
// 007dd637  5b                   pop ebx
// 007dd638  c3                   ret 
// 007dd639  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007dd63d  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007dd641  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dd645  50                   push eax
// 007dd646  6a0c                 push 0xc
// 007dd648  e8f3fbffff           call 0x7dd240
// 007dd64d  83c408               add esp, 8
// 007dd650  5f                   pop edi
// 007dd651  5e                   pop esi
// 007dd652  5b                   pop ebx
// 007dd653  c3                   ret 
// 007dd654  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007dd658  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007dd65c  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dd660  51                   push ecx
// 007dd661  6a0d                 push 0xd
// 007dd663  e8d8fbffff           call 0x7dd240
// 007dd668  83c408               add esp, 8
// 007dd66b  5f                   pop edi
// 007dd66c  5e                   pop esi
// 007dd66d  5b                   pop ebx
// 007dd66e  c3                   ret 
// 007dd66f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007dd673  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007dd677  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dd67b  52                   push edx
// 007dd67c  6a0e                 push 0xe
// 007dd67e  e8bdfbffff           call 0x7dd240
// 007dd683  83c408               add esp, 8
// 007dd686  5f                   pop edi
// 007dd687  5e                   pop esi
// 007dd688  5b                   pop ebx
// 007dd689  c3                   ret 
// 007dd68a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007dd68e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007dd692  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dd696  50                   push eax
// 007dd697  6a0f                 push 0xf
// 007dd699  e8a2fbffff           call 0x7dd240
// 007dd69e  83c408               add esp, 8
// 007dd6a1  5f                   pop edi
// 007dd6a2  5e                   pop esi
// 007dd6a3  5b                   pop ebx
// 007dd6a4  c3                   ret 
// 007dd6a5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007dd6a9  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007dd6ad  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dd6b1  51                   push ecx
// 007dd6b2  6a10                 push 0x10
// 007dd6b4  e887fbffff           call 0x7dd240
// 007dd6b9  83c408               add esp, 8
// 007dd6bc  5f                   pop edi
// 007dd6bd  5e                   pop esi
// 007dd6be  5b                   pop ebx
// 007dd6bf  c3                   ret 
// 007dd6c0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007dd6c4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007dd6c8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dd6cc  52                   push edx
// 007dd6cd  6a11                 push 0x11
// 007dd6cf  e86cfbffff           call 0x7dd240
// 007dd6d4  83c408               add esp, 8
// 007dd6d7  5f                   pop edi
// 007dd6d8  5e                   pop esi
// 007dd6d9  5b                   pop ebx
// 007dd6da  c3                   ret 
// 007dd6db  6a01                 push 1
// 007dd6dd  6a17                 push 0x17
// 007dd6df  eb1a                 jmp 0x7dd6fb
// 007dd6e1  6a00                 push 0
// 007dd6e3  6a17                 push 0x17
// 007dd6e5  eb14                 jmp 0x7dd6fb
// 007dd6e7  6a01                 push 1
// 007dd6e9  6a18                 push 0x18
// 007dd6eb  eb0e                 jmp 0x7dd6fb
// 007dd6ed  6a01                 push 1
// 007dd6ef  eb08                 jmp 0x7dd6f9
// 007dd6f1  6a00                 push 0
// 007dd6f3  6a18                 push 0x18
// 007dd6f5  eb04                 jmp 0x7dd6fb
// 007dd6f7  6a00                 push 0
// 007dd6f9  6a19                 push 0x19
// 007dd6fb  8b442424             mov eax, dword ptr [esp + 0x24]
// 007dd6ff  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 007dd703  8b742418             mov esi, dword ptr [esp + 0x18]
// 007dd707  e824fcffff           call 0x7dd330
// 007dd70c  83c408               add esp, 8
// 007dd70f  5f                   pop edi
// 007dd710  5e                   pop esi
// 007dd711  5b                   pop ebx
// 007dd712  c3                   ret 
// 007dd713  90                   nop 
// 007dd714  39d6                 cmp esi, edx
// 007dd716  7d00                 jge 0x7dd718
// 007dd718  54                   push esp
// 007dd719  d6                   salc 
// 007dd71a  7d00                 jge 0x7dd71c
// 007dd71c  6f                   outsd dx, dword ptr [esi]
// 007dd71d  d6                   salc 
// 007dd71e  7d00                 jge 0x7dd720
// 007dd720  8ad6                 mov dl, dh
// 007dd722  7d00                 jge 0x7dd724
// 007dd724  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 007dd725  d6                   salc 
// 007dd726  7d00                 jge 0x7dd728
// 007dd728  c0d67d               rcl dh, 0x7d
// 007dd72b  00bbd57d00e1         add byte ptr [ebx - 0x1eff822b], bh
// 007dd731  d6                   salc 
// 007dd732  7d00                 jge 0x7dd734
// 007dd734  dbd6                 fcmovnbe st(0), st(6)
// 007dd736  7d00                 jge 0x7dd738
// 007dd738  e7d6                 out 0xd6, eax
// 007dd73a  7d00                 jge 0x7dd73c
// 007dd73c  ed                   in eax, dx
// 007dd73d  d6                   salc 
// 007dd73e  7d00                 jge 0x7dd740
// 007dd740  f1                   int1 
// 007dd741  d6                   salc 
// 007dd742  7d00                 jge 0x7dd744
// 007dd744  f7d6                 not esi
// 007dd746  7d00                 jge 0x7dd748
// 007dd748  27                   daa 
// 007dd749  d57d                 aad 0x7d
// 007dd74b  0071d5               add byte ptr [ecx - 0x2b], dh
// 007dd74e  7d00                 jge 0x7dd750
// library lua-5.1.1/lcode.c (function _luaK_posfix)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
