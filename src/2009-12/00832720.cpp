// from server: 100% by auto
// roc 2009-12 00832720  unit: CRobloxTreeCtrl  size: 328 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832720
//
// 00832720  53                   push ebx
// 00832721  8b1dc4cb9800         mov ebx, dword ptr [0x98cbc4]
// 00832727  56                   push esi
// 00832728  57                   push edi
// 00832729  6a00                 push 0
// 0083272b  8bf9                 mov edi, ecx
// 0083272d  8b4734               mov eax, dword ptr [edi + 0x34]
// 00832730  8b4020               mov eax, dword ptr [eax + 0x20]
// 00832733  6a00                 push 0
// 00832735  680a110000           push 0x110a
// 0083273a  50                   push eax
// 0083273b  ffd3                 call ebx
// 0083273d  8bf0                 mov esi, eax
// 0083273f  85f6                 test esi, esi
// 00832741  0f84db000000         je 0x832822
// 00832747  55                   push ebp
// 00832748  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0083274c  8d642400             lea esp, [esp]
// 00832750  8b442414             mov eax, dword ptr [esp + 0x14]
// 00832754  3bf0                 cmp esi, eax
// 00832756  7442                 je 0x83279a
// 00832758  3bf5                 cmp esi, ebp
// 0083275a  743e                 je 0x83279a
// 0083275c  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 00832761  741b                 je 0x83277e
// 00832763  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00832766  6a02                 push 2
// 00832768  56                   push esi
// 00832769  e8983f0f00           call 0x926706
// 0083276e  a802                 test al, 2
// 00832770  740c                 je 0x83277e
// 00832772  6a02                 push 2
// 00832774  6a00                 push 0
// 00832776  56                   push esi
// 00832777  8bcf                 mov ecx, edi
// 00832779  e8d2f9ffff           call 0x832150
// 0083277e  8b4734               mov eax, dword ptr [edi + 0x34]
// 00832781  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00832784  56                   push esi
// 00832785  6a06                 push 6
// 00832787  680a110000           push 0x110a
// 0083278c  51                   push ecx
// 0083278d  ffd3                 call ebx
// 0083278f  8bf0                 mov esi, eax
// 00832791  85f6                 test esi, esi
// 00832793  75bb                 jne 0x832750
// 00832795  e987000000           jmp 0x832821
// 0083279a  3bc5                 cmp eax, ebp
// 0083279c  742e                 je 0x8327cc
// 0083279e  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 008327a1  6a02                 push 2
// 008327a3  56                   push esi
// 008327a4  e85d3f0f00           call 0x926706
// 008327a9  a802                 test al, 2
// 008327ab  750c                 jne 0x8327b9
// 008327ad  6a02                 push 2
// 008327af  6a02                 push 2
// 008327b1  56                   push esi
// 008327b2  8bcf                 mov ecx, edi
// 008327b4  e897f9ffff           call 0x832150
// 008327b9  8b4734               mov eax, dword ptr [edi + 0x34]
// 008327bc  8b5020               mov edx, dword ptr [eax + 0x20]
// 008327bf  56                   push esi
// 008327c0  6a06                 push 6
// 008327c2  680a110000           push 0x110a
// 008327c7  52                   push edx
// 008327c8  ffd3                 call ebx
// 008327ca  8bf0                 mov esi, eax
// 008327cc  85f6                 test esi, esi
// 008327ce  7451                 je 0x832821
// 008327d0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 008327d3  6a02                 push 2
// 008327d5  56                   push esi
// 008327d6  e82b3f0f00           call 0x926706
// 008327db  a802                 test al, 2
// 008327dd  750c                 jne 0x8327eb
// 008327df  6a02                 push 2
// 008327e1  6a02                 push 2
// 008327e3  56                   push esi
// 008327e4  8bcf                 mov ecx, edi
// 008327e6  e865f9ffff           call 0x832150
// 008327eb  3b742414             cmp esi, dword ptr [esp + 0x14]
// 008327ef  741d                 je 0x83280e
// 008327f1  3bf5                 cmp esi, ebp
// 008327f3  7419                 je 0x83280e
// 008327f5  8b4734               mov eax, dword ptr [edi + 0x34]
// 008327f8  8b4020               mov eax, dword ptr [eax + 0x20]
// 008327fb  56                   push esi
// 008327fc  6a06                 push 6
// 008327fe  680a110000           push 0x110a
// 00832803  50                   push eax
// 00832804  ffd3                 call ebx
// 00832806  8bf0                 mov esi, eax
// 00832808  85f6                 test esi, esi
// 0083280a  75c4                 jne 0x8327d0
// 0083280c  eb13                 jmp 0x832821
// 0083280e  8b4734               mov eax, dword ptr [edi + 0x34]
// 00832811  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00832814  56                   push esi
// 00832815  6a06                 push 6
// 00832817  680a110000           push 0x110a
// 0083281c  51                   push ecx
// 0083281d  ffd3                 call ebx
// 0083281f  8bf0                 mov esi, eax
// 00832821  5d                   pop ebp
// 00832822  837c241800           cmp dword ptr [esp + 0x18], 0
// 00832827  7439                 je 0x832862
// 00832829  85f6                 test esi, esi
// 0083282b  7435                 je 0x832862
// 0083282d  8d4900               lea ecx, [ecx]
// 00832830  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00832833  6a02                 push 2
// 00832835  56                   push esi
// 00832836  e8cb3e0f00           call 0x926706
// 0083283b  a802                 test al, 2
// 0083283d  740c                 je 0x83284b
// 0083283f  6a02                 push 2
// 00832841  6a00                 push 0
// 00832843  56                   push esi
// 00832844  8bcf                 mov ecx, edi
// 00832846  e805f9ffff           call 0x832150
// 0083284b  8b4734               mov eax, dword ptr [edi + 0x34]
// 0083284e  8b5020               mov edx, dword ptr [eax + 0x20]
// 00832851  56                   push esi
// 00832852  6a06                 push 6
// 00832854  680a110000           push 0x110a
// 00832859  52                   push edx
// 0083285a  ffd3                 call ebx
// 0083285c  8bf0                 mov esi, eax
// 0083285e  85f6                 test esi, esi
// 00832860  75ce                 jne 0x832830
// 00832862  5f                   pop edi
// 00832863  5e                   pop esi
// 00832864  5b                   pop ebx
// 00832865  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectItems@CXTPTreeBase@@QAEXPAU_TREEITEM@@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
