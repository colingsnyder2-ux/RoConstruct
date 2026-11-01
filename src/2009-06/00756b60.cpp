// from server: 100% by auto
// roc 2009-06 00756b60  unit: CRobloxTreeCtrl  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756b60
//
// 00756b60  53                   push ebx
// 00756b61  8b1d90ee8900         mov ebx, dword ptr [0x89ee90]
// 00756b67  56                   push esi
// 00756b68  57                   push edi
// 00756b69  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00756b6d  57                   push edi
// 00756b6e  8bf1                 mov esi, ecx
// 00756b70  8b4634               mov eax, dword ptr [esi + 0x34]
// 00756b73  8b4020               mov eax, dword ptr [eax + 0x20]
// 00756b76  6a02                 push 2
// 00756b78  680a110000           push 0x110a
// 00756b7d  50                   push eax
// 00756b7e  ffd3                 call ebx
// 00756b80  85c0                 test eax, eax
// 00756b82  7517                 jne 0x756b9b
// 00756b84  8b7634               mov esi, dword ptr [esi + 0x34]
// 00756b87  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00756b8a  57                   push edi
// 00756b8b  6a03                 push 3
// 00756b8d  680a110000           push 0x110a
// 00756b92  51                   push ecx
// 00756b93  ffd3                 call ebx
// 00756b95  5f                   pop edi
// 00756b96  5e                   pop esi
// 00756b97  5b                   pop ebx
// 00756b98  c20400               ret 4
// 00756b9b  8b16                 mov edx, dword ptr [esi]
// 00756b9d  50                   push eax
// 00756b9e  8b4210               mov eax, dword ptr [edx + 0x10]
// 00756ba1  8bce                 mov ecx, esi
// 00756ba3  ffd0                 call eax
// 00756ba5  5f                   pop edi
// 00756ba6  5e                   pop esi
// 00756ba7  5b                   pop ebx
// 00756ba8  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetPrevItem@CXTPTreeBase@@UBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
