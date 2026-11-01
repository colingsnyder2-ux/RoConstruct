// from server: 100% by auto
// roc 2009-12 00832480  unit: CRobloxTreeCtrl  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832480
//
// 00832480  53                   push ebx
// 00832481  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00832485  55                   push ebp
// 00832486  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0083248a  56                   push esi
// 0083248b  57                   push edi
// 0083248c  8bc3                 mov eax, ebx
// 0083248e  83e0fe               and eax, 0xfffffffe
// 00832491  8bf1                 mov esi, ecx
// 00832493  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00832496  50                   push eax
// 00832497  55                   push ebp
// 00832498  e869420f00           call 0x926706
// 0083249d  8bf8                 mov edi, eax
// 0083249f  f6c301               test bl, 1
// 008324a2  741f                 je 0x8324c3
// 008324a4  8b7634               mov esi, dword ptr [esi + 0x34]
// 008324a7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008324aa  6a00                 push 0
// 008324ac  6a09                 push 9
// 008324ae  680a110000           push 0x110a
// 008324b3  51                   push ecx
// 008324b4  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008324ba  3bc5                 cmp eax, ebp
// 008324bc  7503                 jne 0x8324c1
// 008324be  83cf01               or edi, 1
// 008324c1  8bc7                 mov eax, edi
// 008324c3  5f                   pop edi
// 008324c4  5e                   pop esi
// 008324c5  5d                   pop ebp
// 008324c6  5b                   pop ebx
// 008324c7  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetItemState@CXTPTreeBase@@QBEIPAU_TREEITEM@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
