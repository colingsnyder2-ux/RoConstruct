// from server: 100% by auto
// roc 2009-12 0081ea30  unit: CXTPReportControl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081ea30
//
// 0081ea30  51                   push ecx
// 0081ea31  833d6caeb90000       cmp dword ptr [0xb9ae6c], 0
// 0081ea38  755a                 jne 0x81ea94
// 0081ea3a  56                   push esi
// 0081ea3b  6a00                 push 0
// 0081ea3d  6a00                 push 0
// 0081ea3f  6a00                 push 0
// 0081ea41  ff1500b39800         call dword ptr [0x98b300]
// 0081ea47  689c2c9a00           push 0x9a2c9c
// 0081ea4c  a36caeb900           mov dword ptr [0xb9ae6c], eax
// 0081ea51  8bf0                 mov esi, eax
// 0081ea53  c744240802000000     mov dword ptr [esp + 8], 2
// 0081ea5b  ff151cb29800         call dword ptr [0x98b21c]
// 0081ea61  85c0                 test eax, eax
// 0081ea63  7424                 je 0x81ea89
// 0081ea65  68882c9a00           push 0x9a2c88
// 0081ea6a  50                   push eax
// 0081ea6b  ff1520b29800         call dword ptr [0x98b220]
// 0081ea71  85c0                 test eax, eax
// 0081ea73  7414                 je 0x81ea89
// 0081ea75  6a04                 push 4
// 0081ea77  8d4c2408             lea ecx, [esp + 8]
// 0081ea7b  51                   push ecx
// 0081ea7c  6a00                 push 0
// 0081ea7e  56                   push esi
// 0081ea7f  ffd0                 call eax
// 0081ea81  a374aeb900           mov dword ptr [0xb9ae74], eax
// 0081ea86  5e                   pop esi
// 0081ea87  59                   pop ecx
// 0081ea88  c3                   ret 
// 0081ea89  b801000000           mov eax, 1
// 0081ea8e  a374aeb900           mov dword ptr [0xb9ae74], eax
// 0081ea93  5e                   pop esi
// 0081ea94  59                   pop ecx
// 0081ea95  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?CreateHeapIfNeed@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
