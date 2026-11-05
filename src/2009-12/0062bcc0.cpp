// from server: 100% by auto
// roc 2009-12 0062bcc0  unit: seg_00620000  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0062bcc0
//
// 0062bcc0  a1e84ab600           mov eax, dword ptr [0xb64ae8]
// 0062bcc5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxmem.cpp (function ?AfxGetNewHandler@@YGP6AHI@ZXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxmem.cpp
