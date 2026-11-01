// from server: 100% by auto
// roc 2007-03 006397c0  unit: seg_00630000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006397c0
//
// 006397c0  56                   push esi
// 006397c1  8bf1                 mov esi, ecx
// 006397c3  e8a8ffffff           call 0x639770
// 006397c8  8bce                 mov ecx, esi
// 006397ca  e8034ffeff           call 0x61e6d2
// 006397cf  5e                   pop esi
// 006397d0  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
