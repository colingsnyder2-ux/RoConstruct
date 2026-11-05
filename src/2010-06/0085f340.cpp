// from server: 100% by auto
// roc 2010-06 0085f340  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085f340
//
// 0085f340  83c8ff               or eax, 0xffffffff
// 0085f343  0bd0                 or edx, eax
// 0085f345  52                   push edx
// 0085f346  50                   push eax
// 0085f347  6a00                 push 0
// 0085f349  e852ffffff           call 0x85f2a0
// 0085f34e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMessageBar.cpp
