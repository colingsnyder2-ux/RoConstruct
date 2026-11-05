// from server: 100% by auto
// roc 2010-06 007e1780  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e1780
//
// 007e1780  83793400             cmp dword ptr [ecx + 0x34], 0
// 007e1784  7404                 je 0x7e178a
// 007e1786  8b4138               mov eax, dword ptr [ecx + 0x38]
// 007e1789  c3                   ret 
// 007e178a  8b4128               mov eax, dword ptr [ecx + 0x28]
// 007e178d  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportRecords.cpp (function ?GetCount@CXTPReportRecords@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecords.cpp
