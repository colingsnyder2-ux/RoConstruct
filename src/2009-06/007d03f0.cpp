// from server: 100% by auto
// roc 2009-06 007d03f0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d03f0
//
// 007d03f0  83c8ff               or eax, 0xffffffff
// 007d03f3  0bd0                 or edx, eax
// 007d03f5  52                   push edx
// 007d03f6  50                   push eax
// 007d03f7  6a00                 push 0
// 007d03f9  e852ffffff           call 0x7d0350
// 007d03fe  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
