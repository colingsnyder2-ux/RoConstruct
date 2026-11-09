// from server: 100% by auto
// roc 2009-12 00512380  unit: boost::detail::thread_data_base  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00512380
//
// 00512380  a1fc00b800           mov eax, dword ptr [0xb800fc]
// 00512385  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxmem.cpp (function ?AfxGetNewHandler@@YGP6AHI@ZXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxmem.cpp
