// from server: 100% by auto
// roc 2010-06 007d84c0  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d84c0
//
// 007d84c0  56                   push esi
// 007d84c1  8bf1                 mov esi, ecx
// 007d84c3  e848970000           call 0x7e1c10
// 007d84c8  f644240801           test byte ptr [esp + 8], 1
// 007d84cd  742c                 je 0x7d84fb
// 007d84cf  833db855c20000       cmp dword ptr [0xc255b8], 0
// 007d84d6  740f                 je 0x7d84e7
// 007d84d8  56                   push esi
// 007d84d9  e832e2ffff           call 0x7d6710
// 007d84de  83c404               add esp, 4
// 007d84e1  8bc6                 mov eax, esi
// 007d84e3  5e                   pop esi
// 007d84e4  c20400               ret 4
// 007d84e7  68b055c200           push 0xc255b0
// 007d84ec  ff157ca39e00         call dword ptr [0x9ea37c]
// 007d84f2  56                   push esi
// 007d84f3  e8a2f4fcff           call 0x7a799a
// 007d84f8  83c404               add esp, 4
// 007d84fb  8bc6                 mov eax, esi
// 007d84fd  5e                   pop esi
// 007d84fe  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
