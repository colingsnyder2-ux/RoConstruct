// from server: 100% by auto
// roc 2009-06 00743aa0  unit: CXTPReportControl  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00743aa0
//
// 00743aa0  56                   push esi
// 00743aa1  33f6                 xor esi, esi
// 00743aa3  3935141aa500         cmp dword ptr [0xa51a14], esi
// 00743aa9  740d                 je 0x743ab8
// 00743aab  68141aa500           push 0xa51a14
// 00743ab0  ff15a4e18900         call dword ptr [0x89e1a4]
// 00743ab6  8bf0                 mov esi, eax
// 00743ab8  833d1c1aa50000       cmp dword ptr [0xa51a1c], 0
// 00743abf  7434                 je 0x743af5
// 00743ac1  8b442408             mov eax, dword ptr [esp + 8]
// 00743ac5  8b0d101aa500         mov ecx, dword ptr [0xa51a10]
// 00743acb  50                   push eax
// 00743acc  6a00                 push 0
// 00743ace  51                   push ecx
// 00743acf  ff1528e28900         call dword ptr [0x89e228]
// 00743ad5  85f6                 test esi, esi
// 00743ad7  751a                 jne 0x743af3
// 00743ad9  a1101aa500           mov eax, dword ptr [0xa51a10]
// 00743ade  85c0                 test eax, eax
// 00743ae0  7407                 je 0x743ae9
// 00743ae2  50                   push eax
// 00743ae3  ff1520e28900         call dword ptr [0x89e220]
// 00743ae9  c705101aa50000000000 mov dword ptr [0xa51a10], 0
// 00743af3  5e                   pop esi
// 00743af4  c3                   ret 
// 00743af5  5e                   pop esi
// 00743af6  e9374ffdff           jmp 0x718a32
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?Free_mem@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
