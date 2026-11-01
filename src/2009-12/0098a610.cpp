// from server: 100% by auto
// roc 2009-12 0098a610  unit: seg_00980000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0098a610
//
// 0098a610  c7051c5cb600a04b9f00 mov dword ptr [0xb65c1c], 0x9f4ba0
// 0098a61a  e8d183e9ff           call 0x8229f0
// 0098a61f  833d70aeb90000       cmp dword ptr [0xb9ae70], 0
// 0098a626  751a                 jne 0x98a642
// 0098a628  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 0098a62d  85c0                 test eax, eax
// 0098a62f  7407                 je 0x98a638
// 0098a631  50                   push eax
// 0098a632  ff1504b39800         call dword ptr [0x98b304]
// 0098a638  c7056caeb90000000000 mov dword ptr [0xb9ae6c], 0
// 0098a642  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??__Fgs_CXTPChartSeriesBatchPoint_BlocksManager@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
