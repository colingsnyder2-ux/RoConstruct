// from server: 100% by auto
// roc 2007-08 0065ac70  unit: CXTPReportControl  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0065ac70
//
// 0065ac70  83c8ff               or eax, 0xffffffff
// 0065ac73  0bd0                 or edx, eax
// 0065ac75  52                   push edx
// 0065ac76  50                   push eax
// 0065ac77  6a00                 push 0
// 0065ac79  e812ddffff           call 0x658990
// 0065ac7e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
