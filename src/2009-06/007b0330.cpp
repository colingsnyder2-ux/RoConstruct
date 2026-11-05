// from server: 100% by auto
// roc 2009-06 007b0330  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b0330
//
// 007b0330  6800030000           push 0x300
// 007b0335  e8161bf7ff           call 0x721e50
// 007b033a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ??__E_init_CMFCToolBarColorButton@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
