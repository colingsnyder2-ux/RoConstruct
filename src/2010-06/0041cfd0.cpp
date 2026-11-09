// from server: 100% by auto
// roc 2010-06 0041cfd0  unit: CSettingsExplorer  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041cfd0
//
// 0041cfd0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0041cfd3  50                   push eax
// 0041cfd4  ff1580bc9e00         call dword ptr [0x9ebc80]
// 0041cfda  50                   push eax
// 0041cfdb  e88aac3800           call 0x7a7c6a
// 0041cfe0  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
