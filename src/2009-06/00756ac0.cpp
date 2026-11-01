// from server: 100% by auto
// roc 2009-06 00756ac0  unit: CXTTreeBase  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756ac0
//
// 00756ac0  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00756ac3  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00756ac6  6a00                 push 0
// 00756ac8  6a09                 push 9
// 00756aca  680a110000           push 0x110a
// 00756acf  50                   push eax
// 00756ad0  ff1590ee8900         call dword ptr [0x89ee90]
// 00756ad6  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetFocusedItem@CXTPTreeBase@@QBEPAU_TREEITEM@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
