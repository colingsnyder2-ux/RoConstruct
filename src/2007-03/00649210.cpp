// from server: 100% by auto
// roc 2007-03 00649210  unit: seg_00640000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00649210
//
// 00649210  83ec14               sub esp, 0x14
// 00649213  8b442418             mov eax, dword ptr [esp + 0x18]
// 00649217  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0064921b  8944240c             mov dword ptr [esp + 0xc], eax
// 0064921f  8d0424               lea eax, [esp]
// 00649222  50                   push eax
// 00649223  6ac3                 push -0x3d
// 00649225  89542418             mov dword ptr [esp + 0x18], edx
// 00649229  e882faffff           call 0x648cb0
// 0064922e  83c414               add esp, 0x14
// 00649231  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?GetItemMetrics@CXTPReportControl@@MAEXPAUXTP_REPORTRECORDITEM_DRAWARGS@@PAUXTP_REPORTRECORDITEM_METRICS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
