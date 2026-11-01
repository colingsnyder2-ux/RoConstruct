// from server: 100% by auto
// roc 2009-12 00822630  unit: UCXTPReportAllocatorDefaultData::?$CXTPHeapAllocatorT  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00822630
//
// 00822630  56                   push esi
// 00822631  8bf1                 mov esi, ecx
// 00822633  c706e44e9f00         mov dword ptr [esi], 0x9f4ee4
// 00822639  833d80aeb90000       cmp dword ptr [0xb9ae80], 0
// 00822640  751a                 jne 0x82265c
// 00822642  a17caeb900           mov eax, dword ptr [0xb9ae7c]
// 00822647  85c0                 test eax, eax
// 00822649  7407                 je 0x822652
// 0082264b  50                   push eax
// 0082264c  ff1504b39800         call dword ptr [0x98b304]
// 00822652  c7057caeb90000000000 mov dword ptr [0xb9ae7c], 0
// 0082265c  f644240801           test byte ptr [esp + 8], 1
// 00822661  7409                 je 0x82266c
// 00822663  56                   push esi
// 00822664  e8f111fdff           call 0x7f385a
// 00822669  83c404               add esp, 4
// 0082266c  8bc6                 mov eax, esi
// 0082266e  5e                   pop esi
// 0082266f  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
