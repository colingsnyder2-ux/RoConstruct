// from server: 100% by auto
// roc 2007-03 0076e760  unit: seg_00760000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0076e760
//
// 0076e760  6a00                 push 0
// 0076e762  6a00                 push 0
// 0076e764  6a00                 push 0
// 0076e766  6a01                 push 1
// 0076e768  6a01                 push 1
// 0076e76a  6a64                 push 0x64
// 0076e76c  b95c668b00           mov ecx, 0x8b665c
// 0076e771  e8aa22cfff           call 0x460a20
// 0076e776  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__ExtpCalendarDateTime_min@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
