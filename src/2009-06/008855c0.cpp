// from server: 100% by auto
// roc 2009-06 008855c0  unit: seg_00880000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008855c0
//
// 008855c0  68f04c9e00           push 0x9e4cf0
// 008855c5  e82e3ee9ff           call 0x7193f8
// 008855ca  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
