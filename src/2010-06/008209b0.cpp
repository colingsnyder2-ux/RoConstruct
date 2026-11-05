// from server: 100% by auto
// roc 2010-06 008209b0  unit: CXTPReportColumns  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008209b0
//
// 008209b0  6aff                 push -1
// 008209b2  6a00                 push 0
// 008209b4  83c124               add ecx, 0x24
// 008209b7  e84409fcff           call 0x7e1300
// 008209bc  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPDatePickerDaysCollection.cpp (function ?Clear@CXTPDatePickerDaysCollection@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPDatePickerDaysCollection.cpp
