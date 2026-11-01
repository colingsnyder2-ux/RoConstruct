// from server: 100% by auto
// roc 2007-03 0064fb10  unit: seg_00640000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064fb10
//
// 0064fb10  8b442404             mov eax, dword ptr [esp + 4]
// 0064fb14  8b542408             mov edx, dword ptr [esp + 8]
// 0064fb18  894134               mov dword ptr [ecx + 0x34], eax
// 0064fb1b  895138               mov dword ptr [ecx + 0x38], edx
// 0064fb1e  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?SetVirtualMode@CXTPReportRows@@UAEXPAVCXTPReportRow@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
