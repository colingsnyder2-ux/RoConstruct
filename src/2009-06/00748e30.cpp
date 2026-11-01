// from server: 100% by auto
// roc 2009-06 00748e30  unit: VCXTPReportRowAllocator::?$CXTPBatchAllocManagerT  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748e30
//
// 00748e30  56                   push esi
// 00748e31  8bf1                 mov esi, ecx
// 00748e33  c706fc468f00         mov dword ptr [esi], 0x8f46fc
// 00748e39  e852edffff           call 0x747b90
// 00748e3e  833d141aa50000       cmp dword ptr [0xa51a14], 0
// 00748e45  751a                 jne 0x748e61
// 00748e47  a1101aa500           mov eax, dword ptr [0xa51a10]
// 00748e4c  85c0                 test eax, eax
// 00748e4e  7407                 je 0x748e57
// 00748e50  50                   push eax
// 00748e51  ff1520e28900         call dword ptr [0x89e220]
// 00748e57  c705101aa50000000000 mov dword ptr [0xa51a10], 0
// 00748e61  f644240801           test byte ptr [esp + 8], 1
// 00748e66  7409                 je 0x748e71
// 00748e68  56                   push esi
// 00748e69  e8c4fbfcff           call 0x718a32
// 00748e6e  83c404               add esp, 4
// 00748e71  8bc6                 mov eax, esi
// 00748e73  5e                   pop esi
// 00748e74  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
