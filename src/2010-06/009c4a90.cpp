// from server: 100% by auto
// roc 2010-06 009c4a90  unit: seg_009c0000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c4a90
//
// 009c4a90  68a423a100           push 0xa123a4
// 009c4a95  ff15b8bb9e00         call dword ptr [0x9ebbb8]
// 009c4a9b  a36021c000           mov dword ptr [0xc02160], eax
// 009c4aa0  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__Extp_wm_SwitchView@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
