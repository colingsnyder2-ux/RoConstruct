// from server: 100% by auto
// roc 2010-06 009c4a50  unit: seg_009c0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c4a50
//
// 009c4a50  6a00                 push 0
// 009c4a52  6a00                 push 0
// 009c4a54  6a00                 push 0
// 009c4a56  6a01                 push 1
// 009c4a58  6a01                 push 1
// 009c4a5a  6a64                 push 0x64
// 009c4a5c  b94021c000           mov ecx, 0xc02140
// 009c4a61  e87a29abff           call 0x4773e0
// 009c4a66  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__ExtpCalendarDateTime_min@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
