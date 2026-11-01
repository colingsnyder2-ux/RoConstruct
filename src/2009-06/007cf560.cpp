// from server: 100% by auto
// roc 2009-06 007cf560  unit: CXTPDockingPaneAutoHideWnd  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cf560
//
// 007cf560  83b91001000000       cmp dword ptr [ecx + 0x110], 0
// 007cf567  740a                 je 0x7cf573
// 007cf569  6a01                 push 1
// 007cf56b  e860fdffff           call 0x7cf2d0
// 007cf570  c20c00               ret 0xc
// 007cf573  e8909af4ff           call 0x719008
// 007cf578  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?OnMouseMove@CXTPDockingPaneAutoHideWnd@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
