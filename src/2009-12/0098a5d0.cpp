// from server: 100% by auto
// roc 2009-12 0098a5d0  unit: seg_00980000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0098a5d0
//
// 0098a5d0  c705185cb600984b9f00 mov dword ptr [0xb65c18], 0x9f4b98
// 0098a5da  e83182e9ff           call 0x822810
// 0098a5df  833d70aeb90000       cmp dword ptr [0xb9ae70], 0
// 0098a5e6  751a                 jne 0x98a602
// 0098a5e8  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 0098a5ed  85c0                 test eax, eax
// 0098a5ef  7407                 je 0x98a5f8
// 0098a5f1  50                   push eax
// 0098a5f2  ff1504b39800         call dword ptr [0x98b304]
// 0098a5f8  c7056caeb90000000000 mov dword ptr [0xb9ae6c], 0
// 0098a602  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??__Fgs_CXTPChartSeriesBatchPoint_BlocksManager@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
