// from server: 100% by auto
// roc 2010-06 00857390  unit: CXTPReportHyperlink  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00857390
//
// 00857390  56                   push esi
// 00857391  8bf1                 mov esi, ecx
// 00857393  e8f8f9ffff           call 0x856d90
// 00857398  f644240801           test byte ptr [esp + 8], 1
// 0085739d  742c                 je 0x8573cb
// 0085739f  833d9855c20000       cmp dword ptr [0xc25598], 0
// 008573a6  740f                 je 0x8573b7
// 008573a8  56                   push esi
// 008573a9  e8823dbcff           call 0x41b130
// 008573ae  83c404               add esp, 4
// 008573b1  8bc6                 mov eax, esi
// 008573b3  5e                   pop esi
// 008573b4  c20400               ret 4
// 008573b7  689055c200           push 0xc25590
// 008573bc  ff157ca39e00         call dword ptr [0x9ea37c]
// 008573c2  56                   push esi
// 008573c3  e8d205f5ff           call 0x7a799a
// 008573c8  83c404               add esp, 4
// 008573cb  8bc6                 mov eax, esi
// 008573cd  5e                   pop esi
// 008573ce  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
