// from server: 100% by auto
// roc 2009-06 0089d3e0  unit: seg_00890000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0089d3e0
//
// 0089d3e0  833d241aa50000       cmp dword ptr [0xa51a24], 0
// 0089d3e7  c7054459a2003c4a8f00 mov dword ptr [0xa25944], 0x8f4a3c
// 0089d3f1  751a                 jne 0x89d40d
// 0089d3f3  a1201aa500           mov eax, dword ptr [0xa51a20]
// 0089d3f8  85c0                 test eax, eax
// 0089d3fa  7407                 je 0x89d403
// 0089d3fc  50                   push eax
// 0089d3fd  ff1520e28900         call dword ptr [0x89e220]
// 0089d403  c705201aa50000000000 mov dword ptr [0xa51a20], 0
// 0089d40d  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??__Fg_objCXTPChartSeriesPointAllocator@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
