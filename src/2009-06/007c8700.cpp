// from server: 100% by auto
// roc 2009-06 007c8700  unit: CXTPReportHyperlinks  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c8700
//
// 007c8700  56                   push esi
// 007c8701  8bf1                 mov esi, ecx
// 007c8703  e8a8fdffff           call 0x7c84b0
// 007c8708  f644240801           test byte ptr [esp + 8], 1
// 007c870d  742c                 je 0x7c873b
// 007c870f  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 007c8716  740f                 je 0x7c8727
// 007c8718  56                   push esi
// 007c8719  e85225c5ff           call 0x41ac70
// 007c871e  83c404               add esp, 4
// 007c8721  8bc6                 mov eax, esi
// 007c8723  5e                   pop esi
// 007c8724  c20400               ret 4
// 007c8727  68041aa500           push 0xa51a04
// 007c872c  ff15a4e18900         call dword ptr [0x89e1a4]
// 007c8732  56                   push esi
// 007c8733  e8fa02f5ff           call 0x718a32
// 007c8738  83c404               add esp, 4
// 007c873b  8bc6                 mov eax, esi
// 007c873d  5e                   pop esi
// 007c873e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
