// from server: 100% by auto
// roc 2009-06 00885800  unit: seg_00880000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00885800
//
// 00885800  a1286d9e00           mov eax, dword ptr [0x9e6d28]
// 00885805  50                   push eax
// 00885806  ff159ced8900         call dword ptr [0x89ed9c]
// 0088580c  a354b6a300           mov dword ptr [0xa3b654], eax
// 00885811  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__Extp_wm_NotificationSinkMTOnEvent@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
