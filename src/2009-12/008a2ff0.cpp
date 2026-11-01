// from server: 100% by auto
// roc 2009-12 008a2ff0  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a2ff0
//
// 008a2ff0  6aff                 push -1
// 008a2ff2  6a00                 push 0
// 008a2ff4  83c120               add ecx, 0x20
// 008a2ff7  e8a423fbff           call 0x8553a0
// 008a2ffc  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?RemoveAll@?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
