// from server: 100% by auto
// roc 2009-12 00822d60  unit: UCXTPReportRowAllocatorData::?$CXTPHeapAllocatorT  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00822d60
//
// 00822d60  56                   push esi
// 00822d61  8bf1                 mov esi, ecx
// 00822d63  c706dc4e9f00         mov dword ptr [esi], 0x9f4edc
// 00822d69  833d70aeb90000       cmp dword ptr [0xb9ae70], 0
// 00822d70  751a                 jne 0x822d8c
// 00822d72  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 00822d77  85c0                 test eax, eax
// 00822d79  7407                 je 0x822d82
// 00822d7b  50                   push eax
// 00822d7c  ff1504b39800         call dword ptr [0x98b304]
// 00822d82  c7056caeb90000000000 mov dword ptr [0xb9ae6c], 0
// 00822d8c  f644240801           test byte ptr [esp + 8], 1
// 00822d91  7409                 je 0x822d9c
// 00822d93  56                   push esi
// 00822d94  e8c10afdff           call 0x7f385a
// 00822d99  83c404               add esp, 4
// 00822d9c  8bc6                 mov eax, esi
// 00822d9e  5e                   pop esi
// 00822d9f  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
