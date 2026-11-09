// from server: 100% by auto
// roc 2009-12 0089a5a0  unit: CXTPFormulaMulDivC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089a5a0
//
// 0089a5a0  8b4124               mov eax, dword ptr [ecx + 0x24]
// 0089a5a3  56                   push esi
// 0089a5a4  8bf0                 mov esi, eax
// 0089a5a6  85c0                 test eax, eax
// 0089a5a8  7505                 jne 0x89a5af
// 0089a5aa  be01000000           mov esi, 1
// 0089a5af  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0089a5b2  0faf442408           imul eax, dword ptr [esp + 8]
// 0089a5b7  99                   cdq 
// 0089a5b8  f7fe                 idiv esi
// 0089a5ba  5e                   pop esi
// 0089a5bb  034128               add eax, dword ptr [ecx + 0x28]
// 0089a5be  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?Calculate@CXTPFormulaMulDivC@@UBEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
