// from server: 100% by auto
// roc 2011-06 00847300  unit: CXTTreeBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00847300
//
// 00847300  8b442404             mov eax, dword ptr [esp + 4]
// 00847304  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00847307  50                   push eax
// 00847308  6a09                 push 9
// 0084730a  680b110000           push 0x110b
// 0084730f  51                   push ecx
// 00847310  ff15c019a400         call dword ptr [0xa419c0]
// 00847316  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertysheet.cpp (function ?SelectItem@CTreeCtrl@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertysheet.cpp
