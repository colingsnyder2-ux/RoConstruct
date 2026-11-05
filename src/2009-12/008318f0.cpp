// from server: 100% by auto
// roc 2009-12 008318f0  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008318f0
//
// 008318f0  8b442404             mov eax, dword ptr [esp + 4]
// 008318f4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008318f7  50                   push eax
// 008318f8  6a09                 push 9
// 008318fa  680b110000           push 0x110b
// 008318ff  51                   push ecx
// 00831900  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00831906  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertysheet.cpp (function ?SelectItem@CTreeCtrl@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertysheet.cpp
