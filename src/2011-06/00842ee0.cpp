// from server: 100% by auto
// roc 2011-06 00842ee0  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00842ee0
//
// 00842ee0  8b442404             mov eax, dword ptr [esp + 4]
// 00842ee4  8b542408             mov edx, dword ptr [esp + 8]
// 00842ee8  894134               mov dword ptr [ecx + 0x34], eax
// 00842eeb  895138               mov dword ptr [ecx + 0x38], edx
// 00842eee  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?SetVirtualMode@CXTPReportRows@@UAEXPAVCXTPReportRow@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
