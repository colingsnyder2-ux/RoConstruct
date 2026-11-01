// from server: 100% by auto
// roc 2007-03 00652100  unit: seg_00650000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652100
//
// 00652100  53                   push ebx
// 00652101  8b1d50ee7700         mov ebx, dword ptr [0x77ee50]
// 00652107  56                   push esi
// 00652108  57                   push edi
// 00652109  8bf9                 mov edi, ecx
// 0065210b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065210f  8b4734               mov eax, dword ptr [edi + 0x34]
// 00652112  8b5020               mov edx, dword ptr [eax + 0x20]
// 00652115  51                   push ecx
// 00652116  6a06                 push 6
// 00652118  680a110000           push 0x110a
// 0065211d  52                   push edx
// 0065211e  ffd3                 call ebx
// 00652120  8bf0                 mov esi, eax
// 00652122  85f6                 test esi, esi
// 00652124  7428                 je 0x65214e
// 00652126  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00652129  6a02                 push 2
// 0065212b  56                   push esi
// 0065212c  e8558c0e00           call 0x73ad86
// 00652131  a802                 test al, 2
// 00652133  7517                 jne 0x65214c
// 00652135  8b4734               mov eax, dword ptr [edi + 0x34]
// 00652138  8b4020               mov eax, dword ptr [eax + 0x20]
// 0065213b  56                   push esi
// 0065213c  6a06                 push 6
// 0065213e  680a110000           push 0x110a
// 00652143  50                   push eax
// 00652144  ffd3                 call ebx
// 00652146  8bf0                 mov esi, eax
// 00652148  85f6                 test esi, esi
// 0065214a  75da                 jne 0x652126
// 0065214c  8bc6                 mov eax, esi
// 0065214e  5f                   pop edi
// 0065214f  5e                   pop esi
// 00652150  5b                   pop ebx
// 00652151  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetNextSelectedItem@CXTPTreeBase@@QBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
