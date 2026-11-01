// from server: 100% by auto
// roc 2007-03 0076e7a0  unit: seg_00760000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0076e7a0
//
// 0076e7a0  6804487900           push 0x794804
// 0076e7a5  ff15c0ed7700         call dword ptr [0x77edc0]
// 0076e7ab  a378668b00           mov dword ptr [0x8b6678], eax
// 0076e7b0  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??__Extp_wm_SwitchView@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
