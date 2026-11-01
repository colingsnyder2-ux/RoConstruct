// from server: 100% by auto
// roc 2009-12 0041d0f0  unit: CSettingsExplorer  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041d0f0
//
// 0041d0f0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0041d0f3  50                   push eax
// 0041d0f4  ff152ccc9800         call dword ptr [0x98cc2c]
// 0041d0fa  50                   push eax
// 0041d0fb  e82a6a3d00           call 0x7f3b2a
// 0041d100  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
