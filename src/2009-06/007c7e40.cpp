// from server: 100% by auto
// roc 2009-06 007c7e40  unit: CXTPReportHyperlink  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c7e40
//
// 007c7e40  56                   push esi
// 007c7e41  8bf1                 mov esi, ecx
// 007c7e43  e8e2400800           call 0x84bf2a
// 007c7e48  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007c7e4c  33c0                 xor eax, eax
// 007c7e4e  c7066c549000         mov dword ptr [esi], 0x90546c
// 007c7e54  894620               mov dword ptr [esi + 0x20], eax
// 007c7e57  894624               mov dword ptr [esi + 0x24], eax
// 007c7e5a  894628               mov dword ptr [esi + 0x28], eax
// 007c7e5d  89462c               mov dword ptr [esi + 0x2c], eax
// 007c7e60  8b442408             mov eax, dword ptr [esp + 8]
// 007c7e64  894630               mov dword ptr [esi + 0x30], eax
// 007c7e67  894e34               mov dword ptr [esi + 0x34], ecx
// 007c7e6a  8bc6                 mov eax, esi
// 007c7e6c  5e                   pop esi
// 007c7e6d  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportHyperlink.cpp (function ??0CXTPReportHyperlink@@QAE@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportHyperlink.cpp
