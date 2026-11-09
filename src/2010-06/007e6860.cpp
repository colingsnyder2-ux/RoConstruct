// from server: 100% by auto
// roc 2010-06 007e6860  unit: CRobloxTreeCtrl  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e6860
//
// 007e6860  53                   push ebx
// 007e6861  33c0                 xor eax, eax
// 007e6863  39442408             cmp dword ptr [esp + 8], eax
// 007e6867  55                   push ebp
// 007e6868  0f95c0               setne al
// 007e686b  56                   push esi
// 007e686c  57                   push edi
// 007e686d  6a00                 push 0
// 007e686f  8bf9                 mov edi, ecx
// 007e6871  6a00                 push 0
// 007e6873  680a110000           push 0x110a
// 007e6878  8be8                 mov ebp, eax
// 007e687a  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e687d  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007e6880  8bdd                 mov ebx, ebp
// 007e6882  f7db                 neg ebx
// 007e6884  1bdb                 sbb ebx, ebx
// 007e6886  51                   push ecx
// 007e6887  83e302               and ebx, 2
// 007e688a  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e6890  8bf0                 mov esi, eax
// 007e6892  85f6                 test esi, esi
// 007e6894  7440                 je 0x7e68d6
// 007e6896  3b742418             cmp esi, dword ptr [esp + 0x18]
// 007e689a  741f                 je 0x7e68bb
// 007e689c  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e689f  6a02                 push 2
// 007e68a1  56                   push esi
// 007e68a2  e89b671900           call 0x97d042
// 007e68a7  d1e8                 shr eax, 1
// 007e68a9  83e001               and eax, 1
// 007e68ac  3bc5                 cmp eax, ebp
// 007e68ae  740b                 je 0x7e68bb
// 007e68b0  6a02                 push 2
// 007e68b2  53                   push ebx
// 007e68b3  56                   push esi
// 007e68b4  8bcf                 mov ecx, edi
// 007e68b6  e855faffff           call 0x7e6310
// 007e68bb  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e68be  8b5020               mov edx, dword ptr [eax + 0x20]
// 007e68c1  56                   push esi
// 007e68c2  6a06                 push 6
// 007e68c4  680a110000           push 0x110a
// 007e68c9  52                   push edx
// 007e68ca  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e68d0  8bf0                 mov esi, eax
// 007e68d2  85f6                 test esi, esi
// 007e68d4  75c0                 jne 0x7e6896
// 007e68d6  5f                   pop edi
// 007e68d7  5e                   pop esi
// 007e68d8  5d                   pop ebp
// 007e68d9  5b                   pop ebx
// 007e68da  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?SelectAllIgnore@CXTTreeBase@@MAEXHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
