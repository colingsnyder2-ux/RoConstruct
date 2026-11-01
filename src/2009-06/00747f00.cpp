// from server: 100% by auto
// roc 2009-06 00747f00  unit: UCXTPReportDataAllocatorData::?$CXTPHeapAllocatorT  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00747f00
//
// 00747f00  56                   push esi
// 00747f01  8bf1                 mov esi, ecx
// 00747f03  c7062c4a8f00         mov dword ptr [esi], 0x8f4a2c
// 00747f09  833d041aa50000       cmp dword ptr [0xa51a04], 0
// 00747f10  751a                 jne 0x747f2c
// 00747f12  a1001aa500           mov eax, dword ptr [0xa51a00]
// 00747f17  85c0                 test eax, eax
// 00747f19  7407                 je 0x747f22
// 00747f1b  50                   push eax
// 00747f1c  ff1520e28900         call dword ptr [0x89e220]
// 00747f22  c705001aa50000000000 mov dword ptr [0xa51a00], 0
// 00747f2c  f644240801           test byte ptr [esp + 8], 1
// 00747f31  7409                 je 0x747f3c
// 00747f33  56                   push esi
// 00747f34  e8f90afdff           call 0x718a32
// 00747f39  83c404               add esp, 4
// 00747f3c  8bc6                 mov eax, esi
// 00747f3e  5e                   pop esi
// 00747f3f  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
