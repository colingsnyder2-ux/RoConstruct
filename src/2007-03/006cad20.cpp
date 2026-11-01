// from server: 100% by auto
// roc 2007-03 006cad20  unit: seg_006c0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006cad20
//
// 006cad20  8d41ac               lea eax, [ecx - 0x54]
// 006cad23  85c0                 test eax, eax
// 006cad25  7501                 jne 0x6cad28
// 006cad27  c3                   ret 
// 006cad28  8b4020               mov eax, dword ptr [eax + 0x20]
// 006cad2b  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?GetPaneHwnd@CXTPDockingPaneAutoHidePanel@@UBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
