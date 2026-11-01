// from server: 100% by auto
// roc 2009-06 00752460  unit: CXTPReportRecords  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00752460
//
// 00752460  56                   push esi
// 00752461  8bf1                 mov esi, ecx
// 00752463  e828fdffff           call 0x752190
// 00752468  f644240801           test byte ptr [esp + 8], 1
// 0075246d  742c                 je 0x75249b
// 0075246f  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 00752476  740f                 je 0x752487
// 00752478  56                   push esi
// 00752479  e8f287ccff           call 0x41ac70
// 0075247e  83c404               add esp, 4
// 00752481  8bc6                 mov eax, esi
// 00752483  5e                   pop esi
// 00752484  c20400               ret 4
// 00752487  68041aa500           push 0xa51a04
// 0075248c  ff15a4e18900         call dword ptr [0x89e1a4]
// 00752492  56                   push esi
// 00752493  e89a65fcff           call 0x718a32
// 00752498  83c404               add esp, 4
// 0075249b  8bc6                 mov eax, esi
// 0075249d  5e                   pop esi
// 0075249e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
