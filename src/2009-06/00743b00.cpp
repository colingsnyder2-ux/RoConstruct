// from server: 100% by auto
// roc 2009-06 00743b00  unit: CXTPReportControl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00743b00
//
// 00743b00  51                   push ecx
// 00743b01  833d201aa50000       cmp dword ptr [0xa51a20], 0
// 00743b08  755a                 jne 0x743b64
// 00743b0a  56                   push esi
// 00743b0b  6a00                 push 0
// 00743b0d  6a00                 push 0
// 00743b0f  6a00                 push 0
// 00743b11  ff151ce28900         call dword ptr [0x89e21c]
// 00743b17  68ccff8a00           push 0x8affcc
// 00743b1c  a3201aa500           mov dword ptr [0xa51a20], eax
// 00743b21  8bf0                 mov esi, eax
// 00743b23  c744240802000000     mov dword ptr [esp + 8], 2
// 00743b2b  ff15e4e18900         call dword ptr [0x89e1e4]
// 00743b31  85c0                 test eax, eax
// 00743b33  7424                 je 0x743b59
// 00743b35  68b8ff8a00           push 0x8affb8
// 00743b3a  50                   push eax
// 00743b3b  ff15e8e18900         call dword ptr [0x89e1e8]
// 00743b41  85c0                 test eax, eax
// 00743b43  7414                 je 0x743b59
// 00743b45  6a04                 push 4
// 00743b47  8d4c2408             lea ecx, [esp + 8]
// 00743b4b  51                   push ecx
// 00743b4c  6a00                 push 0
// 00743b4e  56                   push esi
// 00743b4f  ffd0                 call eax
// 00743b51  a3281aa500           mov dword ptr [0xa51a28], eax
// 00743b56  5e                   pop esi
// 00743b57  59                   pop ecx
// 00743b58  c3                   ret 
// 00743b59  b801000000           mov eax, 1
// 00743b5e  a3281aa500           mov dword ptr [0xa51a28], eax
// 00743b63  5e                   pop esi
// 00743b64  59                   pop ecx
// 00743b65  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?CreateHeapIfNeed@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
