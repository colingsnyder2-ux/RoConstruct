// from server: 100% by auto
// roc 2009-06 007578a0  unit: CRobloxTreeCtrl  size: 328 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007578a0
//
// 007578a0  53                   push ebx
// 007578a1  8b1d90ee8900         mov ebx, dword ptr [0x89ee90]
// 007578a7  56                   push esi
// 007578a8  57                   push edi
// 007578a9  6a00                 push 0
// 007578ab  8bf9                 mov edi, ecx
// 007578ad  8b4734               mov eax, dword ptr [edi + 0x34]
// 007578b0  8b4020               mov eax, dword ptr [eax + 0x20]
// 007578b3  6a00                 push 0
// 007578b5  680a110000           push 0x110a
// 007578ba  50                   push eax
// 007578bb  ffd3                 call ebx
// 007578bd  8bf0                 mov esi, eax
// 007578bf  85f6                 test esi, esi
// 007578c1  0f84db000000         je 0x7579a2
// 007578c7  55                   push ebp
// 007578c8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007578cc  8d642400             lea esp, [esp]
// 007578d0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007578d4  3bf0                 cmp esi, eax
// 007578d6  7442                 je 0x75791a
// 007578d8  3bf5                 cmp esi, ebp
// 007578da  743e                 je 0x75791a
// 007578dc  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 007578e1  741b                 je 0x7578fe
// 007578e3  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007578e6  6a02                 push 2
// 007578e8  56                   push esi
// 007578e9  e8ac480f00           call 0x84c19a
// 007578ee  a802                 test al, 2
// 007578f0  740c                 je 0x7578fe
// 007578f2  6a02                 push 2
// 007578f4  6a00                 push 0
// 007578f6  56                   push esi
// 007578f7  8bcf                 mov ecx, edi
// 007578f9  e8d2f9ffff           call 0x7572d0
// 007578fe  8b4734               mov eax, dword ptr [edi + 0x34]
// 00757901  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00757904  56                   push esi
// 00757905  6a06                 push 6
// 00757907  680a110000           push 0x110a
// 0075790c  51                   push ecx
// 0075790d  ffd3                 call ebx
// 0075790f  8bf0                 mov esi, eax
// 00757911  85f6                 test esi, esi
// 00757913  75bb                 jne 0x7578d0
// 00757915  e987000000           jmp 0x7579a1
// 0075791a  3bc5                 cmp eax, ebp
// 0075791c  742e                 je 0x75794c
// 0075791e  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00757921  6a02                 push 2
// 00757923  56                   push esi
// 00757924  e871480f00           call 0x84c19a
// 00757929  a802                 test al, 2
// 0075792b  750c                 jne 0x757939
// 0075792d  6a02                 push 2
// 0075792f  6a02                 push 2
// 00757931  56                   push esi
// 00757932  8bcf                 mov ecx, edi
// 00757934  e897f9ffff           call 0x7572d0
// 00757939  8b4734               mov eax, dword ptr [edi + 0x34]
// 0075793c  8b5020               mov edx, dword ptr [eax + 0x20]
// 0075793f  56                   push esi
// 00757940  6a06                 push 6
// 00757942  680a110000           push 0x110a
// 00757947  52                   push edx
// 00757948  ffd3                 call ebx
// 0075794a  8bf0                 mov esi, eax
// 0075794c  85f6                 test esi, esi
// 0075794e  7451                 je 0x7579a1
// 00757950  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00757953  6a02                 push 2
// 00757955  56                   push esi
// 00757956  e83f480f00           call 0x84c19a
// 0075795b  a802                 test al, 2
// 0075795d  750c                 jne 0x75796b
// 0075795f  6a02                 push 2
// 00757961  6a02                 push 2
// 00757963  56                   push esi
// 00757964  8bcf                 mov ecx, edi
// 00757966  e865f9ffff           call 0x7572d0
// 0075796b  3b742414             cmp esi, dword ptr [esp + 0x14]
// 0075796f  741d                 je 0x75798e
// 00757971  3bf5                 cmp esi, ebp
// 00757973  7419                 je 0x75798e
// 00757975  8b4734               mov eax, dword ptr [edi + 0x34]
// 00757978  8b4020               mov eax, dword ptr [eax + 0x20]
// 0075797b  56                   push esi
// 0075797c  6a06                 push 6
// 0075797e  680a110000           push 0x110a
// 00757983  50                   push eax
// 00757984  ffd3                 call ebx
// 00757986  8bf0                 mov esi, eax
// 00757988  85f6                 test esi, esi
// 0075798a  75c4                 jne 0x757950
// 0075798c  eb13                 jmp 0x7579a1
// 0075798e  8b4734               mov eax, dword ptr [edi + 0x34]
// 00757991  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00757994  56                   push esi
// 00757995  6a06                 push 6
// 00757997  680a110000           push 0x110a
// 0075799c  51                   push ecx
// 0075799d  ffd3                 call ebx
// 0075799f  8bf0                 mov esi, eax
// 007579a1  5d                   pop ebp
// 007579a2  837c241800           cmp dword ptr [esp + 0x18], 0
// 007579a7  7439                 je 0x7579e2
// 007579a9  85f6                 test esi, esi
// 007579ab  7435                 je 0x7579e2
// 007579ad  8d4900               lea ecx, [ecx]
// 007579b0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007579b3  6a02                 push 2
// 007579b5  56                   push esi
// 007579b6  e8df470f00           call 0x84c19a
// 007579bb  a802                 test al, 2
// 007579bd  740c                 je 0x7579cb
// 007579bf  6a02                 push 2
// 007579c1  6a00                 push 0
// 007579c3  56                   push esi
// 007579c4  8bcf                 mov ecx, edi
// 007579c6  e805f9ffff           call 0x7572d0
// 007579cb  8b4734               mov eax, dword ptr [edi + 0x34]
// 007579ce  8b5020               mov edx, dword ptr [eax + 0x20]
// 007579d1  56                   push esi
// 007579d2  6a06                 push 6
// 007579d4  680a110000           push 0x110a
// 007579d9  52                   push edx
// 007579da  ffd3                 call ebx
// 007579dc  8bf0                 mov esi, eax
// 007579de  85f6                 test esi, esi
// 007579e0  75ce                 jne 0x7579b0
// 007579e2  5f                   pop edi
// 007579e3  5e                   pop esi
// 007579e4  5b                   pop ebx
// 007579e5  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectItems@CXTPTreeBase@@QAEXPAU_TREEITEM@@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
