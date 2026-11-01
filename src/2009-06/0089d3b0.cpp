// from server: 100% by auto
// roc 2009-06 0089d3b0  unit: seg_00890000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0089d3b0
//
// 0089d3b0  833d141aa50000       cmp dword ptr [0xa51a14], 0
// 0089d3b7  c7054059a200344a8f00 mov dword ptr [0xa25940], 0x8f4a34
// 0089d3c1  751a                 jne 0x89d3dd
// 0089d3c3  a1101aa500           mov eax, dword ptr [0xa51a10]
// 0089d3c8  85c0                 test eax, eax
// 0089d3ca  7407                 je 0x89d3d3
// 0089d3cc  50                   push eax
// 0089d3cd  ff1520e28900         call dword ptr [0x89e220]
// 0089d3d3  c705101aa50000000000 mov dword ptr [0xa51a10], 0
// 0089d3dd  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??__Fg_objCXTPChartSeriesPointAllocator@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
