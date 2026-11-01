// from server: 100% by auto
// roc 2009-12 008e5dd0  unit: CXTCaptionButton  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5dd0
//
// 008e5dd0  83c8ff               or eax, 0xffffffff
// 008e5dd3  0bd0                 or edx, eax
// 008e5dd5  52                   push edx
// 008e5dd6  50                   push eax
// 008e5dd7  6a00                 push 0
// 008e5dd9  e802fcffff           call 0x8e59e0
// 008e5dde  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
