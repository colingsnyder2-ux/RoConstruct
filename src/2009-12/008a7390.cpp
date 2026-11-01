// from server: 100% by auto
// roc 2009-12 008a7390  unit: CXTPReportHeaderDragWnd  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a7390
//
// 008a7390  56                   push esi
// 008a7391  8bf1                 mov esi, ecx
// 008a7393  e8b0cdf4ff           call 0x7f4148
// 008a7398  8b442408             mov eax, dword ptr [esp + 8]
// 008a739c  894654               mov dword ptr [esi + 0x54], eax
// 008a739f  33c0                 xor eax, eax
// 008a73a1  c706cc60a000         mov dword ptr [esi], 0xa060cc
// 008a73a7  89465c               mov dword ptr [esi + 0x5c], eax
// 008a73aa  c74658f82a9f00       mov dword ptr [esi + 0x58], 0x9f2af8
// 008a73b1  894660               mov dword ptr [esi + 0x60], eax
// 008a73b4  8bc6                 mov eax, esi
// 008a73b6  5e                   pop esi
// 008a73b7  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ??0CXTPReportHeaderDropWnd@@QAE@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportDragDrop.cpp
