// from server: 100% by auto
// roc 2009-12 0098a570  unit: seg_00980000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0098a570
//
// 0098a570  833d70aeb90000       cmp dword ptr [0xb9ae70], 0
// 0098a577  c705105cb600dc4e9f00 mov dword ptr [0xb65c10], 0x9f4edc
// 0098a581  751a                 jne 0x98a59d
// 0098a583  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 0098a588  85c0                 test eax, eax
// 0098a58a  7407                 je 0x98a593
// 0098a58c  50                   push eax
// 0098a58d  ff1504b39800         call dword ptr [0x98b304]
// 0098a593  c7056caeb90000000000 mov dword ptr [0xb9ae6c], 0
// 0098a59d  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??__Fg_objCXTPChartSeriesPointAllocator@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
