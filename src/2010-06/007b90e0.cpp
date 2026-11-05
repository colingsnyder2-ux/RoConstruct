// from server: 100% by auto
// roc 2010-06 007b90e0  unit: CXTPCommandBar  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b90e0
//
// 007b90e0  56                   push esi
// 007b90e1  8bf1                 mov esi, ecx
// 007b90e3  e8a8ffffff           call 0x7b9090
// 007b90e8  8bce                 mov ecx, esi
// 007b90ea  e881eefeff           call 0x7a7f70
// 007b90ef  5e                   pop esi
// 007b90f0  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
