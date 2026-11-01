// from server: 100% by auto
// roc 2009-12 0045f750  unit: CRobloxView  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0045f750
//
// 0045f750  56                   push esi
// 0045f751  8bf1                 mov esi, ecx
// 0045f753  e8d8463900           call 0x7f3e30
// 0045f758  8bce                 mov ecx, esi
// 0045f75a  e811ffffff           call 0x45f670
// 0045f75f  5e                   pop esi
// 0045f760  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
