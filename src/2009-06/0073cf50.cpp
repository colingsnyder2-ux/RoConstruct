// from server: 100% by auto
// roc 2009-06 0073cf50  unit: CXTPToolBar  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073cf50
//
// 0073cf50  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0073cf53  50                   push eax
// 0073cf54  ff1550ed8900         call dword ptr [0x89ed50]
// 0073cf5a  50                   push eax
// 0073cf5b  e8acef1000           call 0x84bf0c
// 0073cf60  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
