// from server: 100% by auto
// roc 2009-12 008b26c0  unit: CXTPDockingPaneTabbedContainer  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b26c0
//
// 008b26c0  83c8ff               or eax, 0xffffffff
// 008b26c3  0bd0                 or edx, eax
// 008b26c5  52                   push edx
// 008b26c6  50                   push eax
// 008b26c7  6a00                 push 0
// 008b26c9  e872feffff           call 0x8b2540
// 008b26ce  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
