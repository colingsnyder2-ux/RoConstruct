// from server: 100% by auto
// roc 2009-06 007477d0  unit: UCXTPReportRowAllocatorData::?$CXTPHeapAllocatorT  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007477d0
//
// 007477d0  56                   push esi
// 007477d1  8bf1                 mov esi, ecx
// 007477d3  c706344a8f00         mov dword ptr [esi], 0x8f4a34
// 007477d9  833d141aa50000       cmp dword ptr [0xa51a14], 0
// 007477e0  751a                 jne 0x7477fc
// 007477e2  a1101aa500           mov eax, dword ptr [0xa51a10]
// 007477e7  85c0                 test eax, eax
// 007477e9  7407                 je 0x7477f2
// 007477eb  50                   push eax
// 007477ec  ff1520e28900         call dword ptr [0x89e220]
// 007477f2  c705101aa50000000000 mov dword ptr [0xa51a10], 0
// 007477fc  f644240801           test byte ptr [esp + 8], 1
// 00747801  7409                 je 0x74780c
// 00747803  56                   push esi
// 00747804  e82912fdff           call 0x718a32
// 00747809  83c404               add esp, 4
// 0074780c  8bc6                 mov eax, esi
// 0074780e  5e                   pop esi
// 0074780f  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
