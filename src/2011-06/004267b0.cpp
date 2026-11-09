// from server: 100% by auto
// roc 2011-06 004267b0  unit: CInstanceExplorer  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004267b0
//
// 004267b0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 004267b3  50                   push eax
// 004267b4  ff15341ba400         call dword ptr [0xa41b34]
// 004267ba  50                   push eax
// 004267bb  e8683b3e00           call 0x80a328
// 004267c0  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
