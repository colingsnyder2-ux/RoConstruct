// from server: 100% by auto
// roc 2009-06 007ced80  unit: CXTPDockingPaneMiniWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ced80
//
// 007ced80  8b81fc000000         mov eax, dword ptr [ecx + 0xfc]
// 007ced86  85c0                 test eax, eax
// 007ced88  7408                 je 0x7ced92
// 007ced8a  8d4854               lea ecx, [eax + 0x54]
// 007ced8d  e96e6f0000           jmp 0x7d5d00
// 007ced92  33c0                 xor eax, eax
// 007ced94  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?GetDockingPaneManager@CXTPDockingPaneAutoHideWnd@@ABEPAVCXTPDockingPaneManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
