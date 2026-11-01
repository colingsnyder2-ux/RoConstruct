// from server: 100% by auto
// roc 2007-03 006514a0  unit: seg_00650000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006514a0
//
// 006514a0  8b442404             mov eax, dword ptr [esp + 4]
// 006514a4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 006514a7  50                   push eax
// 006514a8  6a09                 push 9
// 006514aa  680b110000           push 0x110b
// 006514af  51                   push ecx
// 006514b0  ff1550ee7700         call dword ptr [0x77ee50]
// 006514b6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertysheet.cpp (function ?SelectItem@CTreeCtrl@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertysheet.cpp
