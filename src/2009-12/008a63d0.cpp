// from server: 100% by auto
// roc 2009-12 008a63d0  unit: CXTPReportTip  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a63d0
//
// 008a63d0  56                   push esi
// 008a63d1  8bf1                 mov esi, ecx
// 008a63d3  e86a000800           call 0x926442
// 008a63d8  8b442408             mov eax, dword ptr [esp + 8]
// 008a63dc  894620               mov dword ptr [esi + 0x20], eax
// 008a63df  33c0                 xor eax, eax
// 008a63e1  894624               mov dword ptr [esi + 0x24], eax
// 008a63e4  894628               mov dword ptr [esi + 0x28], eax
// 008a63e7  c7061c5fa000         mov dword ptr [esi], 0xa05f1c
// 008a63ed  8bc6                 mov eax, esi
// 008a63ef  5e                   pop esi
// 008a63f0  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportNavigator.cpp (function ??0CXTPReportNavigator@@QAE@PAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportNavigator.cpp
