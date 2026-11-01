// from server: 100% by auto
// roc 2009-12 0086e0c0  unit: CXTPResourceManager  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e0c0
//
// 0086e0c0  a1c8bab900           mov eax, dword ptr [0xb9bac8]
// 0086e0c5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxmem.cpp (function ?AfxGetNewHandler@@YGP6AHI@ZXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxmem.cpp
