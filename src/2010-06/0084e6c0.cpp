// from server: 100% by auto
// roc 2010-06 0084e6c0  unit: CXTPRibbonBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084e6c0
//
// 0084e6c0  56                   push esi
// 0084e6c1  8bf1                 mov esi, ecx
// 0084e6c3  e8b6e61200           call 0x97cd7e
// 0084e6c8  b801000000           mov eax, 1
// 0084e6cd  894620               mov dword ptr [esi + 0x20], eax
// 0084e6d0  894624               mov dword ptr [esi + 0x24], eax
// 0084e6d3  c7061495a600         mov dword ptr [esi], 0xa69514
// 0084e6d9  c7462800000000       mov dword ptr [esi + 0x28], 0
// 0084e6e0  8bc6                 mov eax, esi
// 0084e6e2  5e                   pop esi
// 0084e6e3  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ??0CXTPFormulaMulDivC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
