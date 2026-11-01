// from server: 100% by auto
// roc 2009-06 00751eb0  unit: VCXTPReportRecords::?$CXTPHeapObjectT  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00751eb0
//
// 00751eb0  83793400             cmp dword ptr [ecx + 0x34], 0
// 00751eb4  7404                 je 0x751eba
// 00751eb6  8b4138               mov eax, dword ptr [ecx + 0x38]
// 00751eb9  c3                   ret 
// 00751eba  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00751ebd  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecords.cpp (function ?GetCount@CXTPReportRecords@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecords.cpp
