// from server: 100% by auto
// roc 2010-06 0085dcd0  unit: CXTPDockingPaneMiniWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085dcd0
//
// 0085dcd0  8b81fc000000         mov eax, dword ptr [ecx + 0xfc]
// 0085dcd6  85c0                 test eax, eax
// 0085dcd8  7408                 je 0x85dce2
// 0085dcda  8d4854               lea ecx, [eax + 0x54]
// 0085dcdd  e92e6c0000           jmp 0x864910
// 0085dce2  33c0                 xor eax, eax
// 0085dce4  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?GetDockingPaneManager@CXTPDockingPaneAutoHideWnd@@ABEPAVCXTPDockingPaneManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
