// from server: 100% by auto
// roc 2010-06 00856dd0  unit: CXTPReportHyperlink  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00856dd0
//
// 00856dd0  56                   push esi
// 00856dd1  8bf1                 mov esi, ecx
// 00856dd3  e8a65f1200           call 0x97cd7e
// 00856dd8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00856ddc  33c0                 xor eax, eax
// 00856dde  c706cc9ba600         mov dword ptr [esi], 0xa69bcc
// 00856de4  894620               mov dword ptr [esi + 0x20], eax
// 00856de7  894624               mov dword ptr [esi + 0x24], eax
// 00856dea  894628               mov dword ptr [esi + 0x28], eax
// 00856ded  89462c               mov dword ptr [esi + 0x2c], eax
// 00856df0  8b442408             mov eax, dword ptr [esp + 8]
// 00856df4  894630               mov dword ptr [esi + 0x30], eax
// 00856df7  894e34               mov dword ptr [esi + 0x34], ecx
// 00856dfa  8bc6                 mov eax, esi
// 00856dfc  5e                   pop esi
// 00856dfd  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportHyperlink.cpp (function ??0CXTPReportHyperlink@@QAE@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportHyperlink.cpp
