// from server: 100% by auto
// roc 2009-12 0089a5f0  unit: CXTPFormulaMulDivC  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089a5f0
//
// 0089a5f0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0089a5f3  8b542404             mov edx, dword ptr [esp + 4]
// 0089a5f7  8902                 mov dword ptr [edx], eax
// 0089a5f9  8b4124               mov eax, dword ptr [ecx + 0x24]
// 0089a5fc  8b542408             mov edx, dword ptr [esp + 8]
// 0089a600  8902                 mov dword ptr [edx], eax
// 0089a602  8b4128               mov eax, dword ptr [ecx + 0x28]
// 0089a605  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0089a609  8901                 mov dword ptr [ecx], eax
// 0089a60b  c20c00               ret 0xc
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?GetStandardValue@CXTPFormulaMulDivC@@UAEXAAH00@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
