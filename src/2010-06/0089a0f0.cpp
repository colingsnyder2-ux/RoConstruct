// from server: 100% by auto
// roc 2010-06 0089a0f0  unit: CXTCaptionButton  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089a0f0
//
// 0089a0f0  83c8ff               or eax, 0xffffffff
// 0089a0f3  0bd0                 or edx, eax
// 0089a0f5  52                   push edx
// 0089a0f6  50                   push eax
// 0089a0f7  6a00                 push 0
// 0089a0f9  e802fcffff           call 0x899d00
// 0089a0fe  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMessageBar.cpp
