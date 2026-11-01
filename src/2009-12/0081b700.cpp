// from server: 100% by auto
// roc 2009-12 0081b700  unit: CInstanceRecord::CNameItem  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081b700
//
// 0081b700  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0081b707  7410                 je 0x81b719
// 0081b709  8b442404             mov eax, dword ptr [esp + 4]
// 0081b70d  50                   push eax
// 0081b70e  e88df9bfff           call 0x41b0a0
// 0081b713  83c404               add esp, 4
// 0081b716  c20400               ret 4
// 0081b719  6860aeb900           push 0xb9ae60
// 0081b71e  ff1508b29800         call dword ptr [0x98b208]
// 0081b724  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0081b728  51                   push ecx
// 0081b729  e82c81fdff           call 0x7f385a
// 0081b72e  59                   pop ecx
// 0081b72f  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??3?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
