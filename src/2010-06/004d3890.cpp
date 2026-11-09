// from server: 100% by auto
// roc 2010-06 004d3890  unit: RBX::Network::VClient::?$FactoryProduct  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004d3890
//
// 004d3890  68b80b0000           push 0xbb8
// 004d3895  e876ffffff           call 0x4d3810
// 004d389a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ??__E_init_CMFCToolBarColorButton@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
