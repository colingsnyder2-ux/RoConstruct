// from server: 100% by auto
// roc 2007-08 00644430  unit: CXTPCommandBar  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00644430
//
// 00644430  56                   push esi
// 00644431  8bf1                 mov esi, ecx
// 00644433  e8a8ffffff           call 0x6443e0
// 00644438  8bce                 mov ecx, esi
// 0064443a  e8ffbdfeff           call 0x63023e
// 0064443f  5e                   pop esi
// 00644440  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
