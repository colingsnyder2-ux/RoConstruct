// from server: 100% by auto
// roc 2009-06 0089d450  unit: seg_00890000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0089d450
//
// 0089d450  c7054c59a200fc468f00 mov dword ptr [0xa2594c], 0x8f46fc
// 0089d45a  e831a7eaff           call 0x747b90
// 0089d45f  833d141aa50000       cmp dword ptr [0xa51a14], 0
// 0089d466  751a                 jne 0x89d482
// 0089d468  a1101aa500           mov eax, dword ptr [0xa51a10]
// 0089d46d  85c0                 test eax, eax
// 0089d46f  7407                 je 0x89d478
// 0089d471  50                   push eax
// 0089d472  ff1520e28900         call dword ptr [0x89e220]
// 0089d478  c705101aa50000000000 mov dword ptr [0xa51a10], 0
// 0089d482  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??__Fgs_CXTPChartSeriesBatchPoint_BlocksManager@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
