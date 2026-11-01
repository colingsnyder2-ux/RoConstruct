// from server: 100% by auto
// roc 2009-12 0082eda0  unit: CXTPReportRows  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082eda0
//
// 0082eda0  56                   push esi
// 0082eda1  8bf1                 mov esi, ecx
// 0082eda3  e8b8ecffff           call 0x82da60
// 0082eda8  f644240801           test byte ptr [esp + 8], 1
// 0082edad  742c                 je 0x82eddb
// 0082edaf  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0082edb6  740f                 je 0x82edc7
// 0082edb8  56                   push esi
// 0082edb9  e8e2c2beff           call 0x41b0a0
// 0082edbe  83c404               add esp, 4
// 0082edc1  8bc6                 mov eax, esi
// 0082edc3  5e                   pop esi
// 0082edc4  c20400               ret 4
// 0082edc7  6860aeb900           push 0xb9ae60
// 0082edcc  ff1508b29800         call dword ptr [0x98b208]
// 0082edd2  56                   push esi
// 0082edd3  e8824afcff           call 0x7f385a
// 0082edd8  83c404               add esp, 4
// 0082eddb  8bc6                 mov eax, esi
// 0082eddd  5e                   pop esi
// 0082edde  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
