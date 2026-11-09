// from server: 100% by auto
// roc 2008-06 00432f60  unit: CMultiPlayerPane  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00432f60
//
// 00432f60  c7415400000000       mov dword ptr [ecx + 0x54], 0
// 00432f67  e910e12600           jmp 0x6a107c
// library xtp-13.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ??1CXTPReportRecordItemControlHookWnd@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecordItem.cpp
