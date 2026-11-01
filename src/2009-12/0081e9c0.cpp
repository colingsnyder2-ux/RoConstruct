// from server: 100% by auto
// roc 2009-12 0081e9c0  unit: CXTPReportControl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081e9c0
//
// 0081e9c0  51                   push ecx
// 0081e9c1  833d7caeb90000       cmp dword ptr [0xb9ae7c], 0
// 0081e9c8  755a                 jne 0x81ea24
// 0081e9ca  56                   push esi
// 0081e9cb  6a00                 push 0
// 0081e9cd  6a00                 push 0
// 0081e9cf  6a00                 push 0
// 0081e9d1  ff1500b39800         call dword ptr [0x98b300]
// 0081e9d7  689c2c9a00           push 0x9a2c9c
// 0081e9dc  a37caeb900           mov dword ptr [0xb9ae7c], eax
// 0081e9e1  8bf0                 mov esi, eax
// 0081e9e3  c744240802000000     mov dword ptr [esp + 8], 2
// 0081e9eb  ff151cb29800         call dword ptr [0x98b21c]
// 0081e9f1  85c0                 test eax, eax
// 0081e9f3  7424                 je 0x81ea19
// 0081e9f5  68882c9a00           push 0x9a2c88
// 0081e9fa  50                   push eax
// 0081e9fb  ff1520b29800         call dword ptr [0x98b220]
// 0081ea01  85c0                 test eax, eax
// 0081ea03  7414                 je 0x81ea19
// 0081ea05  6a04                 push 4
// 0081ea07  8d4c2408             lea ecx, [esp + 8]
// 0081ea0b  51                   push ecx
// 0081ea0c  6a00                 push 0
// 0081ea0e  56                   push esi
// 0081ea0f  ffd0                 call eax
// 0081ea11  a384aeb900           mov dword ptr [0xb9ae84], eax
// 0081ea16  5e                   pop esi
// 0081ea17  59                   pop ecx
// 0081ea18  c3                   ret 
// 0081ea19  b801000000           mov eax, 1
// 0081ea1e  a384aeb900           mov dword ptr [0xb9ae84], eax
// 0081ea23  5e                   pop esi
// 0081ea24  59                   pop ecx
// 0081ea25  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?CreateHeapIfNeed@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
