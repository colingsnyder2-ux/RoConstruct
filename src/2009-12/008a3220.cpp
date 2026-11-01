// from server: 100% by auto
// roc 2009-12 008a3220  unit: CXTPReportHyperlink  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a3220
//
// 008a3220  56                   push esi
// 008a3221  8bf1                 mov esi, ecx
// 008a3223  e8e8f9ffff           call 0x8a2c10
// 008a3228  f644240801           test byte ptr [esp + 8], 1
// 008a322d  742c                 je 0x8a325b
// 008a322f  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 008a3236  740f                 je 0x8a3247
// 008a3238  56                   push esi
// 008a3239  e8627eb7ff           call 0x41b0a0
// 008a323e  83c404               add esp, 4
// 008a3241  8bc6                 mov eax, esi
// 008a3243  5e                   pop esi
// 008a3244  c20400               ret 4
// 008a3247  6860aeb900           push 0xb9ae60
// 008a324c  ff1508b29800         call dword ptr [0x98b208]
// 008a3252  56                   push esi
// 008a3253  e80206f5ff           call 0x7f385a
// 008a3258  83c404               add esp, 4
// 008a325b  8bc6                 mov eax, esi
// 008a325d  5e                   pop esi
// 008a325e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
