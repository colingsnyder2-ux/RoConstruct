// from server: 100% by auto
// roc 2009-12 0045cd50  unit: CRobloxReportView::CStatsItemRecord::CNameItem  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0045cd50
//
// 0045cd50  56                   push esi
// 0045cd51  8bf1                 mov esi, ecx
// 0045cd53  e8b8f6ffff           call 0x45c410
// 0045cd58  f644240801           test byte ptr [esp + 8], 1
// 0045cd5d  742c                 je 0x45cd8b
// 0045cd5f  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0045cd66  740f                 je 0x45cd77
// 0045cd68  56                   push esi
// 0045cd69  e832e3fbff           call 0x41b0a0
// 0045cd6e  83c404               add esp, 4
// 0045cd71  8bc6                 mov eax, esi
// 0045cd73  5e                   pop esi
// 0045cd74  c20400               ret 4
// 0045cd77  6860aeb900           push 0xb9ae60
// 0045cd7c  ff1508b29800         call dword ptr [0x98b208]
// 0045cd82  56                   push esi
// 0045cd83  e8d26a3900           call 0x7f385a
// 0045cd88  83c404               add esp, 4
// 0045cd8b  8bc6                 mov eax, esi
// 0045cd8d  5e                   pop esi
// 0045cd8e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
