// from server: 100% by auto
// roc 2009-12 00969c40  unit: seg_00960000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969c40
//
// 00969c40  6a00                 push 0
// 00969c42  6a00                 push 0
// 00969c44  6a00                 push 0
// 00969c46  6a1f                 push 0x1f
// 00969c48  6a0c                 push 0xc
// 00969c4a  680f270000           push 0x270f
// 00969c4f  b96cbbb700           mov ecx, 0xb7bb6c
// 00969c54  e8b77db0ff           call 0x471a10
// 00969c59  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__ExtpCalendarDateTime_max@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
