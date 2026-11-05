// from server: 100% by auto
// roc 2008-06 006c4990  unit: CXTPToolBar  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006c4990
//
// 006c4990  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006c4993  50                   push eax
// 006c4994  ff15cc2c8000         call dword ptr [0x802ccc]
// 006c499a  50                   push eax
// 006c499b  e888760f00           call 0x7bc028
// 006c49a0  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
