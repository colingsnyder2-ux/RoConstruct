// from server: 100% by auto
// roc 2009-06 007cc8a0  unit: CXTPReportHeaderDragWnd  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cc8a0
//
// 007cc8a0  8b01                 mov eax, dword ptr [ecx]
// 007cc8a2  85c0                 test eax, eax
// 007cc8a4  7407                 je 0x7cc8ad
// 007cc8a6  50                   push eax
// 007cc8a7  ff1508e08900         call dword ptr [0x89e008]
// 007cc8ad  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgtempl.cpp (function ??1CDialogTemplate@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgtempl.cpp
