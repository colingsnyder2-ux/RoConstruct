// from server: 100% by auto
// roc 2007-03 00652270  unit: seg_00650000  size: 328 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652270
//
// 00652270  53                   push ebx
// 00652271  8b1d50ee7700         mov ebx, dword ptr [0x77ee50]
// 00652277  56                   push esi
// 00652278  57                   push edi
// 00652279  6a00                 push 0
// 0065227b  8bf9                 mov edi, ecx
// 0065227d  8b4734               mov eax, dword ptr [edi + 0x34]
// 00652280  8b4020               mov eax, dword ptr [eax + 0x20]
// 00652283  6a00                 push 0
// 00652285  680a110000           push 0x110a
// 0065228a  50                   push eax
// 0065228b  ffd3                 call ebx
// 0065228d  8bf0                 mov esi, eax
// 0065228f  85f6                 test esi, esi
// 00652291  0f84db000000         je 0x652372
// 00652297  55                   push ebp
// 00652298  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0065229c  8d642400             lea esp, [esp]
// 006522a0  8b442414             mov eax, dword ptr [esp + 0x14]
// 006522a4  3bf0                 cmp esi, eax
// 006522a6  7442                 je 0x6522ea
// 006522a8  3bf5                 cmp esi, ebp
// 006522aa  743e                 je 0x6522ea
// 006522ac  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 006522b1  741b                 je 0x6522ce
// 006522b3  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 006522b6  6a02                 push 2
// 006522b8  56                   push esi
// 006522b9  e8c88a0e00           call 0x73ad86
// 006522be  a802                 test al, 2
// 006522c0  740c                 je 0x6522ce
// 006522c2  6a02                 push 2
// 006522c4  6a00                 push 0
// 006522c6  56                   push esi
// 006522c7  8bcf                 mov ecx, edi
// 006522c9  e832faffff           call 0x651d00
// 006522ce  8b4734               mov eax, dword ptr [edi + 0x34]
// 006522d1  8b4820               mov ecx, dword ptr [eax + 0x20]
// 006522d4  56                   push esi
// 006522d5  6a06                 push 6
// 006522d7  680a110000           push 0x110a
// 006522dc  51                   push ecx
// 006522dd  ffd3                 call ebx
// 006522df  8bf0                 mov esi, eax
// 006522e1  85f6                 test esi, esi
// 006522e3  75bb                 jne 0x6522a0
// 006522e5  e987000000           jmp 0x652371
// 006522ea  3bc5                 cmp eax, ebp
// 006522ec  742e                 je 0x65231c
// 006522ee  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 006522f1  6a02                 push 2
// 006522f3  56                   push esi
// 006522f4  e88d8a0e00           call 0x73ad86
// 006522f9  a802                 test al, 2
// 006522fb  750c                 jne 0x652309
// 006522fd  6a02                 push 2
// 006522ff  6a02                 push 2
// 00652301  56                   push esi
// 00652302  8bcf                 mov ecx, edi
// 00652304  e8f7f9ffff           call 0x651d00
// 00652309  8b4734               mov eax, dword ptr [edi + 0x34]
// 0065230c  8b5020               mov edx, dword ptr [eax + 0x20]
// 0065230f  56                   push esi
// 00652310  6a06                 push 6
// 00652312  680a110000           push 0x110a
// 00652317  52                   push edx
// 00652318  ffd3                 call ebx
// 0065231a  8bf0                 mov esi, eax
// 0065231c  85f6                 test esi, esi
// 0065231e  7451                 je 0x652371
// 00652320  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00652323  6a02                 push 2
// 00652325  56                   push esi
// 00652326  e85b8a0e00           call 0x73ad86
// 0065232b  a802                 test al, 2
// 0065232d  750c                 jne 0x65233b
// 0065232f  6a02                 push 2
// 00652331  6a02                 push 2
// 00652333  56                   push esi
// 00652334  8bcf                 mov ecx, edi
// 00652336  e8c5f9ffff           call 0x651d00
// 0065233b  3b742414             cmp esi, dword ptr [esp + 0x14]
// 0065233f  741d                 je 0x65235e
// 00652341  3bf5                 cmp esi, ebp
// 00652343  7419                 je 0x65235e
// 00652345  8b4734               mov eax, dword ptr [edi + 0x34]
// 00652348  8b4020               mov eax, dword ptr [eax + 0x20]
// 0065234b  56                   push esi
// 0065234c  6a06                 push 6
// 0065234e  680a110000           push 0x110a
// 00652353  50                   push eax
// 00652354  ffd3                 call ebx
// 00652356  8bf0                 mov esi, eax
// 00652358  85f6                 test esi, esi
// 0065235a  75c4                 jne 0x652320
// 0065235c  eb13                 jmp 0x652371
// 0065235e  8b4734               mov eax, dword ptr [edi + 0x34]
// 00652361  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00652364  56                   push esi
// 00652365  6a06                 push 6
// 00652367  680a110000           push 0x110a
// 0065236c  51                   push ecx
// 0065236d  ffd3                 call ebx
// 0065236f  8bf0                 mov esi, eax
// 00652371  5d                   pop ebp
// 00652372  837c241800           cmp dword ptr [esp + 0x18], 0
// 00652377  7439                 je 0x6523b2
// 00652379  85f6                 test esi, esi
// 0065237b  7435                 je 0x6523b2
// 0065237d  8d4900               lea ecx, [ecx]
// 00652380  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00652383  6a02                 push 2
// 00652385  56                   push esi
// 00652386  e8fb890e00           call 0x73ad86
// 0065238b  a802                 test al, 2
// 0065238d  740c                 je 0x65239b
// 0065238f  6a02                 push 2
// 00652391  6a00                 push 0
// 00652393  56                   push esi
// 00652394  8bcf                 mov ecx, edi
// 00652396  e865f9ffff           call 0x651d00
// 0065239b  8b4734               mov eax, dword ptr [edi + 0x34]
// 0065239e  8b5020               mov edx, dword ptr [eax + 0x20]
// 006523a1  56                   push esi
// 006523a2  6a06                 push 6
// 006523a4  680a110000           push 0x110a
// 006523a9  52                   push edx
// 006523aa  ffd3                 call ebx
// 006523ac  8bf0                 mov esi, eax
// 006523ae  85f6                 test esi, esi
// 006523b0  75ce                 jne 0x652380
// 006523b2  5f                   pop edi
// 006523b3  5e                   pop esi
// 006523b4  5b                   pop ebx
// 006523b5  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectItems@CXTPTreeBase@@QAEXPAU_TREEITEM@@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
