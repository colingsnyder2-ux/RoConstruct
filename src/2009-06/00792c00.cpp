// from server: 100% by auto
// roc 2009-06 00792c00  unit: CXTPReportColumns  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00792c00
//
// 00792c00  6aff                 push -1
// 00792c02  6a00                 push 0
// 00792c04  83c124               add ecx, 0x24
// 00792c07  e804f9fbff           call 0x752510
// 00792c0c  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPDatePickerDaysCollection.cpp (function ?Clear@CXTPDatePickerDaysCollection@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPDatePickerDaysCollection.cpp
