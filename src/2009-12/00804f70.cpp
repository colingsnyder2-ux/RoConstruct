// from server: 100% by auto
// roc 2009-12 00804f70  unit: CXTPCommandBar  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00804f70
//
// 00804f70  56                   push esi
// 00804f71  8bf1                 mov esi, ecx
// 00804f73  e8a8ffffff           call 0x804f20
// 00804f78  8bce                 mov ecx, esi
// 00804f7a  e8b1eefeff           call 0x7f3e30
// 00804f7f  5e                   pop esi
// 00804f80  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
