// from server: 100% by auto
// roc 2007-03 0064f5c0  unit: seg_00640000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064f5c0
//
// 0064f5c0  83793400             cmp dword ptr [ecx + 0x34], 0
// 0064f5c4  7404                 je 0x64f5ca
// 0064f5c6  8b4138               mov eax, dword ptr [ecx + 0x38]
// 0064f5c9  c3                   ret 
// 0064f5ca  8b4128               mov eax, dword ptr [ecx + 0x28]
// 0064f5cd  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecords.cpp (function ?GetCount@CXTPReportRecords@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecords.cpp
