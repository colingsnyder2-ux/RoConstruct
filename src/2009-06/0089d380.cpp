// from server: 100% by auto
// roc 2009-06 0089d380  unit: seg_00890000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0089d380
//
// 0089d380  833d041aa50000       cmp dword ptr [0xa51a04], 0
// 0089d387  c7053c59a2002c4a8f00 mov dword ptr [0xa2593c], 0x8f4a2c
// 0089d391  751a                 jne 0x89d3ad
// 0089d393  a1001aa500           mov eax, dword ptr [0xa51a00]
// 0089d398  85c0                 test eax, eax
// 0089d39a  7407                 je 0x89d3a3
// 0089d39c  50                   push eax
// 0089d39d  ff1520e28900         call dword ptr [0x89e220]
// 0089d3a3  c705001aa50000000000 mov dword ptr [0xa51a00], 0
// 0089d3ad  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??__Fg_objCXTPChartSeriesPointAllocator@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
