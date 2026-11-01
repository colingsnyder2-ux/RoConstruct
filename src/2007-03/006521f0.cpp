// from server: 100% by auto
// roc 2007-03 006521f0  unit: seg_00650000  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006521f0
//
// 006521f0  53                   push ebx
// 006521f1  33c0                 xor eax, eax
// 006521f3  39442408             cmp dword ptr [esp + 8], eax
// 006521f7  55                   push ebp
// 006521f8  0f95c0               setne al
// 006521fb  56                   push esi
// 006521fc  57                   push edi
// 006521fd  6a00                 push 0
// 006521ff  8bf9                 mov edi, ecx
// 00652201  6a00                 push 0
// 00652203  680a110000           push 0x110a
// 00652208  8be8                 mov ebp, eax
// 0065220a  8b4734               mov eax, dword ptr [edi + 0x34]
// 0065220d  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00652210  8bdd                 mov ebx, ebp
// 00652212  f7db                 neg ebx
// 00652214  1bdb                 sbb ebx, ebx
// 00652216  51                   push ecx
// 00652217  83e302               and ebx, 2
// 0065221a  ff1550ee7700         call dword ptr [0x77ee50]
// 00652220  8bf0                 mov esi, eax
// 00652222  85f6                 test esi, esi
// 00652224  7440                 je 0x652266
// 00652226  3b742418             cmp esi, dword ptr [esp + 0x18]
// 0065222a  741f                 je 0x65224b
// 0065222c  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 0065222f  6a02                 push 2
// 00652231  56                   push esi
// 00652232  e84f8b0e00           call 0x73ad86
// 00652237  d1e8                 shr eax, 1
// 00652239  83e001               and eax, 1
// 0065223c  3bc5                 cmp eax, ebp
// 0065223e  740b                 je 0x65224b
// 00652240  6a02                 push 2
// 00652242  53                   push ebx
// 00652243  56                   push esi
// 00652244  8bcf                 mov ecx, edi
// 00652246  e8b5faffff           call 0x651d00
// 0065224b  8b4734               mov eax, dword ptr [edi + 0x34]
// 0065224e  8b5020               mov edx, dword ptr [eax + 0x20]
// 00652251  56                   push esi
// 00652252  6a06                 push 6
// 00652254  680a110000           push 0x110a
// 00652259  52                   push edx
// 0065225a  ff1550ee7700         call dword ptr [0x77ee50]
// 00652260  8bf0                 mov esi, eax
// 00652262  85f6                 test esi, esi
// 00652264  75c0                 jne 0x652226
// 00652266  5f                   pop edi
// 00652267  5e                   pop esi
// 00652268  5d                   pop ebp
// 00652269  5b                   pop ebx
// 0065226a  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectAllIgnore@CXTPTreeBase@@MAEXHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
