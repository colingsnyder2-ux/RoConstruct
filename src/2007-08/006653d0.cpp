// from server: 100% by auto
// roc 2007-08 006653d0  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006653d0
//
// 006653d0  8b442404             mov eax, dword ptr [esp + 4]
// 006653d4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 006653d7  50                   push eax
// 006653d8  6a09                 push 9
// 006653da  680b110000           push 0x110b
// 006653df  51                   push ecx
// 006653e0  ff15d8ec7700         call dword ptr [0x77ecd8]
// 006653e6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertysheet.cpp (function ?SelectItem@CTreeCtrl@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertysheet.cpp
