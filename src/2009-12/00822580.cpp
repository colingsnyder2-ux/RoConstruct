// from server: 100% by auto
// roc 2009-12 00822580  unit: CXTPReportControl  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00822580
//
// 00822580  c70194509f00         mov dword ptr [ecx], 0x9f5094
// 00822586  8b4904               mov ecx, dword ptr [ecx + 4]
// 00822589  85c9                 test ecx, ecx
// 0082258b  7405                 je 0x822592
// 0082258d  e94a18fdff           jmp 0x7f3ddc
// 00822592  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??1?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
