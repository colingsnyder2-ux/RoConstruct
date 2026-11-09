// from server: 100% by auto
// roc 2011-06 008b6d70  unit: CXTPReportInplaceList  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b6d70
//
// 008b6d70  56                   push esi
// 008b6d71  8bf1                 mov esi, ecx
// 008b6d73  e852581100           call 0x9cc5ca
// 008b6d78  8b442408             mov eax, dword ptr [esp + 8]
// 008b6d7c  894620               mov dword ptr [esi + 0x20], eax
// 008b6d7f  33c0                 xor eax, eax
// 008b6d81  894624               mov dword ptr [esi + 0x24], eax
// 008b6d84  894628               mov dword ptr [esi + 0x28], eax
// 008b6d87  c7068c49ad00         mov dword ptr [esi], 0xad498c
// 008b6d8d  8bc6                 mov eax, esi
// 008b6d8f  5e                   pop esi
// 008b6d90  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportNavigator.cpp (function ??0CXTPReportNavigator@@QAE@PAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportNavigator.cpp
