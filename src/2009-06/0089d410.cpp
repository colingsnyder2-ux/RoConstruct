// from server: 100% by auto
// roc 2009-06 0089d410  unit: seg_00890000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0089d410
//
// 0089d410  c7054859a200f4468f00 mov dword ptr [0xa25948], 0x8f46f4
// 0089d41a  e891a5eaff           call 0x7479b0
// 0089d41f  833d141aa50000       cmp dword ptr [0xa51a14], 0
// 0089d426  751a                 jne 0x89d442
// 0089d428  a1101aa500           mov eax, dword ptr [0xa51a10]
// 0089d42d  85c0                 test eax, eax
// 0089d42f  7407                 je 0x89d438
// 0089d431  50                   push eax
// 0089d432  ff1520e28900         call dword ptr [0x89e220]
// 0089d438  c705101aa50000000000 mov dword ptr [0xa51a10], 0
// 0089d442  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??__Fgs_CXTPChartSeriesBatchPoint_BlocksManager@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
