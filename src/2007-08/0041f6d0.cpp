// from server: 100% by auto
// roc 2007-08 0041f6d0  unit: CSettingsExplorer  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041f6d0
//
// 0041f6d0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0041f6d3  50                   push eax
// 0041f6d4  ff1548ec7700         call dword ptr [0x77ec48]
// 0041f6da  50                   push eax
// 0041f6db  e8e00a2100           call 0x6301c0
// 0041f6e0  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
