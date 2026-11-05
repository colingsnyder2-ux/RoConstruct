// from server: 100% by auto
// roc 2010-06 0085e4a0  unit: CXTPDockingPaneAutoHideWnd  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085e4a0
//
// 0085e4a0  83b91001000000       cmp dword ptr [ecx + 0x110], 0
// 0085e4a7  740a                 je 0x85e4b3
// 0085e4a9  6a01                 push 1
// 0085e4ab  e860fdffff           call 0x85e210
// 0085e4b0  c20c00               ret 0xc
// 0085e4b3  e8b89af4ff           call 0x7a7f70
// 0085e4b8  c20c00               ret 0xc
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?OnMouseMove@CXTPDockingPaneAutoHideWnd@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
