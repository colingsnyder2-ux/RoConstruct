// from server: 100% by auto
// roc 2008-06 00459390  unit: CRobloxView  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459390
//
// 00459390  56                   push esi
// 00459391  8bf1                 mov esi, ecx
// 00459393  e8d0782400           call 0x6a0c68
// 00459398  8bce                 mov ecx, esi
// 0045939a  e811ffffff           call 0x4592b0
// 0045939f  5e                   pop esi
// 004593a0  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
