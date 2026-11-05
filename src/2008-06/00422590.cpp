// from server: 100% by auto
// roc 2008-06 00422590  unit: CSettingsExplorer  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00422590
//
// 00422590  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00422593  50                   push eax
// 00422594  ff15a82d8000         call dword ptr [0x802da8]
// 0042259a  50                   push eax
// 0042259b  e83ee62700           call 0x6a0bde
// 004225a0  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
