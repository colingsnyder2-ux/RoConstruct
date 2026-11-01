// from server: 100% by auto
// roc 2009-06 0080b2e0  unit: CXTCaptionButton  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080b2e0
//
// 0080b2e0  83c8ff               or eax, 0xffffffff
// 0080b2e3  0bd0                 or edx, eax
// 0080b2e5  52                   push edx
// 0080b2e6  50                   push eax
// 0080b2e7  6a00                 push 0
// 0080b2e9  e802fcffff           call 0x80aef0
// 0080b2ee  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
