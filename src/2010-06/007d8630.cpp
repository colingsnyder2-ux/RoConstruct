// from server: 100% by auto
// roc 2010-06 007d8630  unit: CXTPReportControl  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d8630
//
// 007d8630  83ec14               sub esp, 0x14
// 007d8633  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d8637  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007d863b  8944240c             mov dword ptr [esp + 0xc], eax
// 007d863f  8d0424               lea eax, [esp]
// 007d8642  50                   push eax
// 007d8643  6ac3                 push -0x3d
// 007d8645  89542418             mov dword ptr [esp + 0x18], edx
// 007d8649  e882ecffff           call 0x7d72d0
// 007d864e  83c414               add esp, 0x14
// 007d8651  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?GetItemMetrics@CXTPReportControl@@MAEXPAUXTP_REPORTRECORDITEM_DRAWARGS@@PAUXTP_REPORTRECORDITEM_METRICS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
