// from server: 100% by auto
// roc 2009-06 00757790  unit: CRobloxTreeCtrl  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00757790
//
// 00757790  33c0                 xor eax, eax
// 00757792  39442404             cmp dword ptr [esp + 4], eax
// 00757796  53                   push ebx
// 00757797  0f95c0               setne al
// 0075779a  55                   push ebp
// 0075779b  56                   push esi
// 0075779c  8b742414             mov esi, dword ptr [esp + 0x14]
// 007577a0  57                   push edi
// 007577a1  8bf9                 mov edi, ecx
// 007577a3  8be8                 mov ebp, eax
// 007577a5  8bdd                 mov ebx, ebp
// 007577a7  f7db                 neg ebx
// 007577a9  1bdb                 sbb ebx, ebx
// 007577ab  83e302               and ebx, 2
// 007577ae  85f6                 test esi, esi
// 007577b0  751e                 jne 0x7577d0
// 007577b2  8b4734               mov eax, dword ptr [edi + 0x34]
// 007577b5  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007577b8  56                   push esi
// 007577b9  56                   push esi
// 007577ba  680a110000           push 0x110a
// 007577bf  51                   push ecx
// 007577c0  ff1590ee8900         call dword ptr [0x89ee90]
// 007577c6  8bf0                 mov esi, eax
// 007577c8  85f6                 test esi, esi
// 007577ca  743e                 je 0x75780a
// 007577cc  8d642400             lea esp, [esp]
// 007577d0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007577d3  6a02                 push 2
// 007577d5  56                   push esi
// 007577d6  e8bf490f00           call 0x84c19a
// 007577db  d1e8                 shr eax, 1
// 007577dd  83e001               and eax, 1
// 007577e0  3bc5                 cmp eax, ebp
// 007577e2  740b                 je 0x7577ef
// 007577e4  6a02                 push 2
// 007577e6  53                   push ebx
// 007577e7  56                   push esi
// 007577e8  8bcf                 mov ecx, edi
// 007577ea  e8e1faffff           call 0x7572d0
// 007577ef  8b4734               mov eax, dword ptr [edi + 0x34]
// 007577f2  8b5020               mov edx, dword ptr [eax + 0x20]
// 007577f5  56                   push esi
// 007577f6  6a06                 push 6
// 007577f8  680a110000           push 0x110a
// 007577fd  52                   push edx
// 007577fe  ff1590ee8900         call dword ptr [0x89ee90]
// 00757804  8bf0                 mov esi, eax
// 00757806  85f6                 test esi, esi
// 00757808  75c6                 jne 0x7577d0
// 0075780a  5f                   pop edi
// 0075780b  5e                   pop esi
// 0075780c  5d                   pop ebp
// 0075780d  5b                   pop ebx
// 0075780e  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectAll@CXTPTreeBase@@QAEXHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
