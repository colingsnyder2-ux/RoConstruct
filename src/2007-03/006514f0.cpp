// from server: 100% by auto
// roc 2007-03 006514f0  unit: seg_00650000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006514f0
//
// 006514f0  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 006514f3  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006514f6  6a00                 push 0
// 006514f8  6a09                 push 9
// 006514fa  680a110000           push 0x110a
// 006514ff  50                   push eax
// 00651500  ff1550ee7700         call dword ptr [0x77ee50]
// 00651506  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetFocusedItem@CXTPTreeBase@@QBEPAU_TREEITEM@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
