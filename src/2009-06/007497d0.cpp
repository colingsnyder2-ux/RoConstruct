// from server: 100% by auto
// roc 2009-06 007497d0  unit: CXTPReportControl  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007497d0
//
// 007497d0  83ec14               sub esp, 0x14
// 007497d3  8b442418             mov eax, dword ptr [esp + 0x18]
// 007497d7  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007497db  8944240c             mov dword ptr [esp + 0xc], eax
// 007497df  8d0424               lea eax, [esp]
// 007497e2  50                   push eax
// 007497e3  6ac3                 push -0x3d
// 007497e5  89542418             mov dword ptr [esp + 0x18], edx
// 007497e9  e872ecffff           call 0x748460
// 007497ee  83c414               add esp, 0x14
// 007497f1  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?GetItemMetrics@CXTPReportControl@@MAEXPAUXTP_REPORTRECORDITEM_DRAWARGS@@PAUXTP_REPORTRECORDITEM_METRICS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
