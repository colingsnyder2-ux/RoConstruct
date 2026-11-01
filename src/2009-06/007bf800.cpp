// from server: 100% by auto
// roc 2009-06 007bf800  unit: CXTPFormulaMulDivC  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bf800
//
// 007bf800  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007bf803  8b542404             mov edx, dword ptr [esp + 4]
// 007bf807  8902                 mov dword ptr [edx], eax
// 007bf809  8b4124               mov eax, dword ptr [ecx + 0x24]
// 007bf80c  8b542408             mov edx, dword ptr [esp + 8]
// 007bf810  8902                 mov dword ptr [edx], eax
// 007bf812  8b4128               mov eax, dword ptr [ecx + 0x28]
// 007bf815  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007bf819  8901                 mov dword ptr [ecx], eax
// 007bf81b  c20c00               ret 0xc
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?GetStandardValue@CXTPFormulaMulDivC@@UAEXAAH00@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
