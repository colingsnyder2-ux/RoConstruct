// from server: 100% by auto
// roc 2009-06 007d7580  unit: CXTPDockingPaneAutoHidePanel  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d7580
//
// 007d7580  8d41ac               lea eax, [ecx - 0x54]
// 007d7583  85c0                 test eax, eax
// 007d7585  7501                 jne 0x7d7588
// 007d7587  c3                   ret 
// 007d7588  8b4020               mov eax, dword ptr [eax + 0x20]
// 007d758b  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?GetPaneHwnd@CXTPDockingPaneAutoHidePanel@@UBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
