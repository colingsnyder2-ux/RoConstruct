// from server: 100% by auto
// roc 2009-06 007cb5d0  unit: CXTPReportTip  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cb5d0
//
// 007cb5d0  56                   push esi
// 007cb5d1  8bf1                 mov esi, ecx
// 007cb5d3  e852090800           call 0x84bf2a
// 007cb5d8  8b442408             mov eax, dword ptr [esp + 8]
// 007cb5dc  894620               mov dword ptr [esi + 0x20], eax
// 007cb5df  33c0                 xor eax, eax
// 007cb5e1  894624               mov dword ptr [esi + 0x24], eax
// 007cb5e4  894628               mov dword ptr [esi + 0x28], eax
// 007cb5e7  c706a45a9000         mov dword ptr [esi], 0x905aa4
// 007cb5ed  8bc6                 mov eax, esi
// 007cb5ef  5e                   pop esi
// 007cb5f0  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportNavigator.cpp (function ??0CXTPReportNavigator@@QAE@PAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportNavigator.cpp
