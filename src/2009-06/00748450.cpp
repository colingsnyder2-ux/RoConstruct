// from server: 100% by auto
// roc 2009-06 00748450  unit: CXTPReportControl  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748450
//
// 00748450  83c8ff               or eax, 0xffffffff
// 00748453  0bd0                 or edx, eax
// 00748455  52                   push edx
// 00748456  50                   push eax
// 00748457  6a00                 push 0
// 00748459  e812ddffff           call 0x746170
// 0074845e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
