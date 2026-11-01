// from server: 100% by auto
// roc 2009-12 0081b6a0  unit: CInstanceRecord::CNameItem  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081b6a0
//
// 0081b6a0  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0081b6a7  6860aeb900           push 0xb9ae60
// 0081b6ac  743b                 je 0x81b6e9
// 0081b6ae  ff150cb29800         call dword ptr [0x98b20c]
// 0081b6b4  833d68aeb90000       cmp dword ptr [0xb9ae68], 0
// 0081b6bb  741c                 je 0x81b6d9
// 0081b6bd  e8cef6bfff           call 0x41ad90
// 0081b6c2  8b442404             mov eax, dword ptr [esp + 4]
// 0081b6c6  8b0d5caeb900         mov ecx, dword ptr [0xb9ae5c]
// 0081b6cc  50                   push eax
// 0081b6cd  6a00                 push 0
// 0081b6cf  51                   push ecx
// 0081b6d0  ff1508b39800         call dword ptr [0x98b308]
// 0081b6d6  c20400               ret 4
// 0081b6d9  8b542404             mov edx, dword ptr [esp + 4]
// 0081b6dd  52                   push edx
// 0081b6de  e85f84fdff           call 0x7f3b42
// 0081b6e3  83c404               add esp, 4
// 0081b6e6  c20400               ret 4
// 0081b6e9  ff150cb29800         call dword ptr [0x98b20c]
// 0081b6ef  8b442404             mov eax, dword ptr [esp + 4]
// 0081b6f3  50                   push eax
// 0081b6f4  e86781fdff           call 0x7f3860
// 0081b6f9  83c404               add esp, 4
// 0081b6fc  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??2?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
