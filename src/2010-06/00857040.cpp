// from server: 100% by auto
// roc 2010-06 00857040  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00857040
//
// 00857040  8b01                 mov eax, dword ptr [ecx]
// 00857042  8b4078               mov eax, dword ptr [eax + 0x78]
// 00857045  ffe0                 jmp eax
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPCalendarEventLabel.cpp (function ?OleAdd@?$CXTPArrayT@IIJ@@MAEXJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPCalendarEventLabel.cpp
