// from server: 100% by auto
// roc 2010-06 007e2f50  unit: CXTPReportRows  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e2f50
//
// 007e2f50  56                   push esi
// 007e2f51  8bf1                 mov esi, ecx
// 007e2f53  e8b8ecffff           call 0x7e1c10
// 007e2f58  f644240801           test byte ptr [esp + 8], 1
// 007e2f5d  742c                 je 0x7e2f8b
// 007e2f5f  833d9855c20000       cmp dword ptr [0xc25598], 0
// 007e2f66  740f                 je 0x7e2f77
// 007e2f68  56                   push esi
// 007e2f69  e8c281c3ff           call 0x41b130
// 007e2f6e  83c404               add esp, 4
// 007e2f71  8bc6                 mov eax, esi
// 007e2f73  5e                   pop esi
// 007e2f74  c20400               ret 4
// 007e2f77  689055c200           push 0xc25590
// 007e2f7c  ff157ca39e00         call dword ptr [0x9ea37c]
// 007e2f82  56                   push esi
// 007e2f83  e8124afcff           call 0x7a799a
// 007e2f88  83c404               add esp, 4
// 007e2f8b  8bc6                 mov eax, esi
// 007e2f8d  5e                   pop esi
// 007e2f8e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
