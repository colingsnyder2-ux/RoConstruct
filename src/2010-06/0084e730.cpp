// from server: 100% by auto
// roc 2010-06 0084e730  unit: CXTPFormulaMulDivC  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084e730
//
// 0084e730  8b442404             mov eax, dword ptr [esp + 4]
// 0084e734  8b542408             mov edx, dword ptr [esp + 8]
// 0084e738  894120               mov dword ptr [ecx + 0x20], eax
// 0084e73b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0084e73f  895124               mov dword ptr [ecx + 0x24], edx
// 0084e742  894128               mov dword ptr [ecx + 0x28], eax
// 0084e745  c20c00               ret 0xc
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?SetStandardValue@CXTPFormulaMulDivC@@UAEXHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
