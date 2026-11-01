// from server: 100% by auto
// roc 2009-12 00701070  unit: RBX::TimerService  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00701070
//
// 00701070  51                   push ecx
// 00701071  8b493c               mov ecx, dword ptr [ecx + 0x3c]
// 00701074  e817260b00           call 0x7b3690
// 00701079  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRow.cpp (function ?EnsureVisible@CXTPReportRow@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRow.cpp
