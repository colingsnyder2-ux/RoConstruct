// from server: 100% by auto
// roc 2010-06 00464d60  unit: CRobloxView  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00464d60
//
// 00464d60  56                   push esi
// 00464d61  8bf1                 mov esi, ecx
// 00464d63  e808323400           call 0x7a7f70
// 00464d68  8bce                 mov ecx, esi
// 00464d6a  e811ffffff           call 0x464c80
// 00464d6f  5e                   pop esi
// 00464d70  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
