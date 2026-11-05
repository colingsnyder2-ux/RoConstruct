// from server: 100% by auto
// roc 2010-06 0083e770  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0083e770
//
// 0083e770  6800030000           push 0x300
// 0083e775  e8f6dff6ff           call 0x7ac770
// 0083e77a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ??__E_init_CMFCToolBarColorButton@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
