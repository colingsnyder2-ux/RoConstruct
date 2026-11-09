// from server: 100% by auto
// roc 2008-06 00401130  unit: CRobloxWnd  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401130
//
// 00401130  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00401133  6a01                 push 1
// 00401135  50                   push eax
// 00401136  ff15302e8000         call dword ptr [0x802e30]
// 0040113c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?EndModalState@CWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
