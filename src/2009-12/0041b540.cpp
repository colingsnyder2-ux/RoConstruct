// from server: 100% by auto
// roc 2009-12 0041b540  unit: CInstanceRecord  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041b540
//
// 0041b540  56                   push esi
// 0041b541  8bf1                 mov esi, ecx
// 0041b543  e828ffffff           call 0x41b470
// 0041b548  f644240801           test byte ptr [esp + 8], 1
// 0041b54d  742c                 je 0x41b57b
// 0041b54f  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0041b556  740f                 je 0x41b567
// 0041b558  56                   push esi
// 0041b559  e842fbffff           call 0x41b0a0
// 0041b55e  83c404               add esp, 4
// 0041b561  8bc6                 mov eax, esi
// 0041b563  5e                   pop esi
// 0041b564  c20400               ret 4
// 0041b567  6860aeb900           push 0xb9ae60
// 0041b56c  ff1508b29800         call dword ptr [0x98b208]
// 0041b572  56                   push esi
// 0041b573  e8e2823d00           call 0x7f385a
// 0041b578  83c404               add esp, 4
// 0041b57b  8bc6                 mov eax, esi
// 0041b57d  5e                   pop esi
// 0041b57e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
