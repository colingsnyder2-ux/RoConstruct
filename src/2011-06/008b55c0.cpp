// from server: 100% by auto
// roc 2011-06 008b55c0  unit: CXTPReportInplaceEdit  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b55c0
//
// 008b55c0  8bc1                 mov eax, ecx
// 008b55c2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008b55c6  8b11                 mov edx, dword ptr [ecx]
// 008b55c8  8b808c000000         mov eax, dword ptr [eax + 0x8c]
// 008b55ce  8b5238               mov edx, dword ptr [edx + 0x38]
// 008b55d1  50                   push eax
// 008b55d2  ffd2                 call edx
// 008b55d4  6a05                 push 5
// 008b55d6  ff15701aa400         call dword ptr [0xa41a70]
// 008b55dc  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\ReportControl\XTPReportInplaceEdit.cpp (function ?CtlColor@CXTPReportInplaceEdit@@IAEPAUHBRUSH__@@PAVCDC@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/ReportControl/XTPReportInplaceEdit.cpp
