// from server: 100% by auto
// roc 2009-06 00885860  unit: seg_00880000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00885860
//
// 00885860  689ccc8b00           push 0x8bcc9c
// 00885865  ff159ced8900         call dword ptr [0x89ed9c]
// 0088586b  a358b6a300           mov dword ptr [0xa3b658], eax
// 00885870  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__Extp_wm_SwitchView@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
