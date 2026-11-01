// from server: 100% by auto
// roc 2011-06 008ab8c0  unit: CXTPFormulaMulDivC  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ab8c0
//
// 008ab8c0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008ab8c3  8b542404             mov edx, dword ptr [esp + 4]
// 008ab8c7  8902                 mov dword ptr [edx], eax
// 008ab8c9  8b4124               mov eax, dword ptr [ecx + 0x24]
// 008ab8cc  8b542408             mov edx, dword ptr [esp + 8]
// 008ab8d0  8902                 mov dword ptr [edx], eax
// 008ab8d2  8b4128               mov eax, dword ptr [ecx + 0x28]
// 008ab8d5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008ab8d9  8901                 mov dword ptr [ecx], eax
// 008ab8db  c20c00               ret 0xc
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?GetStandardValue@CXTPFormulaMulDivC@@UAEXAAH00@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
