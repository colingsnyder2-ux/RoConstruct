// from server: 100% by auto
// roc 2010-06 00462330  unit: CRobloxReportView::CStatsItemRecord::CNameItem  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00462330
//
// 00462330  56                   push esi
// 00462331  8bf1                 mov esi, ecx
// 00462333  e8b8f6ffff           call 0x4619f0
// 00462338  f644240801           test byte ptr [esp + 8], 1
// 0046233d  742c                 je 0x46236b
// 0046233f  833d9855c20000       cmp dword ptr [0xc25598], 0
// 00462346  740f                 je 0x462357
// 00462348  56                   push esi
// 00462349  e8e28dfbff           call 0x41b130
// 0046234e  83c404               add esp, 4
// 00462351  8bc6                 mov eax, esi
// 00462353  5e                   pop esi
// 00462354  c20400               ret 4
// 00462357  689055c200           push 0xc25590
// 0046235c  ff157ca39e00         call dword ptr [0x9ea37c]
// 00462362  56                   push esi
// 00462363  e832563400           call 0x7a799a
// 00462368  83c404               add esp, 4
// 0046236b  8bc6                 mov eax, esi
// 0046236d  5e                   pop esi
// 0046236e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
