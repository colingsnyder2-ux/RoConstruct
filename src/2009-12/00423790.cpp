// from server: 100% by auto
// roc 2009-12 00423790  unit: RobloxCrashReporter  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00423790
//
// 00423790  a160a2b700           mov eax, dword ptr [0xb7a260]
// 00423795  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxmem.cpp (function ?AfxGetNewHandler@@YGP6AHI@ZXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxmem.cpp
