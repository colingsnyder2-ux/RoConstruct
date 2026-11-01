// from server: 100% by auto
// roc 2009-06 00748de0  unit: VCXTPReportRowAllocator::?$CXTPBatchAllocManagerT  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748de0
//
// 00748de0  56                   push esi
// 00748de1  8bf1                 mov esi, ecx
// 00748de3  c706f4468f00         mov dword ptr [esi], 0x8f46f4
// 00748de9  e8c2ebffff           call 0x7479b0
// 00748dee  833d141aa50000       cmp dword ptr [0xa51a14], 0
// 00748df5  751a                 jne 0x748e11
// 00748df7  a1101aa500           mov eax, dword ptr [0xa51a10]
// 00748dfc  85c0                 test eax, eax
// 00748dfe  7407                 je 0x748e07
// 00748e00  50                   push eax
// 00748e01  ff1520e28900         call dword ptr [0x89e220]
// 00748e07  c705101aa50000000000 mov dword ptr [0xa51a10], 0
// 00748e11  f644240801           test byte ptr [esp + 8], 1
// 00748e16  7409                 je 0x748e21
// 00748e18  56                   push esi
// 00748e19  e814fcfcff           call 0x718a32
// 00748e1e  83c404               add esp, 4
// 00748e21  8bc6                 mov eax, esi
// 00748e23  5e                   pop esi
// 00748e24  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
