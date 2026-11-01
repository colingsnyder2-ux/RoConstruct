// from server: 100% by auto
// roc 2009-06 0041a990  unit: CInstanceRecord::CNameItem  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041a990
//
// 0041a990  51                   push ecx
// 0041a991  833d001aa50000       cmp dword ptr [0xa51a00], 0
// 0041a998  755a                 jne 0x41a9f4
// 0041a99a  56                   push esi
// 0041a99b  6a00                 push 0
// 0041a99d  6a00                 push 0
// 0041a99f  6a00                 push 0
// 0041a9a1  ff151ce28900         call dword ptr [0x89e21c]
// 0041a9a7  68ccff8a00           push 0x8affcc
// 0041a9ac  a3001aa500           mov dword ptr [0xa51a00], eax
// 0041a9b1  8bf0                 mov esi, eax
// 0041a9b3  c744240802000000     mov dword ptr [esp + 8], 2
// 0041a9bb  ff15e4e18900         call dword ptr [0x89e1e4]
// 0041a9c1  85c0                 test eax, eax
// 0041a9c3  7424                 je 0x41a9e9
// 0041a9c5  68b8ff8a00           push 0x8affb8
// 0041a9ca  50                   push eax
// 0041a9cb  ff15e8e18900         call dword ptr [0x89e1e8]
// 0041a9d1  85c0                 test eax, eax
// 0041a9d3  7414                 je 0x41a9e9
// 0041a9d5  6a04                 push 4
// 0041a9d7  8d4c2408             lea ecx, [esp + 8]
// 0041a9db  51                   push ecx
// 0041a9dc  6a00                 push 0
// 0041a9de  56                   push esi
// 0041a9df  ffd0                 call eax
// 0041a9e1  a3081aa500           mov dword ptr [0xa51a08], eax
// 0041a9e6  5e                   pop esi
// 0041a9e7  59                   pop ecx
// 0041a9e8  c3                   ret 
// 0041a9e9  b801000000           mov eax, 1
// 0041a9ee  a3081aa500           mov dword ptr [0xa51a08], eax
// 0041a9f3  5e                   pop esi
// 0041a9f4  59                   pop ecx
// 0041a9f5  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?CreateHeapIfNeed@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
