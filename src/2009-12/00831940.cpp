// from server: 100% by auto
// roc 2009-12 00831940  unit: CXTTreeBase  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00831940
//
// 00831940  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00831943  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00831946  6a00                 push 0
// 00831948  6a09                 push 9
// 0083194a  680a110000           push 0x110a
// 0083194f  50                   push eax
// 00831950  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00831956  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetFocusedItem@CXTPTreeBase@@QBEPAU_TREEITEM@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
