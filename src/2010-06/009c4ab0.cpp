// from server: 100% by auto
// roc 2010-06 009c4ab0  unit: seg_009c0000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c4ab0
//
// 009c4ab0  688c23a100           push 0xa1238c
// 009c4ab5  ff15b8bb9e00         call dword ptr [0x9ebbb8]
// 009c4abb  a35821c000           mov dword ptr [0xc02158], eax
// 009c4ac0  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__Extp_wm_UserAction@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
