// from server: 100% by auto
// roc 2010-06 009c4a30  unit: seg_009c0000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c4a30
//
// 009c4a30  a17854b800           mov eax, dword ptr [0xb85478]
// 009c4a35  50                   push eax
// 009c4a36  ff15b8bb9e00         call dword ptr [0x9ebbb8]
// 009c4a3c  a35c21c000           mov dword ptr [0xc0215c], eax
// 009c4a41  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__Extp_wm_NotificationSinkMTOnEvent@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
