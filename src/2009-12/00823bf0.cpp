// from server: 100% by auto
// roc 2009-12 00823bf0  unit: VCXTPReportRowAllocator::?$CXTPBatchAllocManagerT  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823bf0
//
// 00823bf0  56                   push esi
// 00823bf1  8bf1                 mov esi, ecx
// 00823bf3  c706984b9f00         mov dword ptr [esi], 0x9f4b98
// 00823bf9  e812ecffff           call 0x822810
// 00823bfe  833d70aeb90000       cmp dword ptr [0xb9ae70], 0
// 00823c05  751a                 jne 0x823c21
// 00823c07  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 00823c0c  85c0                 test eax, eax
// 00823c0e  7407                 je 0x823c17
// 00823c10  50                   push eax
// 00823c11  ff1504b39800         call dword ptr [0x98b304]
// 00823c17  c7056caeb90000000000 mov dword ptr [0xb9ae6c], 0
// 00823c21  f644240801           test byte ptr [esp + 8], 1
// 00823c26  7409                 je 0x823c31
// 00823c28  56                   push esi
// 00823c29  e82cfcfcff           call 0x7f385a
// 00823c2e  83c404               add esp, 4
// 00823c31  8bc6                 mov eax, esi
// 00823c33  5e                   pop esi
// 00823c34  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
