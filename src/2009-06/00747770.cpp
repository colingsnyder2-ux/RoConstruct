// from server: 100% by auto
// roc 2009-06 00747770  unit: CXTPReportControl  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00747770
//
// 00747770  c701ec4b8f00         mov dword ptr [ecx], 0x8f4bec
// 00747776  8b4904               mov ecx, dword ptr [ecx + 4]
// 00747779  85c9                 test ecx, ecx
// 0074777b  7405                 je 0x747782
// 0074777d  e92618fdff           jmp 0x718fa8
// 00747782  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??1?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
