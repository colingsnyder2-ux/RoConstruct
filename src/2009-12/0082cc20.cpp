// from server: 100% by auto
// roc 2009-12 0082cc20  unit: VCXTPReportRecords::?$CXTPHeapObjectT  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082cc20
//
// 0082cc20  83793400             cmp dword ptr [ecx + 0x34], 0
// 0082cc24  7404                 je 0x82cc2a
// 0082cc26  8b4138               mov eax, dword ptr [ecx + 0x38]
// 0082cc29  c3                   ret 
// 0082cc2a  8b4128               mov eax, dword ptr [ecx + 0x28]
// 0082cc2d  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecords.cpp (function ?GetCount@CXTPReportRecords@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecords.cpp
