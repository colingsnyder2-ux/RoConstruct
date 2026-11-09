// from server: 100% by auto
// roc 2010-06 007b4860  unit: CXTPControlComboBoxPopupBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4860
//
// 007b4860  8b442404             mov eax, dword ptr [esp + 4]
// 007b4864  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007b4867  6a00                 push 0
// 007b4869  50                   push eax
// 007b486a  6886010000           push 0x186
// 007b486f  51                   push ecx
// 007b4870  ff1554ba9e00         call dword ptr [0x9eba54]
// 007b4876  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxmousepropertypage.cpp (function ?SetCurSel@CListBox@@QAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmousepropertypage.cpp
