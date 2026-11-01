// from server: 100% by auto
// roc 2009-12 008326a0  unit: CRobloxTreeCtrl  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008326a0
//
// 008326a0  53                   push ebx
// 008326a1  33c0                 xor eax, eax
// 008326a3  39442408             cmp dword ptr [esp + 8], eax
// 008326a7  55                   push ebp
// 008326a8  0f95c0               setne al
// 008326ab  56                   push esi
// 008326ac  57                   push edi
// 008326ad  6a00                 push 0
// 008326af  8bf9                 mov edi, ecx
// 008326b1  6a00                 push 0
// 008326b3  680a110000           push 0x110a
// 008326b8  8be8                 mov ebp, eax
// 008326ba  8b4734               mov eax, dword ptr [edi + 0x34]
// 008326bd  8b4820               mov ecx, dword ptr [eax + 0x20]
// 008326c0  8bdd                 mov ebx, ebp
// 008326c2  f7db                 neg ebx
// 008326c4  1bdb                 sbb ebx, ebx
// 008326c6  51                   push ecx
// 008326c7  83e302               and ebx, 2
// 008326ca  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008326d0  8bf0                 mov esi, eax
// 008326d2  85f6                 test esi, esi
// 008326d4  7440                 je 0x832716
// 008326d6  3b742418             cmp esi, dword ptr [esp + 0x18]
// 008326da  741f                 je 0x8326fb
// 008326dc  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 008326df  6a02                 push 2
// 008326e1  56                   push esi
// 008326e2  e81f400f00           call 0x926706
// 008326e7  d1e8                 shr eax, 1
// 008326e9  83e001               and eax, 1
// 008326ec  3bc5                 cmp eax, ebp
// 008326ee  740b                 je 0x8326fb
// 008326f0  6a02                 push 2
// 008326f2  53                   push ebx
// 008326f3  56                   push esi
// 008326f4  8bcf                 mov ecx, edi
// 008326f6  e855faffff           call 0x832150
// 008326fb  8b4734               mov eax, dword ptr [edi + 0x34]
// 008326fe  8b5020               mov edx, dword ptr [eax + 0x20]
// 00832701  56                   push esi
// 00832702  6a06                 push 6
// 00832704  680a110000           push 0x110a
// 00832709  52                   push edx
// 0083270a  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00832710  8bf0                 mov esi, eax
// 00832712  85f6                 test esi, esi
// 00832714  75c0                 jne 0x8326d6
// 00832716  5f                   pop edi
// 00832717  5e                   pop esi
// 00832718  5d                   pop ebp
// 00832719  5b                   pop ebx
// 0083271a  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectAllIgnore@CXTPTreeBase@@MAEXHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
