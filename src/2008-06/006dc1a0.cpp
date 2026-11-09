// from server: 100% by auto
// roc 2008-06 006dc1a0  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006dc1a0
//
// 006dc1a0  8b442404             mov eax, dword ptr [esp + 4]
// 006dc1a4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 006dc1a7  50                   push eax
// 006dc1a8  6a09                 push 9
// 006dc1aa  680b110000           push 0x110b
// 006dc1af  51                   push ecx
// 006dc1b0  ff15142e8000         call dword ptr [0x802e14]
// 006dc1b6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertysheet.cpp (function ?SelectItem@CTreeCtrl@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertysheet.cpp
