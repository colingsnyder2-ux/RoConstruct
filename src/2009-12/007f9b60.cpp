// from server: 100% by auto
// roc 2009-12 007f9b60  unit: CXTPControlComboBoxPopupBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f9b60
//
// 007f9b60  8b442404             mov eax, dword ptr [esp + 4]
// 007f9b64  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007f9b67  6a00                 push 0
// 007f9b69  50                   push eax
// 007f9b6a  6886010000           push 0x186
// 007f9b6f  51                   push ecx
// 007f9b70  ff15c4cb9800         call dword ptr [0x98cbc4]
// 007f9b76  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\docmgr.cpp (function ?SetCurSel@CListBox@@QAEHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmgr.cpp
