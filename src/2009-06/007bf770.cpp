// from server: 100% by auto
// roc 2009-06 007bf770  unit: CXTPDockContext  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bf770
//
// 007bf770  56                   push esi
// 007bf771  8bf1                 mov esi, ecx
// 007bf773  e8b2c70800           call 0x84bf2a
// 007bf778  b801000000           mov eax, 1
// 007bf77d  894620               mov dword ptr [esi + 0x20], eax
// 007bf780  894624               mov dword ptr [esi + 0x24], eax
// 007bf783  c706b44d9000         mov dword ptr [esi], 0x904db4
// 007bf789  c7462800000000       mov dword ptr [esi + 0x28], 0
// 007bf790  8bc6                 mov eax, esi
// 007bf792  5e                   pop esi
// 007bf793  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ??0CXTPFormulaMulDivC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
