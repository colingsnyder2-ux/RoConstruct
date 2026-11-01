// from server: 100% by auto
// roc 2009-06 00757600  unit: CRobloxTreeCtrl  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00757600
//
// 00757600  53                   push ebx
// 00757601  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00757605  55                   push ebp
// 00757606  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0075760a  56                   push esi
// 0075760b  57                   push edi
// 0075760c  8bc3                 mov eax, ebx
// 0075760e  83e0fe               and eax, 0xfffffffe
// 00757611  8bf1                 mov esi, ecx
// 00757613  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00757616  50                   push eax
// 00757617  55                   push ebp
// 00757618  e87d4b0f00           call 0x84c19a
// 0075761d  8bf8                 mov edi, eax
// 0075761f  f6c301               test bl, 1
// 00757622  741f                 je 0x757643
// 00757624  8b7634               mov esi, dword ptr [esi + 0x34]
// 00757627  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0075762a  6a00                 push 0
// 0075762c  6a09                 push 9
// 0075762e  680a110000           push 0x110a
// 00757633  51                   push ecx
// 00757634  ff1590ee8900         call dword ptr [0x89ee90]
// 0075763a  3bc5                 cmp eax, ebp
// 0075763c  7503                 jne 0x757641
// 0075763e  83cf01               or edi, 1
// 00757641  8bc7                 mov eax, edi
// 00757643  5f                   pop edi
// 00757644  5e                   pop esi
// 00757645  5d                   pop ebp
// 00757646  5b                   pop ebx
// 00757647  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetItemState@CXTPTreeBase@@QBEIPAU_TREEITEM@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
