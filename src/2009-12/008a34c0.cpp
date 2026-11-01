// from server: 100% by auto
// roc 2009-12 008a34c0  unit: CXTPReportHyperlinks  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a34c0
//
// 008a34c0  56                   push esi
// 008a34c1  8bf1                 mov esi, ecx
// 008a34c3  e8a8fdffff           call 0x8a3270
// 008a34c8  f644240801           test byte ptr [esp + 8], 1
// 008a34cd  742c                 je 0x8a34fb
// 008a34cf  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 008a34d6  740f                 je 0x8a34e7
// 008a34d8  56                   push esi
// 008a34d9  e8c27bb7ff           call 0x41b0a0
// 008a34de  83c404               add esp, 4
// 008a34e1  8bc6                 mov eax, esi
// 008a34e3  5e                   pop esi
// 008a34e4  c20400               ret 4
// 008a34e7  6860aeb900           push 0xb9ae60
// 008a34ec  ff1508b29800         call dword ptr [0x98b208]
// 008a34f2  56                   push esi
// 008a34f3  e86203f5ff           call 0x7f385a
// 008a34f8  83c404               add esp, 4
// 008a34fb  8bc6                 mov eax, esi
// 008a34fd  5e                   pop esi
// 008a34fe  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
