// from server: 100% by auto
// roc 2010-06 00824780  unit: CXTPControlGallery  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00824780
//
// 00824780  6815100000           push 0x1015
// 00824785  e8e67ff8ff           call 0x7ac770
// 0082478a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ??__E_init_CMFCToolBarColorButton@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
