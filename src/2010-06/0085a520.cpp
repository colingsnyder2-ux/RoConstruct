// from server: 100% by auto
// roc 2010-06 0085a520  unit: CXTPReportTip  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085a520
//
// 0085a520  56                   push esi
// 0085a521  8bf1                 mov esi, ecx
// 0085a523  e856281200           call 0x97cd7e
// 0085a528  8b442408             mov eax, dword ptr [esp + 8]
// 0085a52c  894620               mov dword ptr [esi + 0x20], eax
// 0085a52f  33c0                 xor eax, eax
// 0085a531  894624               mov dword ptr [esi + 0x24], eax
// 0085a534  894628               mov dword ptr [esi + 0x28], eax
// 0085a537  c70604a2a600         mov dword ptr [esi], 0xa6a204
// 0085a53d  8bc6                 mov eax, esi
// 0085a53f  5e                   pop esi
// 0085a540  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportNavigator.cpp (function ??0CXTPReportNavigator@@QAE@PAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportNavigator.cpp
