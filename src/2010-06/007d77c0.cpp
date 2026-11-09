// from server: 100% by auto
// roc 2010-06 007d77c0  unit: CXTPReportControl  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d77c0
//
// 007d77c0  833db855c20000       cmp dword ptr [0xc255b8], 0
// 007d77c7  7410                 je 0x7d77d9
// 007d77c9  8b442404             mov eax, dword ptr [esp + 4]
// 007d77cd  50                   push eax
// 007d77ce  e83defffff           call 0x7d6710
// 007d77d3  83c404               add esp, 4
// 007d77d6  c20400               ret 4
// 007d77d9  68b055c200           push 0xc255b0
// 007d77de  ff157ca39e00         call dword ptr [0x9ea37c]
// 007d77e4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d77e8  51                   push ecx
// 007d77e9  e8ac01fdff           call 0x7a799a
// 007d77ee  59                   pop ecx
// 007d77ef  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??3?$CXTPHeapObjectT@VCXTPReportRowBase@@VCXTPReportRowAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
