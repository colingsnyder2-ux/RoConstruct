// from server: 100% by auto
// roc 2009-06 007bf7b0  unit: CXTPFormulaMulDivC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bf7b0
//
// 007bf7b0  8b4124               mov eax, dword ptr [ecx + 0x24]
// 007bf7b3  56                   push esi
// 007bf7b4  8bf0                 mov esi, eax
// 007bf7b6  85c0                 test eax, eax
// 007bf7b8  7505                 jne 0x7bf7bf
// 007bf7ba  be01000000           mov esi, 1
// 007bf7bf  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007bf7c2  0faf442408           imul eax, dword ptr [esp + 8]
// 007bf7c7  99                   cdq 
// 007bf7c8  f7fe                 idiv esi
// 007bf7ca  5e                   pop esi
// 007bf7cb  034128               add eax, dword ptr [ecx + 0x28]
// 007bf7ce  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?Calculate@CXTPFormulaMulDivC@@UBEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
