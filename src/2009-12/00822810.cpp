// from server: 100% by auto
// roc 2009-12 00822810  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00822810
//
// 00822810  56                   push esi
// 00822811  8b359caeb900         mov esi, dword ptr [0xb9ae9c]
// 00822817  85f6                 test esi, esi
// 00822819  0f84c4000000         je 0x8228e3
// 0082281f  90                   nop 
// 00822820  8b4608               mov eax, dword ptr [esi + 8]
// 00822823  85c0                 test eax, eax
// 00822825  7408                 je 0x82282f
// 00822827  8bf0                 mov esi, eax
// 00822829  85f6                 test esi, esi
// 0082282b  75f3                 jne 0x822820
// 0082282d  5e                   pop esi
// 0082282e  c3                   ret 
// 0082282f  53                   push ebx
// 00822830  55                   push ebp
// 00822831  8b2d0cb39800         mov ebp, dword ptr [0x98b30c]
// 00822837  57                   push edi
// 00822838  eb06                 jmp 0x822840
// 0082283a  8d9b00000000         lea ebx, [ebx]
// 00822840  833e00               cmp dword ptr [esi], 0
// 00822843  0f858c000000         jne 0x8228d5
// 00822849  8b4608               mov eax, dword ptr [esi + 8]
// 0082284c  8bde                 mov ebx, esi
// 0082284e  85c0                 test eax, eax
// 00822850  7406                 je 0x822858
// 00822852  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00822855  89480c               mov dword ptr [eax + 0xc], ecx
// 00822858  8b460c               mov eax, dword ptr [esi + 0xc]
// 0082285b  85c0                 test eax, eax
// 0082285d  7406                 je 0x822865
// 0082285f  8b5608               mov edx, dword ptr [esi + 8]
// 00822862  895008               mov dword ptr [eax + 8], edx
// 00822865  39359caeb900         cmp dword ptr [0xb9ae9c], esi
// 0082286b  750f                 jne 0x82287c
// 0082286d  8b4608               mov eax, dword ptr [esi + 8]
// 00822870  85c0                 test eax, eax
// 00822872  7503                 jne 0x822877
// 00822874  8b460c               mov eax, dword ptr [esi + 0xc]
// 00822877  a39caeb900           mov dword ptr [0xb9ae9c], eax
// 0082287c  8b760c               mov esi, dword ptr [esi + 0xc]
// 0082287f  33ff                 xor edi, edi
// 00822881  393d70aeb900         cmp dword ptr [0xb9ae70], edi
// 00822887  740d                 je 0x822896
// 00822889  6870aeb900           push 0xb9ae70
// 0082288e  ff1508b29800         call dword ptr [0x98b208]
// 00822894  8bf8                 mov edi, eax
// 00822896  833d78aeb90000       cmp dword ptr [0xb9ae78], 0
// 0082289d  53                   push ebx
// 0082289e  742b                 je 0x8228cb
// 008228a0  8b0d6caeb900         mov ecx, dword ptr [0xb9ae6c]
// 008228a6  6a00                 push 0
// 008228a8  51                   push ecx
// 008228a9  ffd5                 call ebp
// 008228ab  85ff                 test edi, edi
// 008228ad  7529                 jne 0x8228d8
// 008228af  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 008228b4  85c0                 test eax, eax
// 008228b6  7407                 je 0x8228bf
// 008228b8  50                   push eax
// 008228b9  ff1504b39800         call dword ptr [0x98b304]
// 008228bf  c7056caeb90000000000 mov dword ptr [0xb9ae6c], 0
// 008228c9  eb0d                 jmp 0x8228d8
// 008228cb  e88a0ffdff           call 0x7f385a
// 008228d0  83c404               add esp, 4
// 008228d3  eb03                 jmp 0x8228d8
// 008228d5  8b760c               mov esi, dword ptr [esi + 0xc]
// 008228d8  85f6                 test esi, esi
// 008228da  0f8560ffffff         jne 0x822840
// 008228e0  5f                   pop edi
// 008228e1  5d                   pop ebp
// 008228e2  5b                   pop ebx
// 008228e3  5e                   pop esi
// 008228e4  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?FreeExtraData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
