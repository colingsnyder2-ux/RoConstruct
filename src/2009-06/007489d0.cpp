// from server: 100% by auto
// roc 2009-06 007489d0  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007489d0
//
// 007489d0  833d1c1aa50000       cmp dword ptr [0xa51a1c], 0
// 007489d7  68141aa500           push 0xa51a14
// 007489dc  743b                 je 0x748a19
// 007489de  ff15d0e18900         call dword ptr [0x89e1d0]
// 007489e4  833d1c1aa50000       cmp dword ptr [0xa51a1c], 0
// 007489eb  741c                 je 0x748a09
// 007489ed  e87eb1ffff           call 0x743b70
// 007489f2  8b442404             mov eax, dword ptr [esp + 4]
// 007489f6  8b0d101aa500         mov ecx, dword ptr [0xa51a10]
// 007489fc  50                   push eax
// 007489fd  6a00                 push 0
// 007489ff  51                   push ecx
// 00748a00  ff1524e28900         call dword ptr [0x89e224]
// 00748a06  c20400               ret 4
// 00748a09  8b542404             mov edx, dword ptr [esp + 4]
// 00748a0d  52                   push edx
// 00748a0e  e80703fdff           call 0x718d1a
// 00748a13  83c404               add esp, 4
// 00748a16  c20400               ret 4
// 00748a19  ff15d0e18900         call dword ptr [0x89e1d0]
// 00748a1f  8b442404             mov eax, dword ptr [esp + 4]
// 00748a23  50                   push eax
// 00748a24  e80f00fdff           call 0x718a38
// 00748a29  83c404               add esp, 4
// 00748a2c  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??2?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
