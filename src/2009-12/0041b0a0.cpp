// from server: 100% by auto
// roc 2009-12 0041b0a0  unit: rbx::signals::connection::slot  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041b0a0
//
// 0041b0a0  56                   push esi
// 0041b0a1  33f6                 xor esi, esi
// 0041b0a3  393560aeb900         cmp dword ptr [0xb9ae60], esi
// 0041b0a9  740d                 je 0x41b0b8
// 0041b0ab  6860aeb900           push 0xb9ae60
// 0041b0b0  ff1508b29800         call dword ptr [0x98b208]
// 0041b0b6  8bf0                 mov esi, eax
// 0041b0b8  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0041b0bf  7434                 je 0x41b0f5
// 0041b0c1  8b442408             mov eax, dword ptr [esp + 8]
// 0041b0c5  8b0d5caeb900         mov ecx, dword ptr [0xb9ae5c]
// 0041b0cb  50                   push eax
// 0041b0cc  6a00                 push 0
// 0041b0ce  51                   push ecx
// 0041b0cf  ff150cb39800         call dword ptr [0x98b30c]
// 0041b0d5  85f6                 test esi, esi
// 0041b0d7  751a                 jne 0x41b0f3
// 0041b0d9  a15caeb900           mov eax, dword ptr [0xb9ae5c]
// 0041b0de  85c0                 test eax, eax
// 0041b0e0  7407                 je 0x41b0e9
// 0041b0e2  50                   push eax
// 0041b0e3  ff1504b39800         call dword ptr [0x98b304]
// 0041b0e9  c7055caeb90000000000 mov dword ptr [0xb9ae5c], 0
// 0041b0f3  5e                   pop esi
// 0041b0f4  c3                   ret 
// 0041b0f5  5e                   pop esi
// 0041b0f6  e95f873d00           jmp 0x7f385a
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?Free_mem@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
