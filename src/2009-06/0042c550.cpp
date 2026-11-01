// from server: 100% by auto
// roc 2009-06 0042c550  unit: CMultiPlayerPane  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042c550
//
// 0042c550  c7415400000000       mov dword ptr [ecx + 0x54], 0
// 0042c557  e992cf2e00           jmp 0x7194ee
// library xtp-13.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ??1CXTPReportRecordItemControlHookWnd@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecordItem.cpp
