// from server: 100% by auto
// roc 2009-12 00832610  unit: CRobloxTreeCtrl  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832610
//
// 00832610  33c0                 xor eax, eax
// 00832612  39442404             cmp dword ptr [esp + 4], eax
// 00832616  53                   push ebx
// 00832617  0f95c0               setne al
// 0083261a  55                   push ebp
// 0083261b  56                   push esi
// 0083261c  8b742414             mov esi, dword ptr [esp + 0x14]
// 00832620  57                   push edi
// 00832621  8bf9                 mov edi, ecx
// 00832623  8be8                 mov ebp, eax
// 00832625  8bdd                 mov ebx, ebp
// 00832627  f7db                 neg ebx
// 00832629  1bdb                 sbb ebx, ebx
// 0083262b  83e302               and ebx, 2
// 0083262e  85f6                 test esi, esi
// 00832630  751e                 jne 0x832650
// 00832632  8b4734               mov eax, dword ptr [edi + 0x34]
// 00832635  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00832638  56                   push esi
// 00832639  56                   push esi
// 0083263a  680a110000           push 0x110a
// 0083263f  51                   push ecx
// 00832640  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00832646  8bf0                 mov esi, eax
// 00832648  85f6                 test esi, esi
// 0083264a  743e                 je 0x83268a
// 0083264c  8d642400             lea esp, [esp]
// 00832650  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00832653  6a02                 push 2
// 00832655  56                   push esi
// 00832656  e8ab400f00           call 0x926706
// 0083265b  d1e8                 shr eax, 1
// 0083265d  83e001               and eax, 1
// 00832660  3bc5                 cmp eax, ebp
// 00832662  740b                 je 0x83266f
// 00832664  6a02                 push 2
// 00832666  53                   push ebx
// 00832667  56                   push esi
// 00832668  8bcf                 mov ecx, edi
// 0083266a  e8e1faffff           call 0x832150
// 0083266f  8b4734               mov eax, dword ptr [edi + 0x34]
// 00832672  8b5020               mov edx, dword ptr [eax + 0x20]
// 00832675  56                   push esi
// 00832676  6a06                 push 6
// 00832678  680a110000           push 0x110a
// 0083267d  52                   push edx
// 0083267e  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00832684  8bf0                 mov esi, eax
// 00832686  85f6                 test esi, esi
// 00832688  75c6                 jne 0x832650
// 0083268a  5f                   pop edi
// 0083268b  5e                   pop esi
// 0083268c  5d                   pop ebp
// 0083268d  5b                   pop ebx
// 0083268e  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectAll@CXTPTreeBase@@QAEXHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
