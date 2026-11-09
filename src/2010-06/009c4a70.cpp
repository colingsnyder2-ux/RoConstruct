// from server: 100% by auto
// roc 2010-06 009c4a70  unit: seg_009c0000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c4a70
//
// 009c4a70  6a00                 push 0
// 009c4a72  6a00                 push 0
// 009c4a74  6a00                 push 0
// 009c4a76  6a1f                 push 0x1f
// 009c4a78  6a0c                 push 0xc
// 009c4a7a  680f270000           push 0x270f
// 009c4a7f  b94c21c000           mov ecx, 0xc0214c
// 009c4a84  e85729abff           call 0x4773e0
// 009c4a89  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__ExtpCalendarDateTime_max@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
