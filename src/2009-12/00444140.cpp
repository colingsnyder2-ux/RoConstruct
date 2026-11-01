// from server: 100% by auto
// roc 2009-12 00444140  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00444140
//
// 00444140  a17025b100           mov eax, dword ptr [0xb12570]
// 00444145  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxmem.cpp (function ?AfxGetNewHandler@@YGP6AHI@ZXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxmem.cpp
