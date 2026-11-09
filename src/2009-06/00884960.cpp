// from server: 100% by auto
// roc 2009-06 00884960  unit: seg_00880000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00884960
//
// 00884960  68bc099e00           push 0x9e09bc
// 00884965  e88e4ae9ff           call 0x7193f8
// 0088496a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
