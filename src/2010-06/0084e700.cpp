// from server: 100% by auto
// roc 2010-06 0084e700  unit: CXTPFormulaMulDivC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084e700
//
// 0084e700  8b4124               mov eax, dword ptr [ecx + 0x24]
// 0084e703  56                   push esi
// 0084e704  8bf0                 mov esi, eax
// 0084e706  85c0                 test eax, eax
// 0084e708  7505                 jne 0x84e70f
// 0084e70a  be01000000           mov esi, 1
// 0084e70f  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0084e712  0faf442408           imul eax, dword ptr [esp + 8]
// 0084e717  99                   cdq 
// 0084e718  f7fe                 idiv esi
// 0084e71a  5e                   pop esi
// 0084e71b  034128               add eax, dword ptr [ecx + 0x28]
// 0084e71e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?Calculate@CXTPFormulaMulDivC@@UBEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
