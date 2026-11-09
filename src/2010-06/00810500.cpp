// from server: 100% by auto
// roc 2010-06 00810500  unit: CXTPStatusBar  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00810500
//
// 00810500  83c8ff               or eax, 0xffffffff
// 00810503  0bd0                 or edx, eax
// 00810505  52                   push edx
// 00810506  50                   push eax
// 00810507  6a00                 push 0
// 00810509  e8f2faffff           call 0x810000
// 0081050e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMessageBar.cpp
