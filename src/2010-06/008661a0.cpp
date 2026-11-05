// from server: 100% by auto
// roc 2010-06 008661a0  unit: CXTPDockingPaneAutoHidePanel  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008661a0
//
// 008661a0  8d41ac               lea eax, [ecx - 0x54]
// 008661a3  85c0                 test eax, eax
// 008661a5  7501                 jne 0x8661a8
// 008661a7  c3                   ret 
// 008661a8  8b4020               mov eax, dword ptr [eax + 0x20]
// 008661ab  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?GetPaneHwnd@CXTPDockingPaneAutoHidePanel@@UBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
