// from server: 100% by auto
// roc 2010-06 007e5a90  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5a90
//
// 007e5a90  8b442404             mov eax, dword ptr [esp + 4]
// 007e5a94  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007e5a97  50                   push eax
// 007e5a98  6a07                 push 7
// 007e5a9a  680a110000           push 0x110a
// 007e5a9f  51                   push ecx
// 007e5aa0  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e5aa6  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetPrevVisibleItem@CTreeCtrl@@QBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
