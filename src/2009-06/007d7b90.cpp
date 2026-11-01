// from server: 100% by auto
// roc 2009-06 007d7b90  unit: CXTPDockingPaneTabbedContainer  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d7b90
//
// 007d7b90  83c8ff               or eax, 0xffffffff
// 007d7b93  0bd0                 or edx, eax
// 007d7b95  52                   push edx
// 007d7b96  50                   push eax
// 007d7b97  6a00                 push 0
// 007d7b99  e872feffff           call 0x7d7a10
// 007d7b9e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
