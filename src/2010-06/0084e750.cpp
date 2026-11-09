// from server: 100% by auto
// roc 2010-06 0084e750  unit: CXTPFormulaMulDivC  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084e750
//
// 0084e750  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0084e753  8b542404             mov edx, dword ptr [esp + 4]
// 0084e757  8902                 mov dword ptr [edx], eax
// 0084e759  8b4124               mov eax, dword ptr [ecx + 0x24]
// 0084e75c  8b542408             mov edx, dword ptr [esp + 8]
// 0084e760  8902                 mov dword ptr [edx], eax
// 0084e762  8b4128               mov eax, dword ptr [ecx + 0x28]
// 0084e765  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0084e769  8901                 mov dword ptr [ecx], eax
// 0084e76b  c20c00               ret 0xc
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?GetStandardValue@CXTPFormulaMulDivC@@UAEXAAH00@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
