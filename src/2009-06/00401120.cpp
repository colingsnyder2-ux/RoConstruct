// from server: 100% by auto
// roc 2009-06 00401120  unit: CRobloxWnd  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401120
//
// 00401120  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00401123  6a01                 push 1
// 00401125  50                   push eax
// 00401126  ff15a0ee8900         call dword ptr [0x89eea0]
// 0040112c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?EndModalState@CWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
