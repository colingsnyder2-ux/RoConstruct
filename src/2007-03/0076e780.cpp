// from server: 100% by auto
// roc 2007-03 0076e780  unit: seg_00760000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0076e780
//
// 0076e780  6a00                 push 0
// 0076e782  6a00                 push 0
// 0076e784  6a00                 push 0
// 0076e786  6a1f                 push 0x1f
// 0076e788  6a0c                 push 0xc
// 0076e78a  680f270000           push 0x270f
// 0076e78f  b968668b00           mov ecx, 0x8b6668
// 0076e794  e88722cfff           call 0x460a20
// 0076e799  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__ExtpCalendarDateTime_max@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
