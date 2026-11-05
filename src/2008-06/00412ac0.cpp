// from server: 100% by auto
// roc 2008-06 00412ac0  unit: CChatPrompt  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00412ac0
//
// 00412ac0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00412ac3  50                   push eax
// 00412ac4  ff15f82d8000         call dword ptr [0x802df8]
// 00412aca  50                   push eax
// 00412acb  e80ee12800           call 0x6a0bde
// 00412ad0  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
