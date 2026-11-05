// from server: 100% by auto
// roc 2010-06 0041b520  unit: CInstanceRecord  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041b520
//
// 0041b520  56                   push esi
// 0041b521  8bf1                 mov esi, ecx
// 0041b523  e878ffffff           call 0x41b4a0
// 0041b528  f644240801           test byte ptr [esp + 8], 1
// 0041b52d  742c                 je 0x41b55b
// 0041b52f  833d9855c20000       cmp dword ptr [0xc25598], 0
// 0041b536  740f                 je 0x41b547
// 0041b538  56                   push esi
// 0041b539  e8f2fbffff           call 0x41b130
// 0041b53e  83c404               add esp, 4
// 0041b541  8bc6                 mov eax, esi
// 0041b543  5e                   pop esi
// 0041b544  c20400               ret 4
// 0041b547  689055c200           push 0xc25590
// 0041b54c  ff157ca39e00         call dword ptr [0x9ea37c]
// 0041b552  56                   push esi
// 0041b553  e842c43800           call 0x7a799a
// 0041b558  83c404               add esp, 4
// 0041b55b  8bc6                 mov eax, esi
// 0041b55d  5e                   pop esi
// 0041b55e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
