// from server: 100% by auto
// roc 2010-06 007d65e0  unit: CXTPReportControl  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d65e0
//
// 007d65e0  c7018493a500         mov dword ptr [ecx], 0xa59384
// 007d65e6  8b4904               mov ecx, dword ptr [ecx + 4]
// 007d65e9  85c9                 test ecx, ecx
// 007d65eb  7405                 je 0x7d65f2
// 007d65ed  e92a19fdff           jmp 0x7a7f1c
// 007d65f2  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??1?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
