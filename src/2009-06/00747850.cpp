// from server: 100% by auto
// roc 2009-06 00747850  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00747850
//
// 00747850  56                   push esi
// 00747851  33f6                 xor esi, esi
// 00747853  3935241aa500         cmp dword ptr [0xa51a24], esi
// 00747859  740d                 je 0x747868
// 0074785b  68241aa500           push 0xa51a24
// 00747860  ff15a4e18900         call dword ptr [0x89e1a4]
// 00747866  8bf0                 mov esi, eax
// 00747868  833d2c1aa50000       cmp dword ptr [0xa51a2c], 0
// 0074786f  7434                 je 0x7478a5
// 00747871  8b442408             mov eax, dword ptr [esp + 8]
// 00747875  8b0d201aa500         mov ecx, dword ptr [0xa51a20]
// 0074787b  50                   push eax
// 0074787c  6a00                 push 0
// 0074787e  51                   push ecx
// 0074787f  ff1528e28900         call dword ptr [0x89e228]
// 00747885  85f6                 test esi, esi
// 00747887  751a                 jne 0x7478a3
// 00747889  a1201aa500           mov eax, dword ptr [0xa51a20]
// 0074788e  85c0                 test eax, eax
// 00747890  7407                 je 0x747899
// 00747892  50                   push eax
// 00747893  ff1520e28900         call dword ptr [0x89e220]
// 00747899  c705201aa50000000000 mov dword ptr [0xa51a20], 0
// 007478a3  5e                   pop esi
// 007478a4  c3                   ret 
// 007478a5  5e                   pop esi
// 007478a6  e98711fdff           jmp 0x718a32
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?Free_mem@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
