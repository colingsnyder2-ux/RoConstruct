// from server: 100% by auto
// roc 2009-12 0041b4f0  unit: CInstanceRecord::CNameItem  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041b4f0
//
// 0041b4f0  56                   push esi
// 0041b4f1  8bf1                 mov esi, ecx
// 0041b4f3  e8f8eb3f00           call 0x81a0f0
// 0041b4f8  f644240801           test byte ptr [esp + 8], 1
// 0041b4fd  742c                 je 0x41b52b
// 0041b4ff  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0041b506  740f                 je 0x41b517
// 0041b508  56                   push esi
// 0041b509  e892fbffff           call 0x41b0a0
// 0041b50e  83c404               add esp, 4
// 0041b511  8bc6                 mov eax, esi
// 0041b513  5e                   pop esi
// 0041b514  c20400               ret 4
// 0041b517  6860aeb900           push 0xb9ae60
// 0041b51c  ff1508b29800         call dword ptr [0x98b208]
// 0041b522  56                   push esi
// 0041b523  e832833d00           call 0x7f385a
// 0041b528  83c404               add esp, 4
// 0041b52b  8bc6                 mov eax, esi
// 0041b52d  5e                   pop esi
// 0041b52e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
