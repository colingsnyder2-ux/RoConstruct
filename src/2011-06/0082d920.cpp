// from server: 100% by auto
// roc 2011-06 0082d920  unit: CXTPCommandBarsOptions  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082d920
//
// 0082d920  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0082d923  50                   push eax
// 0082d924  ff15e419a400         call dword ptr [0xa419e4]
// 0082d92a  50                   push eax
// 0082d92b  e888ec1900           call 0x9cc5b8
// 0082d930  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
