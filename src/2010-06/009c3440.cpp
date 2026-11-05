// from server: 100% by auto
// roc 2010-06 009c3440  unit: seg_009c0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c3440
//
// 009c3440  68d4dab700           push 0xb7dad4
// 009c3445  e8164fdeff           call 0x7a8360
// 009c344a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
