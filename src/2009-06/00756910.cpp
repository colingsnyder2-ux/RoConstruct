// from server: 100% by auto
// roc 2009-06 00756910  unit: CXTTreeBase  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756910
//
// 00756910  56                   push esi
// 00756911  57                   push edi
// 00756912  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00756916  817f08f7fdffff       cmp dword ptr [edi + 8], 0xfffffdf7
// 0075691d  8bf1                 mov esi, ecx
// 0075691f  752d                 jne 0x75694e
// 00756921  8b4634               mov eax, dword ptr [esi + 0x34]
// 00756924  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00756927  6a00                 push 0
// 00756929  6a00                 push 0
// 0075692b  6819110000           push 0x1119
// 00756930  51                   push ecx
// 00756931  ff1590ee8900         call dword ptr [0x89ee90]
// 00756937  85c0                 test eax, eax
// 00756939  7413                 je 0x75694e
// 0075693b  6a13                 push 0x13
// 0075693d  6a00                 push 0
// 0075693f  6a00                 push 0
// 00756941  6a00                 push 0
// 00756943  6a00                 push 0
// 00756945  6a00                 push 0
// 00756947  50                   push eax
// 00756948  ff15f4ec8900         call dword ptr [0x89ecf4]
// 0075694e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00756952  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00756956  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00756959  52                   push edx
// 0075695a  57                   push edi
// 0075695b  50                   push eax
// 0075695c  e83322fcff           call 0x718b94
// 00756961  5f                   pop edi
// 00756962  5e                   pop esi
// 00756963  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnNotify@CXTPTreeBase@@MAEHIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
