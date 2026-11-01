// from server: 100% by auto
// roc 2009-12 0045e540  unit: CRobloxReportView::CStatsItemRecord  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0045e540
//
// 0045e540  56                   push esi
// 0045e541  8bf1                 mov esi, ecx
// 0045e543  e8d8feffff           call 0x45e420
// 0045e548  f644240801           test byte ptr [esp + 8], 1
// 0045e54d  742c                 je 0x45e57b
// 0045e54f  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0045e556  740f                 je 0x45e567
// 0045e558  56                   push esi
// 0045e559  e842cbfbff           call 0x41b0a0
// 0045e55e  83c404               add esp, 4
// 0045e561  8bc6                 mov eax, esi
// 0045e563  5e                   pop esi
// 0045e564  c20400               ret 4
// 0045e567  6860aeb900           push 0xb9ae60
// 0045e56c  ff1508b29800         call dword ptr [0x98b208]
// 0045e572  56                   push esi
// 0045e573  e8e2523900           call 0x7f385a
// 0045e578  83c404               add esp, 4
// 0045e57b  8bc6                 mov eax, esi
// 0045e57d  5e                   pop esi
// 0045e57e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
