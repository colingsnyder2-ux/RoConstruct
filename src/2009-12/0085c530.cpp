// from server: 100% by auto
// roc 2009-12 0085c530  unit: CXTPStatusBar  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085c530
//
// 0085c530  83c8ff               or eax, 0xffffffff
// 0085c533  0bd0                 or edx, eax
// 0085c535  52                   push edx
// 0085c536  50                   push eax
// 0085c537  6a00                 push 0
// 0085c539  e8f2faffff           call 0x85c030
// 0085c53e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
