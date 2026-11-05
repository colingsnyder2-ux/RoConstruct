// from server: 100% by auto
// roc 2010-06 008667b0  unit: CXTPDockingPaneTabbedContainer  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008667b0
//
// 008667b0  83c8ff               or eax, 0xffffffff
// 008667b3  0bd0                 or edx, eax
// 008667b5  52                   push edx
// 008667b6  50                   push eax
// 008667b7  6a00                 push 0
// 008667b9  e872feffff           call 0x866630
// 008667be  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMessageBar.cpp
