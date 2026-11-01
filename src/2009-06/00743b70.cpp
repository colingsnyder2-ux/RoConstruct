// from server: 100% by auto
// roc 2009-06 00743b70  unit: CXTPReportControl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00743b70
//
// 00743b70  51                   push ecx
// 00743b71  833d101aa50000       cmp dword ptr [0xa51a10], 0
// 00743b78  755a                 jne 0x743bd4
// 00743b7a  56                   push esi
// 00743b7b  6a00                 push 0
// 00743b7d  6a00                 push 0
// 00743b7f  6a00                 push 0
// 00743b81  ff151ce28900         call dword ptr [0x89e21c]
// 00743b87  68ccff8a00           push 0x8affcc
// 00743b8c  a3101aa500           mov dword ptr [0xa51a10], eax
// 00743b91  8bf0                 mov esi, eax
// 00743b93  c744240802000000     mov dword ptr [esp + 8], 2
// 00743b9b  ff15e4e18900         call dword ptr [0x89e1e4]
// 00743ba1  85c0                 test eax, eax
// 00743ba3  7424                 je 0x743bc9
// 00743ba5  68b8ff8a00           push 0x8affb8
// 00743baa  50                   push eax
// 00743bab  ff15e8e18900         call dword ptr [0x89e1e8]
// 00743bb1  85c0                 test eax, eax
// 00743bb3  7414                 je 0x743bc9
// 00743bb5  6a04                 push 4
// 00743bb7  8d4c2408             lea ecx, [esp + 8]
// 00743bbb  51                   push ecx
// 00743bbc  6a00                 push 0
// 00743bbe  56                   push esi
// 00743bbf  ffd0                 call eax
// 00743bc1  a3181aa500           mov dword ptr [0xa51a18], eax
// 00743bc6  5e                   pop esi
// 00743bc7  59                   pop ecx
// 00743bc8  c3                   ret 
// 00743bc9  b801000000           mov eax, 1
// 00743bce  a3181aa500           mov dword ptr [0xa51a18], eax
// 00743bd3  5e                   pop esi
// 00743bd4  59                   pop ecx
// 00743bd5  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?CreateHeapIfNeed@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
