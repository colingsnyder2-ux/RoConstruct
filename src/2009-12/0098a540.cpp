// from server: 100% by auto
// roc 2009-12 0098a540  unit: seg_00980000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0098a540
//
// 0098a540  833d60aeb90000       cmp dword ptr [0xb9ae60], 0
// 0098a547  c7050c5cb600d44e9f00 mov dword ptr [0xb65c0c], 0x9f4ed4
// 0098a551  751a                 jne 0x98a56d
// 0098a553  a15caeb900           mov eax, dword ptr [0xb9ae5c]
// 0098a558  85c0                 test eax, eax
// 0098a55a  7407                 je 0x98a563
// 0098a55c  50                   push eax
// 0098a55d  ff1504b39800         call dword ptr [0x98b304]
// 0098a563  c7055caeb90000000000 mov dword ptr [0xb9ae5c], 0
// 0098a56d  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??__Fg_objCXTPChartSeriesPointAllocator@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
