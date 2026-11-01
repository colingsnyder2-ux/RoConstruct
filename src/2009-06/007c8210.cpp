// from server: 100% by auto
// roc 2009-06 007c8210  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c8210
//
// 007c8210  6aff                 push -1
// 007c8212  6a00                 push 0
// 007c8214  83c120               add ecx, 0x20
// 007c8217  e8f4a2f8ff           call 0x752510
// 007c821c  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?RemoveAll@?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
