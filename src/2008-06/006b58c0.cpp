// from server: 100% by auto
// roc 2008-06 006b58c0  unit: CXTPCommandBar  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006b58c0
//
// 006b58c0  56                   push esi
// 006b58c1  8bf1                 mov esi, ecx
// 006b58c3  e8a8ffffff           call 0x6b5870
// 006b58c8  8bce                 mov ecx, esi
// 006b58ca  e899b3feff           call 0x6a0c68
// 006b58cf  5e                   pop esi
// 006b58d0  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
