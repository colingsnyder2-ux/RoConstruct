// from server: 100% by auto
// roc 2009-12 00969c80  unit: seg_00960000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969c80
//
// 00969c80  6834129b00           push 0x9b1234
// 00969c85  ff1530ca9800         call dword ptr [0x98ca30]
// 00969c8b  a378bbb700           mov dword ptr [0xb7bb78], eax
// 00969c90  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__Extp_wm_UserAction@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
