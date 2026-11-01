// from server: 100% by auto
// roc 2009-12 008229f0  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008229f0
//
// 008229f0  56                   push esi
// 008229f1  8b35b4aeb900         mov esi, dword ptr [0xb9aeb4]
// 008229f7  85f6                 test esi, esi
// 008229f9  0f84c4000000         je 0x822ac3
// 008229ff  90                   nop 
// 00822a00  8b4608               mov eax, dword ptr [esi + 8]
// 00822a03  85c0                 test eax, eax
// 00822a05  7408                 je 0x822a0f
// 00822a07  8bf0                 mov esi, eax
// 00822a09  85f6                 test esi, esi
// 00822a0b  75f3                 jne 0x822a00
// 00822a0d  5e                   pop esi
// 00822a0e  c3                   ret 
// 00822a0f  53                   push ebx
// 00822a10  55                   push ebp
// 00822a11  8b2d0cb39800         mov ebp, dword ptr [0x98b30c]
// 00822a17  57                   push edi
// 00822a18  eb06                 jmp 0x822a20
// 00822a1a  8d9b00000000         lea ebx, [ebx]
// 00822a20  833e00               cmp dword ptr [esi], 0
// 00822a23  0f858c000000         jne 0x822ab5
// 00822a29  8b4608               mov eax, dword ptr [esi + 8]
// 00822a2c  8bde                 mov ebx, esi
// 00822a2e  85c0                 test eax, eax
// 00822a30  7406                 je 0x822a38
// 00822a32  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00822a35  89480c               mov dword ptr [eax + 0xc], ecx
// 00822a38  8b460c               mov eax, dword ptr [esi + 0xc]
// 00822a3b  85c0                 test eax, eax
// 00822a3d  7406                 je 0x822a45
// 00822a3f  8b5608               mov edx, dword ptr [esi + 8]
// 00822a42  895008               mov dword ptr [eax + 8], edx
// 00822a45  3935b4aeb900         cmp dword ptr [0xb9aeb4], esi
// 00822a4b  750f                 jne 0x822a5c
// 00822a4d  8b4608               mov eax, dword ptr [esi + 8]
// 00822a50  85c0                 test eax, eax
// 00822a52  7503                 jne 0x822a57
// 00822a54  8b460c               mov eax, dword ptr [esi + 0xc]
// 00822a57  a3b4aeb900           mov dword ptr [0xb9aeb4], eax
// 00822a5c  8b760c               mov esi, dword ptr [esi + 0xc]
// 00822a5f  33ff                 xor edi, edi
// 00822a61  393d70aeb900         cmp dword ptr [0xb9ae70], edi
// 00822a67  740d                 je 0x822a76
// 00822a69  6870aeb900           push 0xb9ae70
// 00822a6e  ff1508b29800         call dword ptr [0x98b208]
// 00822a74  8bf8                 mov edi, eax
// 00822a76  833d78aeb90000       cmp dword ptr [0xb9ae78], 0
// 00822a7d  53                   push ebx
// 00822a7e  742b                 je 0x822aab
// 00822a80  8b0d6caeb900         mov ecx, dword ptr [0xb9ae6c]
// 00822a86  6a00                 push 0
// 00822a88  51                   push ecx
// 00822a89  ffd5                 call ebp
// 00822a8b  85ff                 test edi, edi
// 00822a8d  7529                 jne 0x822ab8
// 00822a8f  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 00822a94  85c0                 test eax, eax
// 00822a96  7407                 je 0x822a9f
// 00822a98  50                   push eax
// 00822a99  ff1504b39800         call dword ptr [0x98b304]
// 00822a9f  c7056caeb90000000000 mov dword ptr [0xb9ae6c], 0
// 00822aa9  eb0d                 jmp 0x822ab8
// 00822aab  e8aa0dfdff           call 0x7f385a
// 00822ab0  83c404               add esp, 4
// 00822ab3  eb03                 jmp 0x822ab8
// 00822ab5  8b760c               mov esi, dword ptr [esi + 0xc]
// 00822ab8  85f6                 test esi, esi
// 00822aba  0f8560ffffff         jne 0x822a20
// 00822ac0  5f                   pop edi
// 00822ac1  5d                   pop ebp
// 00822ac2  5b                   pop ebx
// 00822ac3  5e                   pop esi
// 00822ac4  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?FreeExtraData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
