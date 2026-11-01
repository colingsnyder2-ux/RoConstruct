// from server: 100% by auto
// roc 2009-12 0081e960  unit: CXTPReportControl  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081e960
//
// 0081e960  56                   push esi
// 0081e961  33f6                 xor esi, esi
// 0081e963  393570aeb900         cmp dword ptr [0xb9ae70], esi
// 0081e969  740d                 je 0x81e978
// 0081e96b  6870aeb900           push 0xb9ae70
// 0081e970  ff1508b29800         call dword ptr [0x98b208]
// 0081e976  8bf0                 mov esi, eax
// 0081e978  833d78aeb90000       cmp dword ptr [0xb9ae78], 0
// 0081e97f  7434                 je 0x81e9b5
// 0081e981  8b442408             mov eax, dword ptr [esp + 8]
// 0081e985  8b0d6caeb900         mov ecx, dword ptr [0xb9ae6c]
// 0081e98b  50                   push eax
// 0081e98c  6a00                 push 0
// 0081e98e  51                   push ecx
// 0081e98f  ff150cb39800         call dword ptr [0x98b30c]
// 0081e995  85f6                 test esi, esi
// 0081e997  751a                 jne 0x81e9b3
// 0081e999  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 0081e99e  85c0                 test eax, eax
// 0081e9a0  7407                 je 0x81e9a9
// 0081e9a2  50                   push eax
// 0081e9a3  ff1504b39800         call dword ptr [0x98b304]
// 0081e9a9  c7056caeb90000000000 mov dword ptr [0xb9ae6c], 0
// 0081e9b3  5e                   pop esi
// 0081e9b4  c3                   ret 
// 0081e9b5  5e                   pop esi
// 0081e9b6  e99f4efdff           jmp 0x7f385a
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?Free_mem@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
