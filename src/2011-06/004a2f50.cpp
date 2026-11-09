// from server: 100% by auto
// roc 2011-06 004a2f50  unit: CSourceStream  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004a2f50
//
// 004a2f50  8b01                 mov eax, dword ptr [ecx]
// 004a2f52  85c0                 test eax, eax
// 004a2f54  7407                 je 0x4a2f5d
// 004a2f56  50                   push eax
// 004a2f57  ff157c03a400         call dword ptr [0xa4037c]
// 004a2f5d  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgtempl.cpp (function ??1CDialogTemplate@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgtempl.cpp
