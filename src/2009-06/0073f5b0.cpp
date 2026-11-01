// from server: 100% by auto
// roc 2009-06 0073f5b0  unit: CInstanceRecord::CNameItem  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073f5b0
//
// 0073f5b0  85c9                 test ecx, ecx
// 0073f5b2  7503                 jne 0x73f5b7
// 0073f5b4  33c0                 xor eax, eax
// 0073f5b6  c3                   ret 
// 0073f5b7  8b4164               mov eax, dword ptr [ecx + 0x64]
// 0073f5ba  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?IsFocusable@CXTPReportRecordItem@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
