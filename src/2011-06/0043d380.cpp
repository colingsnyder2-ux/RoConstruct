// from server: 100% by auto
// roc 2011-06 0043d380  unit: CMultiPlayerPane  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0043d380
//
// 0043d380  c7415400000000       mov dword ptr [ecx + 0x54], 0
// 0043d387  e994d73c00           jmp 0x80ab20
// library xtp-13.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ??1CXTPReportRecordItemControlHookWnd@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecordItem.cpp
