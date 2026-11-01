// from server: 100% by auto
// roc 2009-06 00757820  unit: CRobloxTreeCtrl  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00757820
//
// 00757820  53                   push ebx
// 00757821  33c0                 xor eax, eax
// 00757823  39442408             cmp dword ptr [esp + 8], eax
// 00757827  55                   push ebp
// 00757828  0f95c0               setne al
// 0075782b  56                   push esi
// 0075782c  57                   push edi
// 0075782d  6a00                 push 0
// 0075782f  8bf9                 mov edi, ecx
// 00757831  6a00                 push 0
// 00757833  680a110000           push 0x110a
// 00757838  8be8                 mov ebp, eax
// 0075783a  8b4734               mov eax, dword ptr [edi + 0x34]
// 0075783d  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00757840  8bdd                 mov ebx, ebp
// 00757842  f7db                 neg ebx
// 00757844  1bdb                 sbb ebx, ebx
// 00757846  51                   push ecx
// 00757847  83e302               and ebx, 2
// 0075784a  ff1590ee8900         call dword ptr [0x89ee90]
// 00757850  8bf0                 mov esi, eax
// 00757852  85f6                 test esi, esi
// 00757854  7440                 je 0x757896
// 00757856  3b742418             cmp esi, dword ptr [esp + 0x18]
// 0075785a  741f                 je 0x75787b
// 0075785c  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 0075785f  6a02                 push 2
// 00757861  56                   push esi
// 00757862  e833490f00           call 0x84c19a
// 00757867  d1e8                 shr eax, 1
// 00757869  83e001               and eax, 1
// 0075786c  3bc5                 cmp eax, ebp
// 0075786e  740b                 je 0x75787b
// 00757870  6a02                 push 2
// 00757872  53                   push ebx
// 00757873  56                   push esi
// 00757874  8bcf                 mov ecx, edi
// 00757876  e855faffff           call 0x7572d0
// 0075787b  8b4734               mov eax, dword ptr [edi + 0x34]
// 0075787e  8b5020               mov edx, dword ptr [eax + 0x20]
// 00757881  56                   push esi
// 00757882  6a06                 push 6
// 00757884  680a110000           push 0x110a
// 00757889  52                   push edx
// 0075788a  ff1590ee8900         call dword ptr [0x89ee90]
// 00757890  8bf0                 mov esi, eax
// 00757892  85f6                 test esi, esi
// 00757894  75c0                 jne 0x757856
// 00757896  5f                   pop edi
// 00757897  5e                   pop esi
// 00757898  5d                   pop ebp
// 00757899  5b                   pop ebx
// 0075789a  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectAllIgnore@CXTPTreeBase@@MAEXHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
