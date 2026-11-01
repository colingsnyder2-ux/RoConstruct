// from server: 100% by auto
// roc 2009-12 008ab210  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ab210
//
// 008ab210  83c8ff               or eax, 0xffffffff
// 008ab213  0bd0                 or edx, eax
// 008ab215  52                   push edx
// 008ab216  50                   push eax
// 008ab217  6a00                 push 0
// 008ab219  e852ffffff           call 0x8ab170
// 008ab21e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
