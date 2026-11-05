// from server: 100% by auto
// roc 2010-06 0085b4e0  unit: CXTPReportHeaderDragWnd  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085b4e0
//
// 0085b4e0  56                   push esi
// 0085b4e1  8bf1                 mov esi, ecx
// 0085b4e3  e8a0cdf4ff           call 0x7a8288
// 0085b4e8  8b442408             mov eax, dword ptr [esp + 8]
// 0085b4ec  894654               mov dword ptr [esi + 0x54], eax
// 0085b4ef  33c0                 xor eax, eax
// 0085b4f1  c706b4a3a600         mov dword ptr [esi], 0xa6a3b4
// 0085b4f7  89465c               mov dword ptr [esi + 0x5c], eax
// 0085b4fa  c74658e06da500       mov dword ptr [esi + 0x58], 0xa56de0
// 0085b501  894660               mov dword ptr [esi + 0x60], eax
// 0085b504  8bc6                 mov eax, esi
// 0085b506  5e                   pop esi
// 0085b507  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ??0CXTPReportHeaderDropWnd@@QAE@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportDragDrop.cpp
