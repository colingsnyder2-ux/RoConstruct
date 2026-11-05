// from server: 100% by auto
// roc 2009-06 007bf7e0  unit: CXTPFormulaMulDivC  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bf7e0
//
// 007bf7e0  8b442404             mov eax, dword ptr [esp + 4]
// 007bf7e4  8b542408             mov edx, dword ptr [esp + 8]
// 007bf7e8  894120               mov dword ptr [ecx + 0x20], eax
// 007bf7eb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bf7ef  895124               mov dword ptr [ecx + 0x24], edx
// 007bf7f2  894128               mov dword ptr [ecx + 0x28], eax
// 007bf7f5  c20c00               ret 0xc
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?SetStandardValue@CXTPFormulaMulDivC@@UAEXHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
