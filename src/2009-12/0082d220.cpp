// from server: 100% by auto
// roc 2009-12 0082d220  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082d220
//
// 0082d220  8b442404             mov eax, dword ptr [esp + 4]
// 0082d224  8b542408             mov edx, dword ptr [esp + 8]
// 0082d228  894134               mov dword ptr [ecx + 0x34], eax
// 0082d22b  895138               mov dword ptr [ecx + 0x38], edx
// 0082d22e  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?SetVirtualMode@CXTPReportRows@@UAEXPAVCXTPReportRow@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
