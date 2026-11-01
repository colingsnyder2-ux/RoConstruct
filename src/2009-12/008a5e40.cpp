// from server: 100% by auto
// roc 2009-12 008a5e40  unit: CXTPReportRow  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a5e40
//
// 008a5e40  56                   push esi
// 008a5e41  8bf1                 mov esi, ecx
// 008a5e43  e868dfffff           call 0x8a3db0
// 008a5e48  f644240801           test byte ptr [esp + 8], 1
// 008a5e4d  742c                 je 0x8a5e7b
// 008a5e4f  833d78aeb90000       cmp dword ptr [0xb9ae78], 0
// 008a5e56  740f                 je 0x8a5e67
// 008a5e58  56                   push esi
// 008a5e59  e8028bf7ff           call 0x81e960
// 008a5e5e  83c404               add esp, 4
// 008a5e61  8bc6                 mov eax, esi
// 008a5e63  5e                   pop esi
// 008a5e64  c20400               ret 4
// 008a5e67  6870aeb900           push 0xb9ae70
// 008a5e6c  ff1508b29800         call dword ptr [0x98b208]
// 008a5e72  56                   push esi
// 008a5e73  e8e2d9f4ff           call 0x7f385a
// 008a5e78  83c404               add esp, 4
// 008a5e7b  8bc6                 mov eax, esi
// 008a5e7d  5e                   pop esi
// 008a5e7e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
