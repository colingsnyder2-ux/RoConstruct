// from server: 100% by auto
// roc 2010-06 00857630  unit: CXTPReportHyperlinks  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00857630
//
// 00857630  56                   push esi
// 00857631  8bf1                 mov esi, ecx
// 00857633  e8a8fdffff           call 0x8573e0
// 00857638  f644240801           test byte ptr [esp + 8], 1
// 0085763d  742c                 je 0x85766b
// 0085763f  833d9855c20000       cmp dword ptr [0xc25598], 0
// 00857646  740f                 je 0x857657
// 00857648  56                   push esi
// 00857649  e8e23abcff           call 0x41b130
// 0085764e  83c404               add esp, 4
// 00857651  8bc6                 mov eax, esi
// 00857653  5e                   pop esi
// 00857654  c20400               ret 4
// 00857657  689055c200           push 0xc25590
// 0085765c  ff157ca39e00         call dword ptr [0x9ea37c]
// 00857662  56                   push esi
// 00857663  e83203f5ff           call 0x7a799a
// 00857668  83c404               add esp, 4
// 0085766b  8bc6                 mov eax, esi
// 0085766d  5e                   pop esi
// 0085766e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
