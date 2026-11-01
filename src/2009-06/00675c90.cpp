// from server: 100% by auto
// roc 2009-06 00675c90  unit: RBX::TimerService  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00675c90
//
// 00675c90  51                   push ecx
// 00675c91  8b493c               mov ecx, dword ptr [ecx + 0x3c]
// 00675c94  e837070600           call 0x6d63d0
// 00675c99  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRow.cpp (function ?EnsureVisible@CXTPReportRow@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRow.cpp
