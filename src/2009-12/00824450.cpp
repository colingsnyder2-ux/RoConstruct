// from server: 100% by auto
// roc 2009-12 00824450  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00824450
//
// 00824450  56                   push esi
// 00824451  8bf1                 mov esi, ecx
// 00824453  e808960000           call 0x82da60
// 00824458  f644240801           test byte ptr [esp + 8], 1
// 0082445d  742c                 je 0x82448b
// 0082445f  833d88aeb90000       cmp dword ptr [0xb9ae88], 0
// 00824466  740f                 je 0x824477
// 00824468  56                   push esi
// 00824469  e842e2ffff           call 0x8226b0
// 0082446e  83c404               add esp, 4
// 00824471  8bc6                 mov eax, esi
// 00824473  5e                   pop esi
// 00824474  c20400               ret 4
// 00824477  6880aeb900           push 0xb9ae80
// 0082447c  ff1508b29800         call dword ptr [0x98b208]
// 00824482  56                   push esi
// 00824483  e8d2f3fcff           call 0x7f385a
// 00824488  83c404               add esp, 4
// 0082448b  8bc6                 mov eax, esi
// 0082448d  5e                   pop esi
// 0082448e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
