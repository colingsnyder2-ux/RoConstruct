// from server: 100% by auto
// roc 2009-12 00401110  unit: CRobloxWnd  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00401110
//
// 00401110  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00401113  6a01                 push 1
// 00401115  50                   push eax
// 00401116  ff15b4cb9800         call dword ptr [0x98cbb4]
// 0040111c  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?EndModalState@CWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
