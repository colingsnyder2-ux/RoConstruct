// from server: 100% by auto
// roc 2008-06 0072df70  unit: CXTPControlGallery  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0072df70
//
// 0072df70  6815100000           push 0x1015
// 0072df75  e8c6f7f7ff           call 0x6ad740
// 0072df7a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ??__E_init_CMFCToolBarColorButton@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
