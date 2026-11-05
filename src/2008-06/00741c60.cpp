// from server: 100% by auto
// roc 2008-06 00741c60  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00741c60
//
// 00741c60  6800030000           push 0x300
// 00741c65  e8d6baf6ff           call 0x6ad740
// 00741c6a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ??__E_init_CMFCToolBarColorButton@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
