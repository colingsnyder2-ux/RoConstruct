// from server: 100% by auto
// roc 2010-06 007aa670  unit: CPatchedControlComboBox  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007aa670
//
// 007aa670  8b442404             mov eax, dword ptr [esp + 4]
// 007aa674  8b5004               mov edx, dword ptr [eax + 4]
// 007aa677  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007aa67a  52                   push edx
// 007aa67b  50                   push eax
// 007aa67c  ff1568ba9e00         call dword ptr [0x9eba68]
// 007aa682  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ReleaseDC@CWnd@@QAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
