// from server: 100% by auto
// roc 2007-08 00401130  unit: CRobloxWnd  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401130
//
// 00401130  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00401133  6a01                 push 1
// 00401135  50                   push eax
// 00401136  ff15f8ec7700         call dword ptr [0x77ecf8]
// 0040113c  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?EndModalState@CWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
