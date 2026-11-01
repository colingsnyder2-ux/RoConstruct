// from server: 100% by auto
// roc 2007-03 006bd670  unit: seg_006b0000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bd670
//
// 006bd670  56                   push esi
// 006bd671  8bf1                 mov esi, ecx
// 006bd673  e856d40700           call 0x73aace
// 006bd678  8b442408             mov eax, dword ptr [esp + 8]
// 006bd67c  894620               mov dword ptr [esi + 0x20], eax
// 006bd67f  c706e4527d00         mov dword ptr [esi], 0x7d52e4
// 006bd685  8bc6                 mov eax, esi
// 006bd687  5e                   pop esi
// 006bd688  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportNavigator.cpp (function ??0CXTPReportNavigator@@QAE@PAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportNavigator.cpp
