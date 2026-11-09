// from server: 100% by auto
// roc 2010-06 007d8b50  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d8b50
//
// 007d8b50  56                   push esi
// 007d8b51  8bf1                 mov esi, ecx
// 007d8b53  e898f30700           call 0x857ef0
// 007d8b58  f644240801           test byte ptr [esp + 8], 1
// 007d8b5d  742c                 je 0x7d8b8b
// 007d8b5f  833db855c20000       cmp dword ptr [0xc255b8], 0
// 007d8b66  740f                 je 0x7d8b77
// 007d8b68  56                   push esi
// 007d8b69  e8a2dbffff           call 0x7d6710
// 007d8b6e  83c404               add esp, 4
// 007d8b71  8bc6                 mov eax, esi
// 007d8b73  5e                   pop esi
// 007d8b74  c20400               ret 4
// 007d8b77  68b055c200           push 0xc255b0
// 007d8b7c  ff157ca39e00         call dword ptr [0x9ea37c]
// 007d8b82  56                   push esi
// 007d8b83  e812eefcff           call 0x7a799a
// 007d8b88  83c404               add esp, 4
// 007d8b8b  8bc6                 mov eax, esi
// 007d8b8d  5e                   pop esi
// 007d8b8e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
