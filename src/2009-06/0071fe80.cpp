// from server: 100% by auto
// roc 2009-06 0071fe80  unit: CPatchedControlComboBox  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071fe80
//
// 0071fe80  8b442404             mov eax, dword ptr [esp + 4]
// 0071fe84  8b5004               mov edx, dword ptr [eax + 4]
// 0071fe87  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0071fe8a  52                   push edx
// 0071fe8b  50                   push eax
// 0071fe8c  ff1540ed8900         call dword ptr [0x89ed40]
// 0071fe92  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ReleaseDC@CWnd@@QAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
