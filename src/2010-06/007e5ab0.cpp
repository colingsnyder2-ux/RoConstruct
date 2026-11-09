// from server: 100% by auto
// roc 2010-06 007e5ab0  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5ab0
//
// 007e5ab0  8b442404             mov eax, dword ptr [esp + 4]
// 007e5ab4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007e5ab7  50                   push eax
// 007e5ab8  6a09                 push 9
// 007e5aba  680b110000           push 0x110b
// 007e5abf  51                   push ecx
// 007e5ac0  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e5ac6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertysheet.cpp (function ?SelectItem@CTreeCtrl@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertysheet.cpp
