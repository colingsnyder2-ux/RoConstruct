// from server: 100% by auto
// roc 2009-12 008226b0  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008226b0
//
// 008226b0  56                   push esi
// 008226b1  33f6                 xor esi, esi
// 008226b3  393580aeb900         cmp dword ptr [0xb9ae80], esi
// 008226b9  740d                 je 0x8226c8
// 008226bb  6880aeb900           push 0xb9ae80
// 008226c0  ff1508b29800         call dword ptr [0x98b208]
// 008226c6  8bf0                 mov esi, eax
// 008226c8  833d88aeb90000       cmp dword ptr [0xb9ae88], 0
// 008226cf  7434                 je 0x822705
// 008226d1  8b442408             mov eax, dword ptr [esp + 8]
// 008226d5  8b0d7caeb900         mov ecx, dword ptr [0xb9ae7c]
// 008226db  50                   push eax
// 008226dc  6a00                 push 0
// 008226de  51                   push ecx
// 008226df  ff150cb39800         call dword ptr [0x98b30c]
// 008226e5  85f6                 test esi, esi
// 008226e7  751a                 jne 0x822703
// 008226e9  a17caeb900           mov eax, dword ptr [0xb9ae7c]
// 008226ee  85c0                 test eax, eax
// 008226f0  7407                 je 0x8226f9
// 008226f2  50                   push eax
// 008226f3  ff1504b39800         call dword ptr [0x98b304]
// 008226f9  c7057caeb90000000000 mov dword ptr [0xb9ae7c], 0
// 00822703  5e                   pop esi
// 00822704  c3                   ret 
// 00822705  5e                   pop esi
// 00822706  e94f11fdff           jmp 0x7f385a
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?Free_mem@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
