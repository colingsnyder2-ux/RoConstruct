// from server: 100% by auto
// roc 2011-06 008ab870  unit: CXTPFormulaMulDivC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ab870
//
// 008ab870  8b4124               mov eax, dword ptr [ecx + 0x24]
// 008ab873  56                   push esi
// 008ab874  8bf0                 mov esi, eax
// 008ab876  85c0                 test eax, eax
// 008ab878  7505                 jne 0x8ab87f
// 008ab87a  be01000000           mov esi, 1
// 008ab87f  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008ab882  0faf442408           imul eax, dword ptr [esp + 8]
// 008ab887  99                   cdq 
// 008ab888  f7fe                 idiv esi
// 008ab88a  5e                   pop esi
// 008ab88b  034128               add eax, dword ptr [ecx + 0x28]
// 008ab88e  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?Calculate@CXTPFormulaMulDivC@@UBEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
