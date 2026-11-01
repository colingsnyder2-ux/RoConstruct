// from server: 100% by auto
// roc 2009-12 00823760  unit: CXTPReportControl  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823760
//
// 00823760  833d88aeb90000       cmp dword ptr [0xb9ae88], 0
// 00823767  7410                 je 0x823779
// 00823769  8b442404             mov eax, dword ptr [esp + 4]
// 0082376d  50                   push eax
// 0082376e  e83defffff           call 0x8226b0
// 00823773  83c404               add esp, 4
// 00823776  c20400               ret 4
// 00823779  6880aeb900           push 0xb9ae80
// 0082377e  ff1508b29800         call dword ptr [0x98b208]
// 00823784  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00823788  51                   push ecx
// 00823789  e8cc00fdff           call 0x7f385a
// 0082378e  59                   pop ecx
// 0082378f  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??3?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
