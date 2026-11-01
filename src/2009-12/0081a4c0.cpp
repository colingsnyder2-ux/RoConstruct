// from server: 100% by auto
// roc 2009-12 0081a4c0  unit: CInstanceRecord::CNameItem  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081a4c0
//
// 0081a4c0  85c9                 test ecx, ecx
// 0081a4c2  7503                 jne 0x81a4c7
// 0081a4c4  33c0                 xor eax, eax
// 0081a4c6  c3                   ret 
// 0081a4c7  8b4164               mov eax, dword ptr [ecx + 0x64]
// 0081a4ca  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?IsFocusable@CXTPReportRecordItem@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
