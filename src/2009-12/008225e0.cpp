// from server: 100% by auto
// roc 2009-12 008225e0  unit: UCXTPReportDataAllocatorData::?$CXTPHeapAllocatorT  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008225e0
//
// 008225e0  56                   push esi
// 008225e1  8bf1                 mov esi, ecx
// 008225e3  c706d44e9f00         mov dword ptr [esi], 0x9f4ed4
// 008225e9  833d60aeb90000       cmp dword ptr [0xb9ae60], 0
// 008225f0  751a                 jne 0x82260c
// 008225f2  a15caeb900           mov eax, dword ptr [0xb9ae5c]
// 008225f7  85c0                 test eax, eax
// 008225f9  7407                 je 0x822602
// 008225fb  50                   push eax
// 008225fc  ff1504b39800         call dword ptr [0x98b304]
// 00822602  c7055caeb90000000000 mov dword ptr [0xb9ae5c], 0
// 0082260c  f644240801           test byte ptr [esp + 8], 1
// 00822611  7409                 je 0x82261c
// 00822613  56                   push esi
// 00822614  e84112fdff           call 0x7f385a
// 00822619  83c404               add esp, 4
// 0082261c  8bc6                 mov eax, esi
// 0082261e  5e                   pop esi
// 0082261f  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
