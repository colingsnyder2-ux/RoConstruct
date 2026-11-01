// from server: 100% by auto
// roc 2009-12 008325b0  unit: CRobloxTreeCtrl  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008325b0
//
// 008325b0  53                   push ebx
// 008325b1  8b1dc4cb9800         mov ebx, dword ptr [0x98cbc4]
// 008325b7  56                   push esi
// 008325b8  57                   push edi
// 008325b9  8bf9                 mov edi, ecx
// 008325bb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008325bf  8b4734               mov eax, dword ptr [edi + 0x34]
// 008325c2  8b5020               mov edx, dword ptr [eax + 0x20]
// 008325c5  51                   push ecx
// 008325c6  6a06                 push 6
// 008325c8  680a110000           push 0x110a
// 008325cd  52                   push edx
// 008325ce  ffd3                 call ebx
// 008325d0  8bf0                 mov esi, eax
// 008325d2  85f6                 test esi, esi
// 008325d4  7428                 je 0x8325fe
// 008325d6  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 008325d9  6a02                 push 2
// 008325db  56                   push esi
// 008325dc  e825410f00           call 0x926706
// 008325e1  a802                 test al, 2
// 008325e3  7517                 jne 0x8325fc
// 008325e5  8b4734               mov eax, dword ptr [edi + 0x34]
// 008325e8  8b4020               mov eax, dword ptr [eax + 0x20]
// 008325eb  56                   push esi
// 008325ec  6a06                 push 6
// 008325ee  680a110000           push 0x110a
// 008325f3  50                   push eax
// 008325f4  ffd3                 call ebx
// 008325f6  8bf0                 mov esi, eax
// 008325f8  85f6                 test esi, esi
// 008325fa  75da                 jne 0x8325d6
// 008325fc  8bc6                 mov eax, esi
// 008325fe  5f                   pop edi
// 008325ff  5e                   pop esi
// 00832600  5b                   pop ebx
// 00832601  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetNextSelectedItem@CXTPTreeBase@@QBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
