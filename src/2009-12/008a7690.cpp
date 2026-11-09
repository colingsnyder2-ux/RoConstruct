// from server: 100% by auto
// roc 2009-12 008a7690  unit: CXTPReportHeaderDragWnd  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a7690
//
// 008a7690  8b01                 mov eax, dword ptr [ecx]
// 008a7692  85c0                 test eax, eax
// 008a7694  7407                 je 0x8a769d
// 008a7696  50                   push eax
// 008a7697  ff1508b09800         call dword ptr [0x98b008]
// 008a769d  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgtempl.cpp (function ??1CDialogTemplate@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgtempl.cpp
