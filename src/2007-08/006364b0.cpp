// from server: 100% by auto
// roc 2007-08 006364b0  unit: CXTPControlComboBox  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006364b0
//
// 006364b0  8b442404             mov eax, dword ptr [esp + 4]
// 006364b4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 006364b7  6a00                 push 0
// 006364b9  50                   push eax
// 006364ba  6886010000           push 0x186
// 006364bf  51                   push ecx
// 006364c0  ff15d8ec7700         call dword ptr [0x77ecd8]
// 006364c6  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\docmgr.cpp (function ?SetCurSel@CListBox@@QAEHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmgr.cpp
