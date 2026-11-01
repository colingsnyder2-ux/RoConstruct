// from server: 100% by auto
// roc 2009-06 00885820  unit: seg_00880000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00885820
//
// 00885820  6a00                 push 0
// 00885822  6a00                 push 0
// 00885824  6a00                 push 0
// 00885826  6a01                 push 1
// 00885828  6a01                 push 1
// 0088582a  6a64                 push 0x64
// 0088582c  b938b6a300           mov ecx, 0xa3b638
// 00885831  e81a33beff           call 0x468b50
// 00885836  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__ExtpCalendarDateTime_min@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
