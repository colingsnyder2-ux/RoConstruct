// from server: 100% by auto
// roc 2009-12 0086dc20  unit: CXTPReportColumns  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086dc20
//
// 0086dc20  6aff                 push -1
// 0086dc22  6a00                 push 0
// 0086dc24  83c124               add ecx, 0x24
// 0086dc27  e87477feff           call 0x8553a0
// 0086dc2c  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPDatePickerDaysCollection.cpp (function ?Clear@CXTPDatePickerDaysCollection@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPDatePickerDaysCollection.cpp
