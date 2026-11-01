// from server: 100% by auto
// roc 2009-12 00824ae0  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00824ae0
//
// 00824ae0  56                   push esi
// 00824ae1  8bf1                 mov esi, ecx
// 00824ae3  e8c8f20700           call 0x8a3db0
// 00824ae8  f644240801           test byte ptr [esp + 8], 1
// 00824aed  742c                 je 0x824b1b
// 00824aef  833d88aeb90000       cmp dword ptr [0xb9ae88], 0
// 00824af6  740f                 je 0x824b07
// 00824af8  56                   push esi
// 00824af9  e8b2dbffff           call 0x8226b0
// 00824afe  83c404               add esp, 4
// 00824b01  8bc6                 mov eax, esi
// 00824b03  5e                   pop esi
// 00824b04  c20400               ret 4
// 00824b07  6880aeb900           push 0xb9ae80
// 00824b0c  ff1508b29800         call dword ptr [0x98b208]
// 00824b12  56                   push esi
// 00824b13  e842edfcff           call 0x7f385a
// 00824b18  83c404               add esp, 4
// 00824b1b  8bc6                 mov eax, esi
// 00824b1d  5e                   pop esi
// 00824b1e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
