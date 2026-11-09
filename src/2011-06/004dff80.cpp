// from server: 100% by auto
// roc 2011-06 004dff80  unit: RBX::Network::VClient::?$FactoryProduct  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004dff80
//
// 004dff80  68b80b0000           push 0xbb8
// 004dff85  e846ffffff           call 0x4dfed0
// 004dff8a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ??__E_init_CMFCToolBarColorButton@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
