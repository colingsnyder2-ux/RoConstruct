// from server: 100% by auto
// roc 2009-06 00747b90  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00747b90
//
// 00747b90  56                   push esi
// 00747b91  8b35581aa500         mov esi, dword ptr [0xa51a58]
// 00747b97  85f6                 test esi, esi
// 00747b99  0f84c4000000         je 0x747c63
// 00747b9f  90                   nop 
// 00747ba0  8b4608               mov eax, dword ptr [esi + 8]
// 00747ba3  85c0                 test eax, eax
// 00747ba5  7408                 je 0x747baf
// 00747ba7  8bf0                 mov esi, eax
// 00747ba9  85f6                 test esi, esi
// 00747bab  75f3                 jne 0x747ba0
// 00747bad  5e                   pop esi
// 00747bae  c3                   ret 
// 00747baf  53                   push ebx
// 00747bb0  55                   push ebp
// 00747bb1  8b2d28e28900         mov ebp, dword ptr [0x89e228]
// 00747bb7  57                   push edi
// 00747bb8  eb06                 jmp 0x747bc0
// 00747bba  8d9b00000000         lea ebx, [ebx]
// 00747bc0  833e00               cmp dword ptr [esi], 0
// 00747bc3  0f858c000000         jne 0x747c55
// 00747bc9  8b4608               mov eax, dword ptr [esi + 8]
// 00747bcc  8bde                 mov ebx, esi
// 00747bce  85c0                 test eax, eax
// 00747bd0  7406                 je 0x747bd8
// 00747bd2  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00747bd5  89480c               mov dword ptr [eax + 0xc], ecx
// 00747bd8  8b460c               mov eax, dword ptr [esi + 0xc]
// 00747bdb  85c0                 test eax, eax
// 00747bdd  7406                 je 0x747be5
// 00747bdf  8b5608               mov edx, dword ptr [esi + 8]
// 00747be2  895008               mov dword ptr [eax + 8], edx
// 00747be5  3935581aa500         cmp dword ptr [0xa51a58], esi
// 00747beb  750f                 jne 0x747bfc
// 00747bed  8b4608               mov eax, dword ptr [esi + 8]
// 00747bf0  85c0                 test eax, eax
// 00747bf2  7503                 jne 0x747bf7
// 00747bf4  8b460c               mov eax, dword ptr [esi + 0xc]
// 00747bf7  a3581aa500           mov dword ptr [0xa51a58], eax
// 00747bfc  8b760c               mov esi, dword ptr [esi + 0xc]
// 00747bff  33ff                 xor edi, edi
// 00747c01  393d141aa500         cmp dword ptr [0xa51a14], edi
// 00747c07  740d                 je 0x747c16
// 00747c09  68141aa500           push 0xa51a14
// 00747c0e  ff15a4e18900         call dword ptr [0x89e1a4]
// 00747c14  8bf8                 mov edi, eax
// 00747c16  833d1c1aa50000       cmp dword ptr [0xa51a1c], 0
// 00747c1d  53                   push ebx
// 00747c1e  742b                 je 0x747c4b
// 00747c20  8b0d101aa500         mov ecx, dword ptr [0xa51a10]
// 00747c26  6a00                 push 0
// 00747c28  51                   push ecx
// 00747c29  ffd5                 call ebp
// 00747c2b  85ff                 test edi, edi
// 00747c2d  7529                 jne 0x747c58
// 00747c2f  a1101aa500           mov eax, dword ptr [0xa51a10]
// 00747c34  85c0                 test eax, eax
// 00747c36  7407                 je 0x747c3f
// 00747c38  50                   push eax
// 00747c39  ff1520e28900         call dword ptr [0x89e220]
// 00747c3f  c705101aa50000000000 mov dword ptr [0xa51a10], 0
// 00747c49  eb0d                 jmp 0x747c58
// 00747c4b  e8e20dfdff           call 0x718a32
// 00747c50  83c404               add esp, 4
// 00747c53  eb03                 jmp 0x747c58
// 00747c55  8b760c               mov esi, dword ptr [esi + 0xc]
// 00747c58  85f6                 test esi, esi
// 00747c5a  0f8560ffffff         jne 0x747bc0
// 00747c60  5f                   pop edi
// 00747c61  5d                   pop ebp
// 00747c62  5b                   pop ebx
// 00747c63  5e                   pop esi
// 00747c64  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?FreeExtraData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
