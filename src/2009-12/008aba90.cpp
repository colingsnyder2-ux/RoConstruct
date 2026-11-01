// from server: 100% by auto
// roc 2009-12 008aba90  unit: CXTPDockingPaneAutoHidePanel  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008aba90
//
// 008aba90  8d41ac               lea eax, [ecx - 0x54]
// 008aba93  85c0                 test eax, eax
// 008aba95  7501                 jne 0x8aba98
// 008aba97  c3                   ret 
// 008aba98  8b4020               mov eax, dword ptr [eax + 0x20]
// 008aba9b  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?GetPaneHwnd@CXTPDockingPaneAutoHidePanel@@UBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
