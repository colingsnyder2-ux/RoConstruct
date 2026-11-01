// from server: 100% by auto
// roc 2007-08 006db070  unit: CXTPReportControl::CReportDropTarget  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006db070
//
// 006db070  83c8ff               or eax, 0xffffffff
// 006db073  0bd0                 or edx, eax
// 006db075  52                   push edx
// 006db076  50                   push eax
// 006db077  6a00                 push 0
// 006db079  e852ffffff           call 0x6dafd0
// 006db07e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMessageBar.cpp (function ?OnMouseLeave@CXTPMessageBar@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMessageBar.cpp
