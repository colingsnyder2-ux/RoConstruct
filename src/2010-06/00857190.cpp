// from server: 100% by auto
// roc 2010-06 00857190  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00857190
//
// 00857190  6aff                 push -1
// 00857192  6a00                 push 0
// 00857194  83c120               add ecx, 0x20
// 00857197  e864a1f8ff           call 0x7e1300
// 0085719c  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?RemoveAll@?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
