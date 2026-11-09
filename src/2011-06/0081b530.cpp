// from server: 100% by auto
// roc 2011-06 0081b530  unit: CXTPCommandBar  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0081b530
//
// 0081b530  56                   push esi
// 0081b531  8bf1                 mov esi, ecx
// 0081b533  e8a8ffffff           call 0x81b4e0
// 0081b538  8bce                 mov ecx, esi
// 0081b53a  e8eff0feff           call 0x80a62e
// 0081b53f  5e                   pop esi
// 0081b540  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
