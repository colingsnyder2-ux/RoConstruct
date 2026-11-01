// from server: 100% by auto
// roc 2009-12 00823c40  unit: VCXTPReportRowAllocator::?$CXTPBatchAllocManagerT  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823c40
//
// 00823c40  56                   push esi
// 00823c41  8bf1                 mov esi, ecx
// 00823c43  c706a04b9f00         mov dword ptr [esi], 0x9f4ba0
// 00823c49  e8a2edffff           call 0x8229f0
// 00823c4e  833d70aeb90000       cmp dword ptr [0xb9ae70], 0
// 00823c55  751a                 jne 0x823c71
// 00823c57  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 00823c5c  85c0                 test eax, eax
// 00823c5e  7407                 je 0x823c67
// 00823c60  50                   push eax
// 00823c61  ff1504b39800         call dword ptr [0x98b304]
// 00823c67  c7056caeb90000000000 mov dword ptr [0xb9ae6c], 0
// 00823c71  f644240801           test byte ptr [esp + 8], 1
// 00823c76  7409                 je 0x823c81
// 00823c78  56                   push esi
// 00823c79  e8dcfbfcff           call 0x7f385a
// 00823c7e  83c404               add esp, 4
// 00823c81  8bc6                 mov eax, esi
// 00823c83  5e                   pop esi
// 00823c84  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
