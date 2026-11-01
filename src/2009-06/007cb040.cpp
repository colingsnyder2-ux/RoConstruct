// from server: 100% by auto
// roc 2009-06 007cb040  unit: CXTPReportRow  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cb040
//
// 007cb040  56                   push esi
// 007cb041  8bf1                 mov esi, ecx
// 007cb043  e868dfffff           call 0x7c8fb0
// 007cb048  f644240801           test byte ptr [esp + 8], 1
// 007cb04d  742c                 je 0x7cb07b
// 007cb04f  833d1c1aa50000       cmp dword ptr [0xa51a1c], 0
// 007cb056  740f                 je 0x7cb067
// 007cb058  56                   push esi
// 007cb059  e8428af7ff           call 0x743aa0
// 007cb05e  83c404               add esp, 4
// 007cb061  8bc6                 mov eax, esi
// 007cb063  5e                   pop esi
// 007cb064  c20400               ret 4
// 007cb067  68141aa500           push 0xa51a14
// 007cb06c  ff15a4e18900         call dword ptr [0x89e1a4]
// 007cb072  56                   push esi
// 007cb073  e8bad9f4ff           call 0x718a32
// 007cb078  83c404               add esp, 4
// 007cb07b  8bc6                 mov eax, esi
// 007cb07d  5e                   pop esi
// 007cb07e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
