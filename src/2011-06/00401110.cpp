// from server: 100% by auto
// roc 2011-06 00401110  unit: CRobloxWnd  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00401110
//
// 00401110  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00401113  6a01                 push 1
// 00401115  50                   push eax
// 00401116  ff15b019a400         call dword ptr [0xa419b0]
// 0040111c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?EndModalState@CWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
