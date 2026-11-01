// from server: 100% by auto
// roc 2007-08 006e2250  unit: CXTPDockingPaneTabbedContainer  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006e2250
//
// 006e2250  83c8ff               or eax, 0xffffffff
// 006e2253  0bd0                 or edx, eax
// 006e2255  52                   push edx
// 006e2256  50                   push eax
// 006e2257  6a00                 push 0
// 006e2259  e872feffff           call 0x6e20d0
// 006e225e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
