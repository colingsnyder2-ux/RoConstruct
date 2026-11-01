// from server: 100% by auto
// roc 2007-03 0076e740  unit: seg_00760000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0076e740
//
// 0076e740  a158958800           mov eax, dword ptr [0x889558]
// 0076e745  50                   push eax
// 0076e746  ff15c0ed7700         call dword ptr [0x77edc0]
// 0076e74c  a374668b00           mov dword ptr [0x8b6674], eax
// 0076e751  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__Extp_wm_NotificationSinkMTOnEvent@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
