// from server: 100% by auto
// roc 2007-08 006d6270  unit: CXTPReportGroupRow  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d6270
//
// 006d6270  56                   push esi
// 006d6271  8bf1                 mov esi, ecx
// 006d6273  e8c2200600           call 0x73833a
// 006d6278  8b442408             mov eax, dword ptr [esp + 8]
// 006d627c  894620               mov dword ptr [esi + 0x20], eax
// 006d627f  c706a4877d00         mov dword ptr [esi], 0x7d87a4
// 006d6285  8bc6                 mov eax, esi
// 006d6287  5e                   pop esi
// 006d6288  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportNavigator.cpp (function ??0CXTPReportNavigator@@QAE@PAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportNavigator.cpp
