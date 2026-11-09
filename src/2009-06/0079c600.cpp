// from server: 100% by auto
// roc 2009-06 0079c600  unit: CXTPControlGallery  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079c600
//
// 0079c600  6815100000           push 0x1015
// 0079c605  e84658f8ff           call 0x721e50
// 0079c60a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ??__E_init_CMFCToolBarColorButton@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
