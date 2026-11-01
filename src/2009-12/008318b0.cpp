// from server: 100% by auto
// roc 2009-12 008318b0  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008318b0
//
// 008318b0  8b442404             mov eax, dword ptr [esp + 4]
// 008318b4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008318b7  50                   push eax
// 008318b8  6a06                 push 6
// 008318ba  680a110000           push 0x110a
// 008318bf  51                   push ecx
// 008318c0  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008318c6  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetNextVisibleItem@CTreeCtrl@@QBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
