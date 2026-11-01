// from server: 100% by auto
// roc 2009-12 008aa390  unit: CXTPDockingPaneAutoHideWnd  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008aa390
//
// 008aa390  83b91001000000       cmp dword ptr [ecx + 0x110], 0
// 008aa397  740a                 je 0x8aa3a3
// 008aa399  6a01                 push 1
// 008aa39b  e860fdffff           call 0x8aa100
// 008aa3a0  c20c00               ret 0xc
// 008aa3a3  e8889af4ff           call 0x7f3e30
// 008aa3a8  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?OnMouseMove@CXTPDockingPaneAutoHideWnd@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
