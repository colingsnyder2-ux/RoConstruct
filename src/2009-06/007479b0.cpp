// from server: 100% by auto
// roc 2009-06 007479b0  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007479b0
//
// 007479b0  56                   push esi
// 007479b1  8b35401aa500         mov esi, dword ptr [0xa51a40]
// 007479b7  85f6                 test esi, esi
// 007479b9  0f84c4000000         je 0x747a83
// 007479bf  90                   nop 
// 007479c0  8b4608               mov eax, dword ptr [esi + 8]
// 007479c3  85c0                 test eax, eax
// 007479c5  7408                 je 0x7479cf
// 007479c7  8bf0                 mov esi, eax
// 007479c9  85f6                 test esi, esi
// 007479cb  75f3                 jne 0x7479c0
// 007479cd  5e                   pop esi
// 007479ce  c3                   ret 
// 007479cf  53                   push ebx
// 007479d0  55                   push ebp
// 007479d1  8b2d28e28900         mov ebp, dword ptr [0x89e228]
// 007479d7  57                   push edi
// 007479d8  eb06                 jmp 0x7479e0
// 007479da  8d9b00000000         lea ebx, [ebx]
// 007479e0  833e00               cmp dword ptr [esi], 0
// 007479e3  0f858c000000         jne 0x747a75
// 007479e9  8b4608               mov eax, dword ptr [esi + 8]
// 007479ec  8bde                 mov ebx, esi
// 007479ee  85c0                 test eax, eax
// 007479f0  7406                 je 0x7479f8
// 007479f2  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007479f5  89480c               mov dword ptr [eax + 0xc], ecx
// 007479f8  8b460c               mov eax, dword ptr [esi + 0xc]
// 007479fb  85c0                 test eax, eax
// 007479fd  7406                 je 0x747a05
// 007479ff  8b5608               mov edx, dword ptr [esi + 8]
// 00747a02  895008               mov dword ptr [eax + 8], edx
// 00747a05  3935401aa500         cmp dword ptr [0xa51a40], esi
// 00747a0b  750f                 jne 0x747a1c
// 00747a0d  8b4608               mov eax, dword ptr [esi + 8]
// 00747a10  85c0                 test eax, eax
// 00747a12  7503                 jne 0x747a17
// 00747a14  8b460c               mov eax, dword ptr [esi + 0xc]
// 00747a17  a3401aa500           mov dword ptr [0xa51a40], eax
// 00747a1c  8b760c               mov esi, dword ptr [esi + 0xc]
// 00747a1f  33ff                 xor edi, edi
// 00747a21  393d141aa500         cmp dword ptr [0xa51a14], edi
// 00747a27  740d                 je 0x747a36
// 00747a29  68141aa500           push 0xa51a14
// 00747a2e  ff15a4e18900         call dword ptr [0x89e1a4]
// 00747a34  8bf8                 mov edi, eax
// 00747a36  833d1c1aa50000       cmp dword ptr [0xa51a1c], 0
// 00747a3d  53                   push ebx
// 00747a3e  742b                 je 0x747a6b
// 00747a40  8b0d101aa500         mov ecx, dword ptr [0xa51a10]
// 00747a46  6a00                 push 0
// 00747a48  51                   push ecx
// 00747a49  ffd5                 call ebp
// 00747a4b  85ff                 test edi, edi
// 00747a4d  7529                 jne 0x747a78
// 00747a4f  a1101aa500           mov eax, dword ptr [0xa51a10]
// 00747a54  85c0                 test eax, eax
// 00747a56  7407                 je 0x747a5f
// 00747a58  50                   push eax
// 00747a59  ff1520e28900         call dword ptr [0x89e220]
// 00747a5f  c705101aa50000000000 mov dword ptr [0xa51a10], 0
// 00747a69  eb0d                 jmp 0x747a78
// 00747a6b  e8c20ffdff           call 0x718a32
// 00747a70  83c404               add esp, 4
// 00747a73  eb03                 jmp 0x747a78
// 00747a75  8b760c               mov esi, dword ptr [esi + 0xc]
// 00747a78  85f6                 test esi, esi
// 00747a7a  0f8560ffffff         jne 0x7479e0
// 00747a80  5f                   pop edi
// 00747a81  5d                   pop ebp
// 00747a82  5b                   pop ebx
// 00747a83  5e                   pop esi
// 00747a84  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?FreeExtraData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
