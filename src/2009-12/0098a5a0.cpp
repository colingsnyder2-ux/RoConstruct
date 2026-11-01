// from server: 100% by auto
// roc 2009-12 0098a5a0  unit: seg_00980000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0098a5a0
//
// 0098a5a0  833d80aeb90000       cmp dword ptr [0xb9ae80], 0
// 0098a5a7  c705145cb600e44e9f00 mov dword ptr [0xb65c14], 0x9f4ee4
// 0098a5b1  751a                 jne 0x98a5cd
// 0098a5b3  a17caeb900           mov eax, dword ptr [0xb9ae7c]
// 0098a5b8  85c0                 test eax, eax
// 0098a5ba  7407                 je 0x98a5c3
// 0098a5bc  50                   push eax
// 0098a5bd  ff1504b39800         call dword ptr [0x98b304]
// 0098a5c3  c7057caeb90000000000 mov dword ptr [0xb9ae7c], 0
// 0098a5cd  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??__Fg_objCXTPChartSeriesPointAllocator@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
