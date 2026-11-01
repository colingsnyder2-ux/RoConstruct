// from server: 100% by auto
// roc 2009-12 0082b390  unit: CXTPReportRecord  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082b390
//
// 0082b390  56                   push esi
// 0082b391  8bf1                 mov esi, ecx
// 0082b393  e868fbffff           call 0x82af00
// 0082b398  f644240801           test byte ptr [esp + 8], 1
// 0082b39d  742c                 je 0x82b3cb
// 0082b39f  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0082b3a6  740f                 je 0x82b3b7
// 0082b3a8  56                   push esi
// 0082b3a9  e8f2fcbeff           call 0x41b0a0
// 0082b3ae  83c404               add esp, 4
// 0082b3b1  8bc6                 mov eax, esi
// 0082b3b3  5e                   pop esi
// 0082b3b4  c20400               ret 4
// 0082b3b7  6860aeb900           push 0xb9ae60
// 0082b3bc  ff1508b29800         call dword ptr [0x98b208]
// 0082b3c2  56                   push esi
// 0082b3c3  e89284fcff           call 0x7f385a
// 0082b3c8  83c404               add esp, 4
// 0082b3cb  8bc6                 mov eax, esi
// 0082b3cd  5e                   pop esi
// 0082b3ce  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
