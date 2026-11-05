// from server: 100% by auto
// roc 2010-06 007cbf20  unit: CXTPCommandBarsOptions  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cbf20
//
// 007cbf20  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007cbf23  50                   push eax
// 007cbf24  ff1570ba9e00         call dword ptr [0x9eba70]
// 007cbf2a  50                   push eax
// 007cbf2b  e83c0e1b00           call 0x97cd6c
// 007cbf30  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
