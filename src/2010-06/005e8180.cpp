// from server: 100% by auto
// roc 2010-06 005e8180  unit: RBX::ModelInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e8180
//
// 005e8180  6820815e00           push 0x5e8120
// 005e8185  e8c60ae8ff           call 0x468c50
// 005e818a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
