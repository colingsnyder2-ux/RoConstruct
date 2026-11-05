// from server: 100% by tester
// roc 2011-06 006a1aa0  unit: RBX::LuaWebService::UCachedLuaWebServiceInfo::?$AsyncHttpCache  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006a1aa0
//
// 006a1aa0  51                   push ecx
// 006a1aa1  8b4940               mov ecx, dword ptr [ecx + 0x40]
// 006a1aa4  e827f90f00           call 0x7a13d0
// 006a1aa9  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportRow.cpp (function ?EnsureVisible@CXTPReportRow@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRow.cpp
