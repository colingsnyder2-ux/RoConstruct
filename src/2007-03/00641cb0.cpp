// from server: 100% by auto
// roc 2007-03 00641cb0  unit: seg_00640000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00641cb0
//
// 00641cb0  85c9                 test ecx, ecx
// 00641cb2  7503                 jne 0x641cb7
// 00641cb4  33c0                 xor eax, eax
// 00641cb6  c3                   ret 
// 00641cb7  8b4164               mov eax, dword ptr [ecx + 0x64]
// 00641cba  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?IsFocusable@CXTPReportRecordItem@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
