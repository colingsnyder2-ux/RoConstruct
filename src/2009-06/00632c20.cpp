// from server: 100% by auto
// roc 2009-06 00632c20  unit: std::strstream  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00632c20
//
// 00632c20  8b442404             mov eax, dword ptr [esp + 4]
// 00632c24  8b542408             mov edx, dword ptr [esp + 8]
// 00632c28  8901                 mov dword ptr [ecx], eax
// 00632c2a  895104               mov dword ptr [ecx + 4], edx
// 00632c2d  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItemRange.cpp (function ?Set@CXTPReportRecordItemId@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItemRange.cpp
