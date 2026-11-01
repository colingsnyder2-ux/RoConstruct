// from server: 100% by auto
// roc 2009-06 007505c0  unit: CXTPReportRecord  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007505c0
//
// 007505c0  56                   push esi
// 007505c1  8bf1                 mov esi, ecx
// 007505c3  e868fbffff           call 0x750130
// 007505c8  f644240801           test byte ptr [esp + 8], 1
// 007505cd  742c                 je 0x7505fb
// 007505cf  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 007505d6  740f                 je 0x7505e7
// 007505d8  56                   push esi
// 007505d9  e892a6ccff           call 0x41ac70
// 007505de  83c404               add esp, 4
// 007505e1  8bc6                 mov eax, esi
// 007505e3  5e                   pop esi
// 007505e4  c20400               ret 4
// 007505e7  68041aa500           push 0xa51a04
// 007505ec  ff15a4e18900         call dword ptr [0x89e1a4]
// 007505f2  56                   push esi
// 007505f3  e83a84fcff           call 0x718a32
// 007505f8  83c404               add esp, 4
// 007505fb  8bc6                 mov eax, esi
// 007505fd  5e                   pop esi
// 007505fe  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
