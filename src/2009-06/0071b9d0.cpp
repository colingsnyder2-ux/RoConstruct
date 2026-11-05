// from server: 100% by auto
// roc 2009-06 0071b9d0  unit: CXTPControlComboBox  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071b9d0
//
// 0071b9d0  8b442404             mov eax, dword ptr [esp + 4]
// 0071b9d4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0071b9d7  6a00                 push 0
// 0071b9d9  50                   push eax
// 0071b9da  6886010000           push 0x186
// 0071b9df  51                   push ecx
// 0071b9e0  ff1590ee8900         call dword ptr [0x89ee90]
// 0071b9e6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxmousepropertypage.cpp (function ?SetCurSel@CListBox@@QAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmousepropertypage.cpp
