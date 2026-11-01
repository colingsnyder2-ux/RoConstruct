// from server: 100% by auto
// roc 2009-06 00885880  unit: seg_00880000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00885880
//
// 00885880  6884cc8b00           push 0x8bcc84
// 00885885  ff159ced8900         call dword ptr [0x89ed9c]
// 0088588b  a350b6a300           mov dword ptr [0xa3b650], eax
// 00885890  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__Extp_wm_UserAction@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
