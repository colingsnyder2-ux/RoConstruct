// from server: 100% by auto
// roc 2009-12 00969c00  unit: seg_00960000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969c00
//
// 00969c00  a160bab000           mov eax, dword ptr [0xb0ba60]
// 00969c05  50                   push eax
// 00969c06  ff1530ca9800         call dword ptr [0x98ca30]
// 00969c0c  a37cbbb700           mov dword ptr [0xb7bb7c], eax
// 00969c11  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__Extp_wm_NotificationSinkMTOnEvent@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
