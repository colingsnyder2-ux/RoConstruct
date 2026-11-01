// from server: 100% by auto
// roc 2011-06 008ab830  unit: CXTPRibbonBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ab830
//
// 008ab830  56                   push esi
// 008ab831  8bf1                 mov esi, ecx
// 008ab833  e8920d1200           call 0x9cc5ca
// 008ab838  b801000000           mov eax, 1
// 008ab83d  894620               mov dword ptr [esi + 0x20], eax
// 008ab840  894624               mov dword ptr [esi + 0x24], eax
// 008ab843  c706343fad00         mov dword ptr [esi], 0xad3f34
// 008ab849  c7462800000000       mov dword ptr [esi + 0x28], 0
// 008ab850  8bc6                 mov eax, esi
// 008ab852  5e                   pop esi
// 008ab853  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ??0CXTPFormulaMulDivC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
