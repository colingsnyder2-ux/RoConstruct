// from server: 100% by auto
// roc 2009-06 007407f0  unit: CInstanceRecord::CNameItem  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007407f0
//
// 007407f0  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 007407f7  7410                 je 0x740809
// 007407f9  8b442404             mov eax, dword ptr [esp + 4]
// 007407fd  50                   push eax
// 007407fe  e86da4cdff           call 0x41ac70
// 00740803  83c404               add esp, 4
// 00740806  c20400               ret 4
// 00740809  68041aa500           push 0xa51a04
// 0074080e  ff15a4e18900         call dword ptr [0x89e1a4]
// 00740814  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00740818  51                   push ecx
// 00740819  e81482fdff           call 0x718a32
// 0074081e  59                   pop ecx
// 0074081f  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??3?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
