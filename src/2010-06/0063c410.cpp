// from server: 100% by auto
// roc 2010-06 0063c410  unit: RBX::VPVInstance::?$NonFactoryProduct  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0063c410
//
// 0063c410  68f0b3c100           push 0xc1b3f0
// 0063c415  e85600ddff           call 0x40c470
// 0063c41a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
