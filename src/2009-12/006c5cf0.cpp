// from server: 100% by auto
// roc 2009-12 006c5cf0  unit: std::D::DU?$char_traits::?$basic_istringstream  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c5cf0
//
// 006c5cf0  a19c58b900           mov eax, dword ptr [0xb9589c]
// 006c5cf5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxmem.cpp (function ?AfxGetNewHandler@@YGP6AHI@ZXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxmem.cpp
