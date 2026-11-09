// from server: 100% by auto
// roc 2008-06 00754280  unit: CXTPReportHeaderDragWnd  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00754280
//
// 00754280  8b01                 mov eax, dword ptr [ecx]
// 00754282  85c0                 test eax, eax
// 00754284  7407                 je 0x75428d
// 00754286  50                   push eax
// 00754287  ff1508208000         call dword ptr [0x802008]
// 0075428d  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgtempl.cpp (function ??1CDialogTemplate@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgtempl.cpp
