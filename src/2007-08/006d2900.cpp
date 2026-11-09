// from server: 100% by auto
// roc 2007-08 006d2900  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d2900
//
// 006d2900  8b01                 mov eax, dword ptr [ecx]
// 006d2902  8b5060               mov edx, dword ptr [eax + 0x60]
// 006d2905  ffe2                 jmp edx
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ?OnClose@CDockablePane@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
