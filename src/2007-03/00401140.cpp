// from server: 100% by auto
// roc 2007-03 00401140  unit: seg_00400000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401140
//
// 00401140  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00401143  6a01                 push 1
// 00401145  50                   push eax
// 00401146  ff1568ee7700         call dword ptr [0x77ee68]
// 0040114c  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?EndModalState@CWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
