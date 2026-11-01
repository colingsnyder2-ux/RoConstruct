// from server: 100% by auto
// roc 2009-06 007576e0  unit: CRobloxTreeCtrl  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007576e0
//
// 007576e0  53                   push ebx
// 007576e1  8b1d90ee8900         mov ebx, dword ptr [0x89ee90]
// 007576e7  56                   push esi
// 007576e8  57                   push edi
// 007576e9  6a00                 push 0
// 007576eb  8bf9                 mov edi, ecx
// 007576ed  8b4734               mov eax, dword ptr [edi + 0x34]
// 007576f0  8b4020               mov eax, dword ptr [eax + 0x20]
// 007576f3  6a00                 push 0
// 007576f5  680a110000           push 0x110a
// 007576fa  50                   push eax
// 007576fb  ffd3                 call ebx
// 007576fd  8bf0                 mov esi, eax
// 007576ff  85f6                 test esi, esi
// 00757701  7428                 je 0x75772b
// 00757703  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00757706  6a02                 push 2
// 00757708  56                   push esi
// 00757709  e88c4a0f00           call 0x84c19a
// 0075770e  a802                 test al, 2
// 00757710  7517                 jne 0x757729
// 00757712  8b4734               mov eax, dword ptr [edi + 0x34]
// 00757715  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00757718  56                   push esi
// 00757719  6a06                 push 6
// 0075771b  680a110000           push 0x110a
// 00757720  51                   push ecx
// 00757721  ffd3                 call ebx
// 00757723  8bf0                 mov esi, eax
// 00757725  85f6                 test esi, esi
// 00757727  75da                 jne 0x757703
// 00757729  8bc6                 mov eax, esi
// 0075772b  5f                   pop edi
// 0075772c  5e                   pop esi
// 0075772d  5b                   pop ebx
// 0075772e  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetFirstSelectedItem@CXTPTreeBase@@QBEPAU_TREEITEM@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
