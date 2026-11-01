// from server: 100% by auto
// roc 2009-12 00823260  unit: CXTPReportControl  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823260
//
// 00823260  83c8ff               or eax, 0xffffffff
// 00823263  0bd0                 or edx, eax
// 00823265  52                   push edx
// 00823266  50                   push eax
// 00823267  6a00                 push 0
// 00823269  e812ddffff           call 0x820f80
// 0082326e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
