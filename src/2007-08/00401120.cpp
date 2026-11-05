// from server: 100% by auto
// roc 2007-08 00401120  unit: CRobloxWnd  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401120
//
// 00401120  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00401123  6a00                 push 0
// 00401125  50                   push eax
// 00401126  ff15f8ec7700         call dword ptr [0x77ecf8]
// 0040112c  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?BeginModalState@CWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
