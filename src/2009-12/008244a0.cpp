// from server: 100% by auto
// roc 2009-12 008244a0  unit: VCXTPReportRecords::?$CXTPHeapObjectT  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008244a0
//
// 008244a0  56                   push esi
// 008244a1  8bf1                 mov esi, ecx
// 008244a3  e8588a0000           call 0x82cf00
// 008244a8  f644240801           test byte ptr [esp + 8], 1
// 008244ad  742c                 je 0x8244db
// 008244af  833d88aeb90000       cmp dword ptr [0xb9ae88], 0
// 008244b6  740f                 je 0x8244c7
// 008244b8  56                   push esi
// 008244b9  e8f2e1ffff           call 0x8226b0
// 008244be  83c404               add esp, 4
// 008244c1  8bc6                 mov eax, esi
// 008244c3  5e                   pop esi
// 008244c4  c20400               ret 4
// 008244c7  6880aeb900           push 0xb9ae80
// 008244cc  ff1508b29800         call dword ptr [0x98b208]
// 008244d2  56                   push esi
// 008244d3  e882f3fcff           call 0x7f385a
// 008244d8  83c404               add esp, 4
// 008244db  8bc6                 mov eax, esi
// 008244dd  5e                   pop esi
// 008244de  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
