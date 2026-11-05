// from server: 100% by auto
// roc 2007-08 006d73b0  unit: CXTMemDC  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d73b0
//
// 006d73b0  8b01                 mov eax, dword ptr [ecx]
// 006d73b2  85c0                 test eax, eax
// 006d73b4  7407                 je 0x6d73bd
// 006d73b6  50                   push eax
// 006d73b7  ff1508d07700         call dword ptr [0x77d008]
// 006d73bd  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgtempl.cpp (function ??1CDialogTemplate@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgtempl.cpp
