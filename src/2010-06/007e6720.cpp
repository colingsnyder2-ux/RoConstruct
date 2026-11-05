// from server: 100% by auto
// roc 2010-06 007e6720  unit: CRobloxTreeCtrl  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e6720
//
// 007e6720  53                   push ebx
// 007e6721  8b1d54ba9e00         mov ebx, dword ptr [0x9eba54]
// 007e6727  56                   push esi
// 007e6728  57                   push edi
// 007e6729  6a00                 push 0
// 007e672b  8bf9                 mov edi, ecx
// 007e672d  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e6730  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e6733  6a00                 push 0
// 007e6735  680a110000           push 0x110a
// 007e673a  50                   push eax
// 007e673b  ffd3                 call ebx
// 007e673d  8bf0                 mov esi, eax
// 007e673f  85f6                 test esi, esi
// 007e6741  7428                 je 0x7e676b
// 007e6743  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e6746  6a02                 push 2
// 007e6748  56                   push esi
// 007e6749  e8f4681900           call 0x97d042
// 007e674e  a802                 test al, 2
// 007e6750  7517                 jne 0x7e6769
// 007e6752  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e6755  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007e6758  56                   push esi
// 007e6759  6a06                 push 6
// 007e675b  680a110000           push 0x110a
// 007e6760  51                   push ecx
// 007e6761  ffd3                 call ebx
// 007e6763  8bf0                 mov esi, eax
// 007e6765  85f6                 test esi, esi
// 007e6767  75da                 jne 0x7e6743
// 007e6769  8bc6                 mov eax, esi
// 007e676b  5f                   pop edi
// 007e676c  5e                   pop esi
// 007e676d  5b                   pop ebx
// 007e676e  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetFirstSelectedItem@CXTTreeBase@@QBEPAU_TREEITEM@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
