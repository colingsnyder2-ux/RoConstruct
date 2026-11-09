// from server: 100% by auto
// roc 2009-06 00611ca0  unit: RBX::ModelInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00611ca0
//
// 00611ca0  68401c6100           push 0x611c40
// 00611ca5  e8f6a5e4ff           call 0x45c2a0
// 00611caa  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
