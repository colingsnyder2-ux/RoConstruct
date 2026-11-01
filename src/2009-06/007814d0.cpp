// from server: 100% by auto
// roc 2009-06 007814d0  unit: CXTPStatusBar  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007814d0
//
// 007814d0  83c8ff               or eax, 0xffffffff
// 007814d3  0bd0                 or edx, eax
// 007814d5  52                   push edx
// 007814d6  50                   push eax
// 007814d7  6a00                 push 0
// 007814d9  e8f2faffff           call 0x780fd0
// 007814de  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
