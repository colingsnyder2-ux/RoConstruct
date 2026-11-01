// from server: 100% by auto
// roc 2009-06 007488f0  unit: CXTPReportControl  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007488f0
//
// 007488f0  833d2c1aa50000       cmp dword ptr [0xa51a2c], 0
// 007488f7  68241aa500           push 0xa51a24
// 007488fc  743b                 je 0x748939
// 007488fe  ff15d0e18900         call dword ptr [0x89e1d0]
// 00748904  833d2c1aa50000       cmp dword ptr [0xa51a2c], 0
// 0074890b  741c                 je 0x748929
// 0074890d  e8eeb1ffff           call 0x743b00
// 00748912  8b442404             mov eax, dword ptr [esp + 4]
// 00748916  8b0d201aa500         mov ecx, dword ptr [0xa51a20]
// 0074891c  50                   push eax
// 0074891d  6a00                 push 0
// 0074891f  51                   push ecx
// 00748920  ff1524e28900         call dword ptr [0x89e224]
// 00748926  c20400               ret 4
// 00748929  8b542404             mov edx, dword ptr [esp + 4]
// 0074892d  52                   push edx
// 0074892e  e8e703fdff           call 0x718d1a
// 00748933  83c404               add esp, 4
// 00748936  c20400               ret 4
// 00748939  ff15d0e18900         call dword ptr [0x89e1d0]
// 0074893f  8b442404             mov eax, dword ptr [esp + 4]
// 00748943  50                   push eax
// 00748944  e8ef00fdff           call 0x718a38
// 00748949  83c404               add esp, 4
// 0074894c  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??2?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
