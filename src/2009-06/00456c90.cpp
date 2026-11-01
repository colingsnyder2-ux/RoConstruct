// from server: 100% by auto
// roc 2009-06 00456c90  unit: CRobloxReportView::CStatsItemRecord  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00456c90
//
// 00456c90  56                   push esi
// 00456c91  8bf1                 mov esi, ecx
// 00456c93  e8d8feffff           call 0x456b70
// 00456c98  f644240801           test byte ptr [esp + 8], 1
// 00456c9d  742c                 je 0x456ccb
// 00456c9f  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 00456ca6  740f                 je 0x456cb7
// 00456ca8  56                   push esi
// 00456ca9  e8c23ffcff           call 0x41ac70
// 00456cae  83c404               add esp, 4
// 00456cb1  8bc6                 mov eax, esi
// 00456cb3  5e                   pop esi
// 00456cb4  c20400               ret 4
// 00456cb7  68041aa500           push 0xa51a04
// 00456cbc  ff15a4e18900         call dword ptr [0x89e1a4]
// 00456cc2  56                   push esi
// 00456cc3  e86a1d2c00           call 0x718a32
// 00456cc8  83c404               add esp, 4
// 00456ccb  8bc6                 mov eax, esi
// 00456ccd  5e                   pop esi
// 00456cce  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
