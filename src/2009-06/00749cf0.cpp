// from server: 100% by auto
// roc 2009-06 00749cf0  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00749cf0
//
// 00749cf0  56                   push esi
// 00749cf1  8bf1                 mov esi, ecx
// 00749cf3  e8b8f20700           call 0x7c8fb0
// 00749cf8  f644240801           test byte ptr [esp + 8], 1
// 00749cfd  742c                 je 0x749d2b
// 00749cff  833d2c1aa50000       cmp dword ptr [0xa51a2c], 0
// 00749d06  740f                 je 0x749d17
// 00749d08  56                   push esi
// 00749d09  e842dbffff           call 0x747850
// 00749d0e  83c404               add esp, 4
// 00749d11  8bc6                 mov eax, esi
// 00749d13  5e                   pop esi
// 00749d14  c20400               ret 4
// 00749d17  68241aa500           push 0xa51a24
// 00749d1c  ff15a4e18900         call dword ptr [0x89e1a4]
// 00749d22  56                   push esi
// 00749d23  e80aedfcff           call 0x718a32
// 00749d28  83c404               add esp, 4
// 00749d2b  8bc6                 mov eax, esi
// 00749d2d  5e                   pop esi
// 00749d2e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
