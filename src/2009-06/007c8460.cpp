// from server: 100% by auto
// roc 2009-06 007c8460  unit: CXTPReportHyperlink  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c8460
//
// 007c8460  56                   push esi
// 007c8461  8bf1                 mov esi, ecx
// 007c8463  e898f9ffff           call 0x7c7e00
// 007c8468  f644240801           test byte ptr [esp + 8], 1
// 007c846d  742c                 je 0x7c849b
// 007c846f  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 007c8476  740f                 je 0x7c8487
// 007c8478  56                   push esi
// 007c8479  e8f227c5ff           call 0x41ac70
// 007c847e  83c404               add esp, 4
// 007c8481  8bc6                 mov eax, esi
// 007c8483  5e                   pop esi
// 007c8484  c20400               ret 4
// 007c8487  68041aa500           push 0xa51a04
// 007c848c  ff15a4e18900         call dword ptr [0x89e1a4]
// 007c8492  56                   push esi
// 007c8493  e89a05f5ff           call 0x718a32
// 007c8498  83c404               add esp, 4
// 007c849b  8bc6                 mov eax, esi
// 007c849d  5e                   pop esi
// 007c849e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
