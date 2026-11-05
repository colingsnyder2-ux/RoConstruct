// from server: 100% by auto
// roc 2010-06 007d72c0  unit: CXTPReportControl  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d72c0
//
// 007d72c0  83c8ff               or eax, 0xffffffff
// 007d72c3  0bd0                 or edx, eax
// 007d72c5  52                   push edx
// 007d72c6  50                   push eax
// 007d72c7  6a00                 push 0
// 007d72c9  e812ddffff           call 0x7d4fe0
// 007d72ce  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMessageBar.cpp
