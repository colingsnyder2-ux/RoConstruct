// from server: 100% by auto
// roc 2009-06 006fb0e0  unit: RBX::GroupDragTool  size: 576 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fb0e0
//
// 006fb0e0  8b442408             mov eax, dword ptr [esp + 8]
// 006fb0e4  83f80e               cmp eax, 0xe
// 006fb0e7  0f87f5010000         ja 0x6fb2e2
// 006fb0ed  53                   push ebx
// 006fb0ee  56                   push esi
// 006fb0ef  57                   push edi
// 006fb0f0  ff2485e4b26f00       jmp dword ptr [eax*4 + 0x6fb2e4]
// 006fb0f7  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006fb0fb  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006fb0ff  56                   push esi
// 006fb100  53                   push ebx
// 006fb101  e84af3ffff           call 0x6fa450
// 006fb106  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fb10a  8b4714               mov eax, dword ptr [edi + 0x14]
// 006fb10d  50                   push eax
// 006fb10e  8d4e14               lea ecx, [esi + 0x14]
// 006fb111  51                   push ecx
// 006fb112  53                   push ebx
// 006fb113  e898ebffff           call 0x6f9cb0
// 006fb118  8b16                 mov edx, dword ptr [esi]
// 006fb11a  8917                 mov dword ptr [edi], edx
// 006fb11c  8b4604               mov eax, dword ptr [esi + 4]
// 006fb11f  894704               mov dword ptr [edi + 4], eax
// 006fb122  8b4e08               mov ecx, dword ptr [esi + 8]
// 006fb125  894f08               mov dword ptr [edi + 8], ecx
// 006fb128  8b560c               mov edx, dword ptr [esi + 0xc]
// 006fb12b  89570c               mov dword ptr [edi + 0xc], edx
// 006fb12e  8b4610               mov eax, dword ptr [esi + 0x10]
// 006fb131  894710               mov dword ptr [edi + 0x10], eax
// 006fb134  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006fb137  83c414               add esp, 0x14
// 006fb13a  894f14               mov dword ptr [edi + 0x14], ecx
// 006fb13d  5f                   pop edi
// 006fb13e  5e                   pop esi
// 006fb13f  5b                   pop ebx
// 006fb140  c3                   ret 
// 006fb141  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006fb145  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006fb149  56                   push esi
// 006fb14a  53                   push ebx
// 006fb14b  e800f3ffff           call 0x6fa450
// 006fb150  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fb154  8b5710               mov edx, dword ptr [edi + 0x10]
// 006fb157  52                   push edx
// 006fb158  8d4610               lea eax, [esi + 0x10]
// 006fb15b  50                   push eax
// 006fb15c  53                   push ebx
// 006fb15d  e84eebffff           call 0x6f9cb0
// 006fb162  8b0e                 mov ecx, dword ptr [esi]
// 006fb164  890f                 mov dword ptr [edi], ecx
// 006fb166  8b5604               mov edx, dword ptr [esi + 4]
// 006fb169  895704               mov dword ptr [edi + 4], edx
// 006fb16c  8b4608               mov eax, dword ptr [esi + 8]
// 006fb16f  894708               mov dword ptr [edi + 8], eax
// 006fb172  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006fb175  894f0c               mov dword ptr [edi + 0xc], ecx
// 006fb178  8b5610               mov edx, dword ptr [esi + 0x10]
// 006fb17b  895710               mov dword ptr [edi + 0x10], edx
// 006fb17e  8b4614               mov eax, dword ptr [esi + 0x14]
// 006fb181  83c414               add esp, 0x14
// 006fb184  894714               mov dword ptr [edi + 0x14], eax
// 006fb187  5f                   pop edi
// 006fb188  5e                   pop esi
// 006fb189  5b                   pop ebx
// 006fb18a  c3                   ret 
// 006fb18b  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006fb18f  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006fb193  56                   push esi
// 006fb194  57                   push edi
// 006fb195  e816f7ffff           call 0x6fa8b0
// 006fb19a  83c408               add esp, 8
// 006fb19d  833e0b               cmp dword ptr [esi], 0xb
// 006fb1a0  754d                 jne 0x6fb1ef
// 006fb1a2  8b0f                 mov ecx, dword ptr [edi]
// 006fb1a4  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006fb1a7  8b5608               mov edx, dword ptr [esi + 8]
// 006fb1aa  8b0c90               mov ecx, dword ptr [eax + edx*4]
// 006fb1ad  83e13f               and ecx, 0x3f
// 006fb1b0  80f915               cmp cl, 0x15
// 006fb1b3  753a                 jne 0x6fb1ef
// 006fb1b5  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006fb1b9  8bc3                 mov eax, ebx
// 006fb1bb  8bcf                 mov ecx, edi
// 006fb1bd  e8beebffff           call 0x6f9d80
// 006fb1c2  8b17                 mov edx, dword ptr [edi]
// 006fb1c4  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 006fb1c7  8b4608               mov eax, dword ptr [esi + 8]
// 006fb1ca  8b5308               mov edx, dword ptr [ebx + 8]
// 006fb1cd  8d0481               lea eax, [ecx + eax*4]
// 006fb1d0  8b08                 mov ecx, dword ptr [eax]
// 006fb1d2  c1e217               shl edx, 0x17
// 006fb1d5  81e1ffff7f00         and ecx, 0x7fffff
// 006fb1db  0bd1                 or edx, ecx
// 006fb1dd  8910                 mov dword ptr [eax], edx
// 006fb1df  c7030b000000         mov dword ptr [ebx], 0xb
// 006fb1e5  8b5608               mov edx, dword ptr [esi + 8]
// 006fb1e8  5f                   pop edi
// 006fb1e9  5e                   pop esi
// 006fb1ea  895308               mov dword ptr [ebx + 8], edx
// 006fb1ed  5b                   pop ebx
// 006fb1ee  c3                   ret 
// 006fb1ef  56                   push esi
// 006fb1f0  57                   push edi
// 006fb1f1  e8eaf5ffff           call 0x6fa7e0
// 006fb1f6  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 006fb1fa  56                   push esi
// 006fb1fb  6a15                 push 0x15
// 006fb1fd  e80efcffff           call 0x6fae10
// 006fb202  83c410               add esp, 0x10
// 006fb205  5f                   pop edi
// 006fb206  5e                   pop esi
// 006fb207  5b                   pop ebx
// 006fb208  c3                   ret 
// 006fb209  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fb20d  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006fb211  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006fb215  50                   push eax
// 006fb216  6a0c                 push 0xc
// 006fb218  e8f3fbffff           call 0x6fae10
// 006fb21d  83c408               add esp, 8
// 006fb220  5f                   pop edi
// 006fb221  5e                   pop esi
// 006fb222  5b                   pop ebx
// 006fb223  c3                   ret 
// 006fb224  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006fb228  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006fb22c  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006fb230  51                   push ecx
// 006fb231  6a0d                 push 0xd
// 006fb233  e8d8fbffff           call 0x6fae10
// 006fb238  83c408               add esp, 8
// 006fb23b  5f                   pop edi
// 006fb23c  5e                   pop esi
// 006fb23d  5b                   pop ebx
// 006fb23e  c3                   ret 
// 006fb23f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006fb243  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006fb247  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006fb24b  52                   push edx
// 006fb24c  6a0e                 push 0xe
// 006fb24e  e8bdfbffff           call 0x6fae10
// 006fb253  83c408               add esp, 8
// 006fb256  5f                   pop edi
// 006fb257  5e                   pop esi
// 006fb258  5b                   pop ebx
// 006fb259  c3                   ret 
// 006fb25a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fb25e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006fb262  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006fb266  50                   push eax
// 006fb267  6a0f                 push 0xf
// 006fb269  e8a2fbffff           call 0x6fae10
// 006fb26e  83c408               add esp, 8
// 006fb271  5f                   pop edi
// 006fb272  5e                   pop esi
// 006fb273  5b                   pop ebx
// 006fb274  c3                   ret 
// 006fb275  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006fb279  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006fb27d  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006fb281  51                   push ecx
// 006fb282  6a10                 push 0x10
// 006fb284  e887fbffff           call 0x6fae10
// 006fb289  83c408               add esp, 8
// 006fb28c  5f                   pop edi
// 006fb28d  5e                   pop esi
// 006fb28e  5b                   pop ebx
// 006fb28f  c3                   ret 
// 006fb290  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006fb294  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006fb298  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006fb29c  52                   push edx
// 006fb29d  6a11                 push 0x11
// 006fb29f  e86cfbffff           call 0x6fae10
// 006fb2a4  83c408               add esp, 8
// 006fb2a7  5f                   pop edi
// 006fb2a8  5e                   pop esi
// 006fb2a9  5b                   pop ebx
// 006fb2aa  c3                   ret 
// 006fb2ab  6a01                 push 1
// 006fb2ad  6a17                 push 0x17
// 006fb2af  eb1a                 jmp 0x6fb2cb
// 006fb2b1  6a00                 push 0
// 006fb2b3  6a17                 push 0x17
// 006fb2b5  eb14                 jmp 0x6fb2cb
// 006fb2b7  6a01                 push 1
// 006fb2b9  6a18                 push 0x18
// 006fb2bb  eb0e                 jmp 0x6fb2cb
// 006fb2bd  6a01                 push 1
// 006fb2bf  eb08                 jmp 0x6fb2c9
// 006fb2c1  6a00                 push 0
// 006fb2c3  6a18                 push 0x18
// 006fb2c5  eb04                 jmp 0x6fb2cb
// 006fb2c7  6a00                 push 0
// 006fb2c9  6a19                 push 0x19
// 006fb2cb  8b442424             mov eax, dword ptr [esp + 0x24]
// 006fb2cf  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 006fb2d3  8b742418             mov esi, dword ptr [esp + 0x18]
// 006fb2d7  e824fcffff           call 0x6faf00
// 006fb2dc  83c408               add esp, 8
// 006fb2df  5f                   pop edi
// 006fb2e0  5e                   pop esi
// 006fb2e1  5b                   pop ebx
// 006fb2e2  c3                   ret 
// 006fb2e3  90                   nop 
// 006fb2e4  09b26f0024b2         or dword ptr [edx - 0x4ddbff91], esi
// 006fb2ea  6f                   outsd dx, dword ptr [esi]
// 006fb2eb  003f                 add byte ptr [edi], bh
// 006fb2ed  b26f                 mov dl, 0x6f
// 006fb2ef  005ab2               add byte ptr [edx - 0x4e], bl
// 006fb2f2  6f                   outsd dx, dword ptr [esi]
// 006fb2f3  0075b2               add byte ptr [ebp - 0x4e], dh
// 006fb2f6  6f                   outsd dx, dword ptr [esi]
// 006fb2f7  0090b26f008b         add byte ptr [eax - 0x74ff904e], dl
// 006fb2fd  b16f                 mov cl, 0x6f
// 006fb2ff  00b1b26f00ab         add byte ptr [ecx - 0x54ff904e], dh
// 006fb305  b26f                 mov dl, 0x6f
// 006fb307  00b7b26f00bd         add byte ptr [edi - 0x42ff904e], dh
// 006fb30d  b26f                 mov dl, 0x6f
// 006fb30f  00c1                 add cl, al
// 006fb311  b26f                 mov dl, 0x6f
// 006fb313  00c7                 add bh, al
// 006fb315  b26f                 mov dl, 0x6f
// 006fb317  00f7                 add bh, dh
// 006fb319  b06f                 mov al, 0x6f
// 006fb31b  0041b1               add byte ptr [ecx - 0x4f], al
// 006fb31e  6f                   outsd dx, dword ptr [esi]
// library lua-5.1.1/lcode.c (function _luaK_posfix)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
