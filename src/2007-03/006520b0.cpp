// from server: 100% by auto
// roc 2007-03 006520b0  unit: seg_00650000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006520b0
//
// 006520b0  53                   push ebx
// 006520b1  8b1d50ee7700         mov ebx, dword ptr [0x77ee50]
// 006520b7  56                   push esi
// 006520b8  57                   push edi
// 006520b9  6a00                 push 0
// 006520bb  8bf9                 mov edi, ecx
// 006520bd  8b4734               mov eax, dword ptr [edi + 0x34]
// 006520c0  8b4020               mov eax, dword ptr [eax + 0x20]
// 006520c3  6a00                 push 0
// 006520c5  680a110000           push 0x110a
// 006520ca  50                   push eax
// 006520cb  ffd3                 call ebx
// 006520cd  8bf0                 mov esi, eax
// 006520cf  85f6                 test esi, esi
// 006520d1  7428                 je 0x6520fb
// 006520d3  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 006520d6  6a02                 push 2
// 006520d8  56                   push esi
// 006520d9  e8a88c0e00           call 0x73ad86
// 006520de  a802                 test al, 2
// 006520e0  7517                 jne 0x6520f9
// 006520e2  8b4734               mov eax, dword ptr [edi + 0x34]
// 006520e5  8b4820               mov ecx, dword ptr [eax + 0x20]
// 006520e8  56                   push esi
// 006520e9  6a06                 push 6
// 006520eb  680a110000           push 0x110a
// 006520f0  51                   push ecx
// 006520f1  ffd3                 call ebx
// 006520f3  8bf0                 mov esi, eax
// 006520f5  85f6                 test esi, esi
// 006520f7  75da                 jne 0x6520d3
// 006520f9  8bc6                 mov eax, esi
// 006520fb  5f                   pop edi
// 006520fc  5e                   pop esi
// 006520fd  5b                   pop ebx
// 006520fe  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetFirstSelectedItem@CXTPTreeBase@@QBEPAU_TREEITEM@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
