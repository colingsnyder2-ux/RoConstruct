// from server: 100% by auto
// roc 2009-06 00740790  unit: CInstanceRecord::CNameItem  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00740790
//
// 00740790  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 00740797  68041aa500           push 0xa51a04
// 0074079c  743b                 je 0x7407d9
// 0074079e  ff15d0e18900         call dword ptr [0x89e1d0]
// 007407a4  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 007407ab  741c                 je 0x7407c9
// 007407ad  e8dea1cdff           call 0x41a990
// 007407b2  8b442404             mov eax, dword ptr [esp + 4]
// 007407b6  8b0d001aa500         mov ecx, dword ptr [0xa51a00]
// 007407bc  50                   push eax
// 007407bd  6a00                 push 0
// 007407bf  51                   push ecx
// 007407c0  ff1524e28900         call dword ptr [0x89e224]
// 007407c6  c20400               ret 4
// 007407c9  8b542404             mov edx, dword ptr [esp + 4]
// 007407cd  52                   push edx
// 007407ce  e84785fdff           call 0x718d1a
// 007407d3  83c404               add esp, 4
// 007407d6  c20400               ret 4
// 007407d9  ff15d0e18900         call dword ptr [0x89e1d0]
// 007407df  8b442404             mov eax, dword ptr [esp + 4]
// 007407e3  50                   push eax
// 007407e4  e84f82fdff           call 0x718a38
// 007407e9  83c404               add esp, 4
// 007407ec  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??2?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
