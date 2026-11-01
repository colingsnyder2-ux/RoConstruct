// from server: 100% by auto
// roc 2009-06 00748950  unit: CXTPReportControl  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748950
//
// 00748950  833d2c1aa50000       cmp dword ptr [0xa51a2c], 0
// 00748957  7410                 je 0x748969
// 00748959  8b442404             mov eax, dword ptr [esp + 4]
// 0074895d  50                   push eax
// 0074895e  e8edeeffff           call 0x747850
// 00748963  83c404               add esp, 4
// 00748966  c20400               ret 4
// 00748969  68241aa500           push 0xa51a24
// 0074896e  ff15a4e18900         call dword ptr [0x89e1a4]
// 00748974  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00748978  51                   push ecx
// 00748979  e8b400fdff           call 0x718a32
// 0074897e  59                   pop ecx
// 0074897f  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??3?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
