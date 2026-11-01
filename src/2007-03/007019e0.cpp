// from server: 100% by auto
// roc 2007-03 007019e0  unit: seg_00700000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007019e0
//
// 007019e0  8b01                 mov eax, dword ptr [ecx]
// 007019e2  85c0                 test eax, eax
// 007019e4  7407                 je 0x7019ed
// 007019e6  50                   push eax
// 007019e7  ff159cd27700         call dword ptr [0x77d29c]
// 007019ed  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgtempl.cpp (function ??1CDialogTemplate@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgtempl.cpp
