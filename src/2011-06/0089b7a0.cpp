// from server: 100% by auto
// roc 2011-06 0089b7a0  unit: CXTPControlEdit  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089b7a0
//
// 0089b7a0  6800030000           push 0x300
// 0089b7a5  e8a634f7ff           call 0x80ec50
// 0089b7aa  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ??__E_init_CMFCToolBarColorButton@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
