// from server: 100% by auto
// roc 2008-06 006a7360  unit: CXTPControlComboBox  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a7360
//
// 006a7360  8b442404             mov eax, dword ptr [esp + 4]
// 006a7364  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 006a7367  6a00                 push 0
// 006a7369  50                   push eax
// 006a736a  6886010000           push 0x186
// 006a736f  51                   push ecx
// 006a7370  ff15142e8000         call dword ptr [0x802e14]
// 006a7376  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxmousepropertypage.cpp (function ?SetCurSel@CListBox@@QAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmousepropertypage.cpp
