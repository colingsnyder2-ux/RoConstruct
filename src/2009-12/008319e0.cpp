// from server: 100% by auto
// roc 2009-12 008319e0  unit: CRobloxTreeCtrl  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008319e0
//
// 008319e0  53                   push ebx
// 008319e1  8b1dc4cb9800         mov ebx, dword ptr [0x98cbc4]
// 008319e7  56                   push esi
// 008319e8  57                   push edi
// 008319e9  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008319ed  57                   push edi
// 008319ee  8bf1                 mov esi, ecx
// 008319f0  8b4634               mov eax, dword ptr [esi + 0x34]
// 008319f3  8b4020               mov eax, dword ptr [eax + 0x20]
// 008319f6  6a02                 push 2
// 008319f8  680a110000           push 0x110a
// 008319fd  50                   push eax
// 008319fe  ffd3                 call ebx
// 00831a00  85c0                 test eax, eax
// 00831a02  7517                 jne 0x831a1b
// 00831a04  8b7634               mov esi, dword ptr [esi + 0x34]
// 00831a07  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00831a0a  57                   push edi
// 00831a0b  6a03                 push 3
// 00831a0d  680a110000           push 0x110a
// 00831a12  51                   push ecx
// 00831a13  ffd3                 call ebx
// 00831a15  5f                   pop edi
// 00831a16  5e                   pop esi
// 00831a17  5b                   pop ebx
// 00831a18  c20400               ret 4
// 00831a1b  8b16                 mov edx, dword ptr [esi]
// 00831a1d  50                   push eax
// 00831a1e  8b4210               mov eax, dword ptr [edx + 0x10]
// 00831a21  8bce                 mov ecx, esi
// 00831a23  ffd0                 call eax
// 00831a25  5f                   pop edi
// 00831a26  5e                   pop esi
// 00831a27  5b                   pop ebx
// 00831a28  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetPrevItem@CXTPTreeBase@@UBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
