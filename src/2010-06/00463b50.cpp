// from server: 100% by auto
// roc 2010-06 00463b50  unit: CRobloxReportView::CStatsItemRecord  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00463b50
//
// 00463b50  56                   push esi
// 00463b51  8bf1                 mov esi, ecx
// 00463b53  e8d8feffff           call 0x463a30
// 00463b58  f644240801           test byte ptr [esp + 8], 1
// 00463b5d  742c                 je 0x463b8b
// 00463b5f  833d9855c20000       cmp dword ptr [0xc25598], 0
// 00463b66  740f                 je 0x463b77
// 00463b68  56                   push esi
// 00463b69  e8c275fbff           call 0x41b130
// 00463b6e  83c404               add esp, 4
// 00463b71  8bc6                 mov eax, esi
// 00463b73  5e                   pop esi
// 00463b74  c20400               ret 4
// 00463b77  689055c200           push 0xc25590
// 00463b7c  ff157ca39e00         call dword ptr [0x9ea37c]
// 00463b82  56                   push esi
// 00463b83  e8123e3400           call 0x7a799a
// 00463b88  83c404               add esp, 4
// 00463b8b  8bc6                 mov eax, esi
// 00463b8d  5e                   pop esi
// 00463b8e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
