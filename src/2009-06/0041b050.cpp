// from server: 100% by auto
// roc 2009-06 0041b050  unit: CInstanceRecord  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041b050
//
// 0041b050  56                   push esi
// 0041b051  8bf1                 mov esi, ecx
// 0041b053  e878ffffff           call 0x41afd0
// 0041b058  f644240801           test byte ptr [esp + 8], 1
// 0041b05d  742c                 je 0x41b08b
// 0041b05f  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 0041b066  740f                 je 0x41b077
// 0041b068  56                   push esi
// 0041b069  e802fcffff           call 0x41ac70
// 0041b06e  83c404               add esp, 4
// 0041b071  8bc6                 mov eax, esi
// 0041b073  5e                   pop esi
// 0041b074  c20400               ret 4
// 0041b077  68041aa500           push 0xa51a04
// 0041b07c  ff15a4e18900         call dword ptr [0x89e1a4]
// 0041b082  56                   push esi
// 0041b083  e8aad92f00           call 0x718a32
// 0041b088  83c404               add esp, 4
// 0041b08b  8bc6                 mov eax, esi
// 0041b08d  5e                   pop esi
// 0041b08e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
