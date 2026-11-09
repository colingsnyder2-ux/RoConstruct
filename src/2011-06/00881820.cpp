// from server: 100% by auto
// roc 2011-06 00881820  unit: CXTPControlGallery  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00881820
//
// 00881820  6815100000           push 0x1015
// 00881825  e826d4f8ff           call 0x80ec50
// 0088182a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ??__E_init_CMFCToolBarColorButton@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
