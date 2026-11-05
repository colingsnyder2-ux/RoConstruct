// from server: 100% by auto
// roc 2009-06 00756a70  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756a70
//
// 00756a70  8b442404             mov eax, dword ptr [esp + 4]
// 00756a74  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00756a77  50                   push eax
// 00756a78  6a09                 push 9
// 00756a7a  680b110000           push 0x110b
// 00756a7f  51                   push ecx
// 00756a80  ff1590ee8900         call dword ptr [0x89ee90]
// 00756a86  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertysheet.cpp (function ?SelectItem@CTreeCtrl@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertysheet.cpp
