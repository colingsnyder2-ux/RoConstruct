// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00526560  unit: G3D::Line  size: 631 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00526560
//
// 00526560  83ec34               sub esp, 0x34
// 00526563  53                   push ebx
// 00526564  55                   push ebp
// 00526565  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 00526569  8bd9                 mov ebx, ecx
// 0052656b  33c9                 xor ecx, ecx
// 0052656d  56                   push esi
// 0052656e  8bf2                 mov esi, edx
// 00526570  894f0c               mov dword ptr [edi + 0xc], ecx
// 00526573  894f08               mov dword ptr [edi + 8], ecx
// 00526576  894f10               mov dword ptr [edi + 0x10], ecx
// 00526579  890f                 mov dword ptr [edi], ecx
// 0052657b  83f8ff               cmp eax, -1
// 0052657e  750e                 jne 0x52658e
// 00526580  5e                   pop esi
// 00526581  892f                 mov dword ptr [edi], ebp
// 00526583  5d                   pop ebp
// 00526584  895f04               mov dword ptr [edi + 4], ebx
// 00526587  8bc3                 mov eax, ebx
// 00526589  5b                   pop ebx
// 0052658a  83c434               add esp, 0x34
// 0052658d  c3                   ret 
// 0052658e  83f803               cmp eax, 3
// 00526591  7c1f                 jl 0x5265b2
// 00526593  50                   push eax
// 00526594  8d442410             lea eax, [esp + 0x10]
// 00526598  68c0b38200           push 0x82b3c0
// 0052659d  50                   push eax
// 0052659e  ff1530288000         call dword ptr [0x802830]
// 005265a4  8d4c2418             lea ecx, [esp + 0x18]
// 005265a8  51                   push ecx
// 005265a9  56                   push esi
// 005265aa  e8a1340000           call 0x529a50
// 005265af  83c414               add esp, 0x14
// 005265b2  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 005265b8  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 005265be  895e78               mov dword ptr [esi + 0x78], ebx
// 005265c1  896e74               mov dword ptr [esi + 0x74], ebp
// 005265c4  899684000000         mov dword ptr [esi + 0x84], edx
// 005265ca  898680000000         mov dword ptr [esi + 0x80], eax
// 005265d0  6a00                 push 0
// 005265d2  8d4674               lea eax, [esi + 0x74]
// 005265d5  50                   push eax
// 005265d6  e815ff2700           call 0x7a64f0
// 005265db  85c0                 test eax, eax
// 005265dd  741b                 je 0x5265fa
// 005265df  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 005265e5  85c0                 test eax, eax
// 005265e7  7403                 je 0x5265ec
// 005265e9  50                   push eax
// 005265ea  eb05                 jmp 0x5265f1
// 005265ec  68108e8200           push 0x828e10
// 005265f1  56                   push esi
// 005265f2  e8b9330000           call 0x5299b0
// 005265f7  83c408               add esp, 8
// 005265fa  83be8400000000       cmp dword ptr [esi + 0x84], 0
// 00526601  0f85af000000         jne 0x5266b6
// 00526607  837e7800             cmp dword ptr [esi + 0x78], 0
// 0052660b  0f84af000000         je 0x5266c0
// 00526611  8b4708               mov eax, dword ptr [edi + 8]
// 00526614  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00526617  3bc5                 cmp eax, ebp
// 00526619  7c4a                 jl 0x526665
// 0052661b  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 0052661e  83c004               add eax, 4
// 00526621  89470c               mov dword ptr [edi + 0xc], eax
// 00526624  85db                 test ebx, ebx
// 00526626  742c                 je 0x526654
// 00526628  8d0c8500000000       lea ecx, [eax*4]
// 0052662f  51                   push ecx
// 00526630  56                   push esi
// 00526631  e86a3e0000           call 0x52a4a0
// 00526636  8d14ad00000000       lea edx, [ebp*4]
// 0052663d  52                   push edx
// 0052663e  53                   push ebx
// 0052663f  50                   push eax
// 00526640  894710               mov dword ptr [edi + 0x10], eax
// 00526643  e898b11700           call 0x6a17e0
// 00526648  53                   push ebx
// 00526649  56                   push esi
// 0052664a  e8b13e0000           call 0x52a500
// 0052664f  83c41c               add esp, 0x1c
// 00526652  eb11                 jmp 0x526665
// 00526654  03c0                 add eax, eax
// 00526656  03c0                 add eax, eax
// 00526658  50                   push eax
// 00526659  56                   push esi
// 0052665a  e8413e0000           call 0x52a4a0
// 0052665f  83c408               add esp, 8
// 00526662  894710               mov dword ptr [edi + 0x10], eax
// 00526665  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0052666b  51                   push ecx
// 0052666c  56                   push esi
// 0052666d  e82e3e0000           call 0x52a4a0
// 00526672  8b5708               mov edx, dword ptr [edi + 8]
// 00526675  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00526678  890491               mov dword ptr [ecx + edx*4], eax
// 0052667b  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 00526681  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 00526687  8b4f08               mov ecx, dword ptr [edi + 8]
// 0052668a  52                   push edx
// 0052668b  8b5710               mov edx, dword ptr [edi + 0x10]
// 0052668e  50                   push eax
// 0052668f  8b048a               mov eax, dword ptr [edx + ecx*4]
// 00526692  50                   push eax
// 00526693  e848b11700           call 0x6a17e0
// 00526698  83c414               add esp, 0x14
// 0052669b  ff4708               inc dword ptr [edi + 8]
// 0052669e  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 005266a4  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 005266aa  898e84000000         mov dword ptr [esi + 0x84], ecx
// 005266b0  899680000000         mov dword ptr [esi + 0x80], edx
// 005266b6  837e7800             cmp dword ptr [esi + 0x78], 0
// 005266ba  0f8510ffffff         jne 0x5265d0
// 005266c0  6a04                 push 4
// 005266c2  8d4674               lea eax, [esi + 0x74]
// 005266c5  50                   push eax
// 005266c6  e825fe2700           call 0x7a64f0
// 005266cb  85c0                 test eax, eax
// 005266cd  0f85b2000000         jne 0x526785
// 005266d3  398684000000         cmp dword ptr [esi + 0x84], eax
// 005266d9  75e5                 jne 0x5266c0
// 005266db  8b4708               mov eax, dword ptr [edi + 8]
// 005266de  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 005266e1  3bc5                 cmp eax, ebp
// 005266e3  7c4a                 jl 0x52672f
// 005266e5  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 005266e8  83c004               add eax, 4
// 005266eb  89470c               mov dword ptr [edi + 0xc], eax
// 005266ee  85db                 test ebx, ebx
// 005266f0  7429                 je 0x52671b
// 005266f2  03c0                 add eax, eax
// 005266f4  03c0                 add eax, eax
// 005266f6  50                   push eax
// 005266f7  56                   push esi
// 005266f8  e8a33d0000           call 0x52a4a0
// 005266fd  8d0cad00000000       lea ecx, [ebp*4]
// 00526704  51                   push ecx
// 00526705  53                   push ebx
// 00526706  50                   push eax
// 00526707  894710               mov dword ptr [edi + 0x10], eax
// 0052670a  e8d1b01700           call 0x6a17e0
// 0052670f  53                   push ebx
// 00526710  56                   push esi
// 00526711  e8ea3d0000           call 0x52a500
// 00526716  83c41c               add esp, 0x1c
// 00526719  eb14                 jmp 0x52672f
// 0052671b  8d148500000000       lea edx, [eax*4]
// 00526722  52                   push edx
// 00526723  56                   push esi
// 00526724  e8773d0000           call 0x52a4a0
// 00526729  83c408               add esp, 8
// 0052672c  894710               mov dword ptr [edi + 0x10], eax
// 0052672f  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00526735  50                   push eax
// 00526736  56                   push esi
// 00526737  e8643d0000           call 0x52a4a0
// 0052673c  8b4f08               mov ecx, dword ptr [edi + 8]
// 0052673f  8b5710               mov edx, dword ptr [edi + 0x10]
// 00526742  89048a               mov dword ptr [edx + ecx*4], eax
// 00526745  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0052674b  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 00526751  8b5708               mov edx, dword ptr [edi + 8]
// 00526754  50                   push eax
// 00526755  8b4710               mov eax, dword ptr [edi + 0x10]
// 00526758  51                   push ecx
// 00526759  8b0c90               mov ecx, dword ptr [eax + edx*4]
// 0052675c  51                   push ecx
// 0052675d  e87eb01700           call 0x6a17e0
// 00526762  83c414               add esp, 0x14
// 00526765  ff4708               inc dword ptr [edi + 8]
// 00526768  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 0052676e  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 00526774  899684000000         mov dword ptr [esi + 0x84], edx
// 0052677a  898680000000         mov dword ptr [esi + 0x80], eax
// 00526780  e93bffffff           jmp 0x5266c0
// 00526785  83f801               cmp eax, 1
// 00526788  742c                 je 0x5267b6
// 0052678a  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 00526790  85c0                 test eax, eax
// 00526792  740f                 je 0x5267a3
// 00526794  50                   push eax
// 00526795  56                   push esi
// 00526796  e815320000           call 0x5299b0
// 0052679b  83c408               add esp, 8
// 0052679e  e91dffffff           jmp 0x5266c0
// 005267a3  68108e8200           push 0x828e10
// 005267a8  56                   push esi
// 005267a9  e802320000           call 0x5299b0
// 005267ae  83c408               add esp, 8
// 005267b1  e90affffff           jmp 0x5266c0
// 005267b6  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 005267bc  8b4708               mov eax, dword ptr [edi + 8]
// 005267bf  8bb684000000         mov esi, dword ptr [esi + 0x84]
// 005267c5  0fafc1               imul eax, ecx
// 005267c8  3bf1                 cmp esi, ecx
// 005267ca  7304                 jae 0x5267d0
// 005267cc  2bce                 sub ecx, esi
// 005267ce  03c1                 add eax, ecx
// 005267d0  5e                   pop esi
// 005267d1  5d                   pop ebp
// 005267d2  5b                   pop ebx
// 005267d3  83c434               add esp, 0x34
// 005267d6  c3                   ret 
// library g3d-6.09-png-dll/pngwutil.c (function _png_text_compress)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09-png-dll roc_espclaude_ddbb8d1faaec3a4e.cpp
