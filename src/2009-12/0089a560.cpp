// from server: 100% by auto
// roc 2009-12 0089a560  unit: CXTPRibbonBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089a560
//
// 0089a560  56                   push esi
// 0089a561  8bf1                 mov esi, ecx
// 0089a563  e8dabe0800           call 0x926442
// 0089a568  b801000000           mov eax, 1
// 0089a56d  894620               mov dword ptr [esi + 0x20], eax
// 0089a570  894624               mov dword ptr [esi + 0x24], eax
// 0089a573  c7063452a000         mov dword ptr [esi], 0xa05234
// 0089a579  c7462800000000       mov dword ptr [esi + 0x28], 0
// 0089a580  8bc6                 mov eax, esi
// 0089a582  5e                   pop esi
// 0089a583  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ??0CXTPFormulaMulDivC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
