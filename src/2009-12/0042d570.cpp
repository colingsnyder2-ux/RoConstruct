// from server: 100% by auto
// roc 2009-12 0042d570  unit: CMultiPlayerPane  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042d570
//
// 0042d570  c7415400000000       mov dword ptr [ecx + 0x54], 0
// 0042d577  e9a06d3c00           jmp 0x7f431c
// library xtp-13.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ??1CXTPReportRecordItemControlHookWnd@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecordItem.cpp
