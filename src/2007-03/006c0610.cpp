// from server: 100% by auto
// roc 2007-03 006c0610  unit: seg_006c0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c0610
//
// 006c0610  8b01                 mov eax, dword ptr [ecx]
// 006c0612  85c0                 test eax, eax
// 006c0614  7407                 je 0x6c061d
// 006c0616  50                   push eax
// 006c0617  ff152cd07700         call dword ptr [0x77d02c]
// 006c061d  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgtempl.cpp (function ??1CDialogTemplate@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgtempl.cpp
