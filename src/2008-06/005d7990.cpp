// from server: 100% by auto
// roc 2008-06 005d7990  unit: CXTPReportControl  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d7990
//
// 005d7990  8b442404             mov eax, dword ptr [esp + 4]
// 005d7994  50                   push eax
// 005d7995  e80633ecff           call 0x49aca0
// 005d799a  83c404               add esp, 4
// 005d799d  89442404             mov dword ptr [esp + 4], eax
// 005d79a1  e9fafbffff           jmp 0x5d75a0
// library mfc-9.0/atlmfc\src\mfc\filetxt.cpp (function ?Afx_clearerr_s@@YAXPAU_iobuf@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/filetxt.cpp
