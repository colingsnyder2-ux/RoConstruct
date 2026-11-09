// from server: 100% by auto
// roc 2009-06 0072de30  unit: CXTPCommandBar  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072de30
//
// 0072de30  56                   push esi
// 0072de31  8bf1                 mov esi, ecx
// 0072de33  e8a8ffffff           call 0x72dde0
// 0072de38  8bce                 mov ecx, esi
// 0072de3a  e8c9b1feff           call 0x719008
// 0072de3f  5e                   pop esi
// 0072de40  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
