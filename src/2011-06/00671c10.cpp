// from server: 100% by auto
// roc 2011-06 00671c10  unit: RBX::VBasicPartInstance::?$ActionStation  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00671c10
//
// 00671c10  68c0e2cc00           push 0xcce2c0
// 00671c15  e84603daff           call 0x411f60
// 00671c1a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
