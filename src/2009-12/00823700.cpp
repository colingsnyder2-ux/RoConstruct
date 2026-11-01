// from server: 100% by auto
// roc 2009-12 00823700  unit: CXTPReportControl  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823700
//
// 00823700  833d88aeb90000       cmp dword ptr [0xb9ae88], 0
// 00823707  6880aeb900           push 0xb9ae80
// 0082370c  743b                 je 0x823749
// 0082370e  ff150cb29800         call dword ptr [0x98b20c]
// 00823714  833d88aeb90000       cmp dword ptr [0xb9ae88], 0
// 0082371b  741c                 je 0x823739
// 0082371d  e89eb2ffff           call 0x81e9c0
// 00823722  8b442404             mov eax, dword ptr [esp + 4]
// 00823726  8b0d7caeb900         mov ecx, dword ptr [0xb9ae7c]
// 0082372c  50                   push eax
// 0082372d  6a00                 push 0
// 0082372f  51                   push ecx
// 00823730  ff1508b39800         call dword ptr [0x98b308]
// 00823736  c20400               ret 4
// 00823739  8b542404             mov edx, dword ptr [esp + 4]
// 0082373d  52                   push edx
// 0082373e  e8ff03fdff           call 0x7f3b42
// 00823743  83c404               add esp, 4
// 00823746  c20400               ret 4
// 00823749  ff150cb29800         call dword ptr [0x98b20c]
// 0082374f  8b442404             mov eax, dword ptr [esp + 4]
// 00823753  50                   push eax
// 00823754  e80701fdff           call 0x7f3860
// 00823759  83c404               add esp, 4
// 0082375c  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??2?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
