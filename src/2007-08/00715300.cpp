// from server: 100% by auto
// roc 2007-08 00715300  unit: CXTCaptionButton  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00715300
//
// 00715300  83c8ff               or eax, 0xffffffff
// 00715303  0bd0                 or edx, eax
// 00715305  52                   push edx
// 00715306  50                   push eax
// 00715307  6a00                 push 0
// 00715309  e802fcffff           call 0x714f10
// 0071530e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
