// from server: 100% by auto
// roc 2009-06 00749660  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00749660
//
// 00749660  56                   push esi
// 00749661  8bf1                 mov esi, ecx
// 00749663  e8f8950000           call 0x752c60
// 00749668  f644240801           test byte ptr [esp + 8], 1
// 0074966d  742c                 je 0x74969b
// 0074966f  833d2c1aa50000       cmp dword ptr [0xa51a2c], 0
// 00749676  740f                 je 0x749687
// 00749678  56                   push esi
// 00749679  e8d2e1ffff           call 0x747850
// 0074967e  83c404               add esp, 4
// 00749681  8bc6                 mov eax, esi
// 00749683  5e                   pop esi
// 00749684  c20400               ret 4
// 00749687  68241aa500           push 0xa51a24
// 0074968c  ff15a4e18900         call dword ptr [0x89e1a4]
// 00749692  56                   push esi
// 00749693  e89af3fcff           call 0x718a32
// 00749698  83c404               add esp, 4
// 0074969b  8bc6                 mov eax, esi
// 0074969d  5e                   pop esi
// 0074969e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
