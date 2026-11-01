// from server: 100% by auto
// roc 2009-12 008318d0  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008318d0
//
// 008318d0  8b442404             mov eax, dword ptr [esp + 4]
// 008318d4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008318d7  50                   push eax
// 008318d8  6a07                 push 7
// 008318da  680a110000           push 0x110a
// 008318df  51                   push ecx
// 008318e0  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008318e6  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetPrevVisibleItem@CTreeCtrl@@QBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
