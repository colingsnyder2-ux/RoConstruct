// from server: 100% by auto
// roc 2010-06 007df400  unit: CXTPReportRecord  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007df400
//
// 007df400  56                   push esi
// 007df401  8bf1                 mov esi, ecx
// 007df403  e868fbffff           call 0x7def70
// 007df408  f644240801           test byte ptr [esp + 8], 1
// 007df40d  742c                 je 0x7df43b
// 007df40f  833d9855c20000       cmp dword ptr [0xc25598], 0
// 007df416  740f                 je 0x7df427
// 007df418  56                   push esi
// 007df419  e812bdc3ff           call 0x41b130
// 007df41e  83c404               add esp, 4
// 007df421  8bc6                 mov eax, esi
// 007df423  5e                   pop esi
// 007df424  c20400               ret 4
// 007df427  689055c200           push 0xc25590
// 007df42c  ff157ca39e00         call dword ptr [0x9ea37c]
// 007df432  56                   push esi
// 007df433  e86285fcff           call 0x7a799a
// 007df438  83c404               add esp, 4
// 007df43b  8bc6                 mov eax, esi
// 007df43d  5e                   pop esi
// 007df43e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
