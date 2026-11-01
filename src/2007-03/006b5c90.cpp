// from server: 100% by auto
// roc 2007-03 006b5c90  unit: seg_006b0000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b5c90
//
// 006b5c90  6aff                 push -1
// 006b5c92  6a00                 push 0
// 006b5c94  83c120               add ecx, 0x20
// 006b5c97  e88455daff           call 0x45b220
// 006b5c9c  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?RemoveAll@?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
