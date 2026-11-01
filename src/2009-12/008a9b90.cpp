// from server: 100% by auto
// roc 2009-12 008a9b90  unit: CXTPDockingPaneMiniWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a9b90
//
// 008a9b90  8b81fc000000         mov eax, dword ptr [ecx + 0xfc]
// 008a9b96  85c0                 test eax, eax
// 008a9b98  7408                 je 0x8a9ba2
// 008a9b9a  8d4854               lea ecx, [eax + 0x54]
// 008a9b9d  e99e6c0000           jmp 0x8b0840
// 008a9ba2  33c0                 xor eax, eax
// 008a9ba4  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?GetDockingPaneManager@CXTPDockingPaneAutoHideWnd@@ABEPAVCXTPDockingPaneManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
