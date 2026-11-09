// from server: 100% by auto
// roc 2007-03 00453530  unit: seg_00450000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00453530
//
// 00453530  56                   push esi
// 00453531  8bf1                 mov esi, ecx
// 00453533  e89ab11c00           call 0x61e6d2
// 00453538  8bce                 mov ecx, esi
// 0045353a  e811ffffff           call 0x453450
// 0045353f  5e                   pop esi
// 00453540  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
