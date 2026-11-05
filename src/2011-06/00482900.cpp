// from server: 100% by auto
// roc 2011-06 00482900  unit: HelpCommand  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00482900
//
// 00482900  56                   push esi
// 00482901  8bf1                 mov esi, ecx
// 00482903  e8267d3800           call 0x80a62e
// 00482908  8bce                 mov ecx, esi
// 0048290a  e811ffffff           call 0x482820
// 0048290f  5e                   pop esi
// 00482910  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
