// from server: 100% by auto
// roc 2009-06 00757730  unit: CRobloxTreeCtrl  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00757730
//
// 00757730  53                   push ebx
// 00757731  8b1d90ee8900         mov ebx, dword ptr [0x89ee90]
// 00757737  56                   push esi
// 00757738  57                   push edi
// 00757739  8bf9                 mov edi, ecx
// 0075773b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0075773f  8b4734               mov eax, dword ptr [edi + 0x34]
// 00757742  8b5020               mov edx, dword ptr [eax + 0x20]
// 00757745  51                   push ecx
// 00757746  6a06                 push 6
// 00757748  680a110000           push 0x110a
// 0075774d  52                   push edx
// 0075774e  ffd3                 call ebx
// 00757750  8bf0                 mov esi, eax
// 00757752  85f6                 test esi, esi
// 00757754  7428                 je 0x75777e
// 00757756  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00757759  6a02                 push 2
// 0075775b  56                   push esi
// 0075775c  e8394a0f00           call 0x84c19a
// 00757761  a802                 test al, 2
// 00757763  7517                 jne 0x75777c
// 00757765  8b4734               mov eax, dword ptr [edi + 0x34]
// 00757768  8b4020               mov eax, dword ptr [eax + 0x20]
// 0075776b  56                   push esi
// 0075776c  6a06                 push 6
// 0075776e  680a110000           push 0x110a
// 00757773  50                   push eax
// 00757774  ffd3                 call ebx
// 00757776  8bf0                 mov esi, eax
// 00757778  85f6                 test esi, esi
// 0075777a  75da                 jne 0x757756
// 0075777c  8bc6                 mov eax, esi
// 0075777e  5f                   pop edi
// 0075777f  5e                   pop esi
// 00757780  5b                   pop ebx
// 00757781  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetNextSelectedItem@CXTPTreeBase@@QBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
