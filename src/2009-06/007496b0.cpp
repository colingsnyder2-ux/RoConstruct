// from server: 100% by auto
// roc 2009-06 007496b0  unit: VCXTPReportRecords::?$CXTPHeapObjectT  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007496b0
//
// 007496b0  56                   push esi
// 007496b1  8bf1                 mov esi, ecx
// 007496b3  e8d88a0000           call 0x752190
// 007496b8  f644240801           test byte ptr [esp + 8], 1
// 007496bd  742c                 je 0x7496eb
// 007496bf  833d2c1aa50000       cmp dword ptr [0xa51a2c], 0
// 007496c6  740f                 je 0x7496d7
// 007496c8  56                   push esi
// 007496c9  e882e1ffff           call 0x747850
// 007496ce  83c404               add esp, 4
// 007496d1  8bc6                 mov eax, esi
// 007496d3  5e                   pop esi
// 007496d4  c20400               ret 4
// 007496d7  68241aa500           push 0xa51a24
// 007496dc  ff15a4e18900         call dword ptr [0x89e1a4]
// 007496e2  56                   push esi
// 007496e3  e84af3fcff           call 0x718a32
// 007496e8  83c404               add esp, 4
// 007496eb  8bc6                 mov eax, esi
// 007496ed  5e                   pop esi
// 007496ee  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
