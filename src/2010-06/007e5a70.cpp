// from server: 100% by auto
// roc 2010-06 007e5a70  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5a70
//
// 007e5a70  8b442404             mov eax, dword ptr [esp + 4]
// 007e5a74  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007e5a77  50                   push eax
// 007e5a78  6a06                 push 6
// 007e5a7a  680a110000           push 0x110a
// 007e5a7f  51                   push ecx
// 007e5a80  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e5a86  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetNextVisibleItem@CTreeCtrl@@QBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
