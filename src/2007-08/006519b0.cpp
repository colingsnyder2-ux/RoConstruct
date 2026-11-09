// from server: 100% by auto
// roc 2007-08 006519b0  unit: CXTPToolBar  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006519b0
//
// 006519b0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006519b3  50                   push eax
// 006519b4  ff1530ed7700         call dword ptr [0x77ed30]
// 006519ba  50                   push eax
// 006519bb  e8fe690e00           call 0x7383be
// 006519c0  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
