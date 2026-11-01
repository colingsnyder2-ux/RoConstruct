// from server: 100% by auto
// roc 2009-12 00832560  unit: CRobloxTreeCtrl  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832560
//
// 00832560  53                   push ebx
// 00832561  8b1dc4cb9800         mov ebx, dword ptr [0x98cbc4]
// 00832567  56                   push esi
// 00832568  57                   push edi
// 00832569  6a00                 push 0
// 0083256b  8bf9                 mov edi, ecx
// 0083256d  8b4734               mov eax, dword ptr [edi + 0x34]
// 00832570  8b4020               mov eax, dword ptr [eax + 0x20]
// 00832573  6a00                 push 0
// 00832575  680a110000           push 0x110a
// 0083257a  50                   push eax
// 0083257b  ffd3                 call ebx
// 0083257d  8bf0                 mov esi, eax
// 0083257f  85f6                 test esi, esi
// 00832581  7428                 je 0x8325ab
// 00832583  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00832586  6a02                 push 2
// 00832588  56                   push esi
// 00832589  e878410f00           call 0x926706
// 0083258e  a802                 test al, 2
// 00832590  7517                 jne 0x8325a9
// 00832592  8b4734               mov eax, dword ptr [edi + 0x34]
// 00832595  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00832598  56                   push esi
// 00832599  6a06                 push 6
// 0083259b  680a110000           push 0x110a
// 008325a0  51                   push ecx
// 008325a1  ffd3                 call ebx
// 008325a3  8bf0                 mov esi, eax
// 008325a5  85f6                 test esi, esi
// 008325a7  75da                 jne 0x832583
// 008325a9  8bc6                 mov eax, esi
// 008325ab  5f                   pop edi
// 008325ac  5e                   pop esi
// 008325ad  5b                   pop ebx
// 008325ae  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetFirstSelectedItem@CXTPTreeBase@@QBEPAU_TREEITEM@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
