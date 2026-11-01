// from server: 100% by auto
// roc 2009-12 00969c20  unit: seg_00960000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969c20
//
// 00969c20  6a00                 push 0
// 00969c22  6a00                 push 0
// 00969c24  6a00                 push 0
// 00969c26  6a01                 push 1
// 00969c28  6a01                 push 1
// 00969c2a  6a64                 push 0x64
// 00969c2c  b960bbb700           mov ecx, 0xb7bb60
// 00969c31  e8da7db0ff           call 0x471a10
// 00969c36  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__ExtpCalendarDateTime_min@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
