// from server: 100% by auto
// roc 2009-12 0082d1d0  unit: CXTPReportRecords  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082d1d0
//
// 0082d1d0  56                   push esi
// 0082d1d1  8bf1                 mov esi, ecx
// 0082d1d3  e828fdffff           call 0x82cf00
// 0082d1d8  f644240801           test byte ptr [esp + 8], 1
// 0082d1dd  742c                 je 0x82d20b
// 0082d1df  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0082d1e6  740f                 je 0x82d1f7
// 0082d1e8  56                   push esi
// 0082d1e9  e8b2debeff           call 0x41b0a0
// 0082d1ee  83c404               add esp, 4
// 0082d1f1  8bc6                 mov eax, esi
// 0082d1f3  5e                   pop esi
// 0082d1f4  c20400               ret 4
// 0082d1f7  6860aeb900           push 0xb9ae60
// 0082d1fc  ff1508b29800         call dword ptr [0x98b208]
// 0082d202  56                   push esi
// 0082d203  e85266fcff           call 0x7f385a
// 0082d208  83c404               add esp, 4
// 0082d20b  8bc6                 mov eax, esi
// 0082d20d  5e                   pop esi
// 0082d20e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
