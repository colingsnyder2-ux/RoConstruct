// from server: 100% by auto
// roc 2007-08 0063a560  unit: CPatchedControlComboBox  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0063a560
//
// 0063a560  8b442404             mov eax, dword ptr [esp + 4]
// 0063a564  8b5004               mov edx, dword ptr [eax + 4]
// 0063a567  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0063a56a  52                   push edx
// 0063a56b  50                   push eax
// 0063a56c  ff1524ed7700         call dword ptr [0x77ed24]
// 0063a572  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ReleaseDC@CWnd@@QAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
