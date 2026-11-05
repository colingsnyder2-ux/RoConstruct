// from server: 100% by auto
// roc 2009-06 00457ec0  unit: CRobloxView  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00457ec0
//
// 00457ec0  56                   push esi
// 00457ec1  8bf1                 mov esi, ecx
// 00457ec3  e840112c00           call 0x719008
// 00457ec8  8bce                 mov ecx, esi
// 00457eca  e811ffffff           call 0x457de0
// 00457ecf  5e                   pop esi
// 00457ed0  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
