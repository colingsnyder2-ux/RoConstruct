// from server: 100% by auto
// roc 2009-12 008a2c50  unit: CXTPReportHyperlink  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a2c50
//
// 008a2c50  56                   push esi
// 008a2c51  8bf1                 mov esi, ecx
// 008a2c53  e8ea370800           call 0x926442
// 008a2c58  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a2c5c  33c0                 xor eax, eax
// 008a2c5e  c706e458a000         mov dword ptr [esi], 0xa058e4
// 008a2c64  894620               mov dword ptr [esi + 0x20], eax
// 008a2c67  894624               mov dword ptr [esi + 0x24], eax
// 008a2c6a  894628               mov dword ptr [esi + 0x28], eax
// 008a2c6d  89462c               mov dword ptr [esi + 0x2c], eax
// 008a2c70  8b442408             mov eax, dword ptr [esp + 8]
// 008a2c74  894630               mov dword ptr [esi + 0x30], eax
// 008a2c77  894e34               mov dword ptr [esi + 0x34], ecx
// 008a2c7a  8bc6                 mov eax, esi
// 008a2c7c  5e                   pop esi
// 008a2c7d  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportHyperlink.cpp (function ??0CXTPReportHyperlink@@QAE@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportHyperlink.cpp
