// from server: 100% by auto
// roc 2009-06 00753f40  unit: CXTPReportRows  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00753f40
//
// 00753f40  56                   push esi
// 00753f41  8bf1                 mov esi, ecx
// 00753f43  e818edffff           call 0x752c60
// 00753f48  f644240801           test byte ptr [esp + 8], 1
// 00753f4d  742c                 je 0x753f7b
// 00753f4f  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 00753f56  740f                 je 0x753f67
// 00753f58  56                   push esi
// 00753f59  e8126dccff           call 0x41ac70
// 00753f5e  83c404               add esp, 4
// 00753f61  8bc6                 mov eax, esi
// 00753f63  5e                   pop esi
// 00753f64  c20400               ret 4
// 00753f67  68041aa500           push 0xa51a04
// 00753f6c  ff15a4e18900         call dword ptr [0x89e1a4]
// 00753f72  56                   push esi
// 00753f73  e8ba4afcff           call 0x718a32
// 00753f78  83c404               add esp, 4
// 00753f7b  8bc6                 mov eax, esi
// 00753f7d  5e                   pop esi
// 00753f7e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
