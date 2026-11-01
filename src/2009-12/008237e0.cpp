// from server: 100% by auto
// roc 2009-12 008237e0  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008237e0
//
// 008237e0  833d78aeb90000       cmp dword ptr [0xb9ae78], 0
// 008237e7  6870aeb900           push 0xb9ae70
// 008237ec  743b                 je 0x823829
// 008237ee  ff150cb29800         call dword ptr [0x98b20c]
// 008237f4  833d78aeb90000       cmp dword ptr [0xb9ae78], 0
// 008237fb  741c                 je 0x823819
// 008237fd  e82eb2ffff           call 0x81ea30
// 00823802  8b442404             mov eax, dword ptr [esp + 4]
// 00823806  8b0d6caeb900         mov ecx, dword ptr [0xb9ae6c]
// 0082380c  50                   push eax
// 0082380d  6a00                 push 0
// 0082380f  51                   push ecx
// 00823810  ff1508b39800         call dword ptr [0x98b308]
// 00823816  c20400               ret 4
// 00823819  8b542404             mov edx, dword ptr [esp + 4]
// 0082381d  52                   push edx
// 0082381e  e81f03fdff           call 0x7f3b42
// 00823823  83c404               add esp, 4
// 00823826  c20400               ret 4
// 00823829  ff150cb29800         call dword ptr [0x98b20c]
// 0082382f  8b442404             mov eax, dword ptr [esp + 4]
// 00823833  50                   push eax
// 00823834  e82700fdff           call 0x7f3860
// 00823839  83c404               add esp, 4
// 0082383c  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??2?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
