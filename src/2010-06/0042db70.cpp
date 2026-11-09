// from server: 100% by auto
// roc 2010-06 0042db70  unit: CMultiPlayerPane  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042db70
//
// 0042db70  c7415400000000       mov dword ptr [ecx + 0x54], 0
// 0042db77  e9e0a83700           jmp 0x7a845c
// library xtp-13.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ??1CXTPReportRecordItemControlHookWnd@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecordItem.cpp
