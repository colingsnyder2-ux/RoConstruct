// from server: 100% by auto
// roc 2010-06 005e81f0  unit: RBX::ModelInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e81f0
//
// 005e81f0  6890815e00           push 0x5e8190
// 005e81f5  e8560ae8ff           call 0x468c50
// 005e81fa  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
