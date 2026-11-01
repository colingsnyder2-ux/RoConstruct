// from server: 100% by auto
// roc 2009-06 00747f50  unit: UCXTPReportAllocatorDefaultData::?$CXTPHeapAllocatorT  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00747f50
//
// 00747f50  56                   push esi
// 00747f51  8bf1                 mov esi, ecx
// 00747f53  c7063c4a8f00         mov dword ptr [esi], 0x8f4a3c
// 00747f59  833d241aa50000       cmp dword ptr [0xa51a24], 0
// 00747f60  751a                 jne 0x747f7c
// 00747f62  a1201aa500           mov eax, dword ptr [0xa51a20]
// 00747f67  85c0                 test eax, eax
// 00747f69  7407                 je 0x747f72
// 00747f6b  50                   push eax
// 00747f6c  ff1520e28900         call dword ptr [0x89e220]
// 00747f72  c705201aa50000000000 mov dword ptr [0xa51a20], 0
// 00747f7c  f644240801           test byte ptr [esp + 8], 1
// 00747f81  7409                 je 0x747f8c
// 00747f83  56                   push esi
// 00747f84  e8a90afdff           call 0x718a32
// 00747f89  83c404               add esp, 4
// 00747f8c  8bc6                 mov eax, esi
// 00747f8e  5e                   pop esi
// 00747f8f  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
