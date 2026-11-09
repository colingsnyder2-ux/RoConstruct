// from server: 100% by auto
// roc 2010-06 007d8510  unit: VCXTPReportRecords::?$CXTPHeapObjectT  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d8510
//
// 007d8510  56                   push esi
// 007d8511  8bf1                 mov esi, ecx
// 007d8513  e8688a0000           call 0x7e0f80
// 007d8518  f644240801           test byte ptr [esp + 8], 1
// 007d851d  742c                 je 0x7d854b
// 007d851f  833db855c20000       cmp dword ptr [0xc255b8], 0
// 007d8526  740f                 je 0x7d8537
// 007d8528  56                   push esi
// 007d8529  e8e2e1ffff           call 0x7d6710
// 007d852e  83c404               add esp, 4
// 007d8531  8bc6                 mov eax, esi
// 007d8533  5e                   pop esi
// 007d8534  c20400               ret 4
// 007d8537  68b055c200           push 0xc255b0
// 007d853c  ff157ca39e00         call dword ptr [0x9ea37c]
// 007d8542  56                   push esi
// 007d8543  e852f4fcff           call 0x7a799a
// 007d8548  83c404               add esp, 4
// 007d854b  8bc6                 mov eax, esi
// 007d854d  5e                   pop esi
// 007d854e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
