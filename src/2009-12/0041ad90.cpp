// from server: 100% by auto
// roc 2009-12 0041ad90  unit: CInstanceRecord::CNameItem  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041ad90
//
// 0041ad90  51                   push ecx
// 0041ad91  833d5caeb90000       cmp dword ptr [0xb9ae5c], 0
// 0041ad98  755a                 jne 0x41adf4
// 0041ad9a  56                   push esi
// 0041ad9b  6a00                 push 0
// 0041ad9d  6a00                 push 0
// 0041ad9f  6a00                 push 0
// 0041ada1  ff1500b39800         call dword ptr [0x98b300]
// 0041ada7  689c2c9a00           push 0x9a2c9c
// 0041adac  a35caeb900           mov dword ptr [0xb9ae5c], eax
// 0041adb1  8bf0                 mov esi, eax
// 0041adb3  c744240802000000     mov dword ptr [esp + 8], 2
// 0041adbb  ff151cb29800         call dword ptr [0x98b21c]
// 0041adc1  85c0                 test eax, eax
// 0041adc3  7424                 je 0x41ade9
// 0041adc5  68882c9a00           push 0x9a2c88
// 0041adca  50                   push eax
// 0041adcb  ff1520b29800         call dword ptr [0x98b220]
// 0041add1  85c0                 test eax, eax
// 0041add3  7414                 je 0x41ade9
// 0041add5  6a04                 push 4
// 0041add7  8d4c2408             lea ecx, [esp + 8]
// 0041addb  51                   push ecx
// 0041addc  6a00                 push 0
// 0041adde  56                   push esi
// 0041addf  ffd0                 call eax
// 0041ade1  a364aeb900           mov dword ptr [0xb9ae64], eax
// 0041ade6  5e                   pop esi
// 0041ade7  59                   pop ecx
// 0041ade8  c3                   ret 
// 0041ade9  b801000000           mov eax, 1
// 0041adee  a364aeb900           mov dword ptr [0xb9ae64], eax
// 0041adf3  5e                   pop esi
// 0041adf4  59                   pop ecx
// 0041adf5  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?CreateHeapIfNeed@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
