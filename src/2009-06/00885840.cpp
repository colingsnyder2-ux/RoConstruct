// from server: 100% by auto
// roc 2009-06 00885840  unit: seg_00880000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00885840
//
// 00885840  6a00                 push 0
// 00885842  6a00                 push 0
// 00885844  6a00                 push 0
// 00885846  6a1f                 push 0x1f
// 00885848  6a0c                 push 0xc
// 0088584a  680f270000           push 0x270f
// 0088584f  b944b6a300           mov ecx, 0xa3b644
// 00885854  e8f732beff           call 0x468b50
// 00885859  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__ExtpCalendarDateTime_max@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
