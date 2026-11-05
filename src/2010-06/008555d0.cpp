// from server: 100% by auto
// roc 2010-06 008555d0  unit: CXTPReportInplaceEdit  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008555d0
//
// 008555d0  8bc1                 mov eax, ecx
// 008555d2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008555d6  8b11                 mov edx, dword ptr [ecx]
// 008555d8  8b808c000000         mov eax, dword ptr [eax + 0x8c]
// 008555de  8b5238               mov edx, dword ptr [edx + 0x38]
// 008555e1  50                   push eax
// 008555e2  ffd2                 call edx
// 008555e4  6a05                 push 5
// 008555e6  ff1520ba9e00         call dword ptr [0x9eba20]
// 008555ec  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportInplaceControls.cpp (function ?CtlColor@CXTPReportInplaceEdit@@IAEPAUHBRUSH__@@PAVCDC@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportInplaceControls.cpp
