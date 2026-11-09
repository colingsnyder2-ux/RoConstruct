// from server: 100% by auto
// roc 2010-06 0085b7e0  unit: CXTPReportHeaderDragWnd  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085b7e0
//
// 0085b7e0  8b01                 mov eax, dword ptr [ecx]
// 0085b7e2  85c0                 test eax, eax
// 0085b7e4  7407                 je 0x85b7ed
// 0085b7e6  50                   push eax
// 0085b7e7  ff1510a09e00         call dword ptr [0x9ea010]
// 0085b7ed  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgtempl.cpp (function ??1CDialogTemplate@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgtempl.cpp
