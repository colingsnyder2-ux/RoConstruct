// from server: 100% by auto
// roc 2009-06 00455420  unit: CRobloxReportView::CStatsItemRecord::CNameItem  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00455420
//
// 00455420  56                   push esi
// 00455421  8bf1                 mov esi, ecx
// 00455423  e828f8ffff           call 0x454c50
// 00455428  f644240801           test byte ptr [esp + 8], 1
// 0045542d  742c                 je 0x45545b
// 0045542f  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 00455436  740f                 je 0x455447
// 00455438  56                   push esi
// 00455439  e83258fcff           call 0x41ac70
// 0045543e  83c404               add esp, 4
// 00455441  8bc6                 mov eax, esi
// 00455443  5e                   pop esi
// 00455444  c20400               ret 4
// 00455447  68041aa500           push 0xa51a04
// 0045544c  ff15a4e18900         call dword ptr [0x89e1a4]
// 00455452  56                   push esi
// 00455453  e8da352c00           call 0x718a32
// 00455458  83c404               add esp, 4
// 0045545b  8bc6                 mov eax, esi
// 0045545d  5e                   pop esi
// 0045545e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
