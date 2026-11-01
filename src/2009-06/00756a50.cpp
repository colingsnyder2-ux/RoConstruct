// from server: 100% by auto
// roc 2009-06 00756a50  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756a50
//
// 00756a50  8b442404             mov eax, dword ptr [esp + 4]
// 00756a54  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00756a57  50                   push eax
// 00756a58  6a07                 push 7
// 00756a5a  680a110000           push 0x110a
// 00756a5f  51                   push ecx
// 00756a60  ff1590ee8900         call dword ptr [0x89ee90]
// 00756a66  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetPrevVisibleItem@CTreeCtrl@@QBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
