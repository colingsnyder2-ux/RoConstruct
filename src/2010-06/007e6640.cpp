// from server: 100% by auto
// roc 2010-06 007e6640  unit: CRobloxTreeCtrl  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e6640
//
// 007e6640  53                   push ebx
// 007e6641  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007e6645  55                   push ebp
// 007e6646  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007e664a  56                   push esi
// 007e664b  57                   push edi
// 007e664c  8bc3                 mov eax, ebx
// 007e664e  83e0fe               and eax, 0xfffffffe
// 007e6651  8bf1                 mov esi, ecx
// 007e6653  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e6656  50                   push eax
// 007e6657  55                   push ebp
// 007e6658  e8e5691900           call 0x97d042
// 007e665d  8bf8                 mov edi, eax
// 007e665f  f6c301               test bl, 1
// 007e6662  741f                 je 0x7e6683
// 007e6664  8b7634               mov esi, dword ptr [esi + 0x34]
// 007e6667  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007e666a  6a00                 push 0
// 007e666c  6a09                 push 9
// 007e666e  680a110000           push 0x110a
// 007e6673  51                   push ecx
// 007e6674  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e667a  3bc5                 cmp eax, ebp
// 007e667c  7503                 jne 0x7e6681
// 007e667e  83cf01               or edi, 1
// 007e6681  8bc7                 mov eax, edi
// 007e6683  5f                   pop edi
// 007e6684  5e                   pop esi
// 007e6685  5d                   pop ebp
// 007e6686  5b                   pop ebx
// 007e6687  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetItemState@CXTTreeBase@@QBEIPAU_TREEITEM@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
