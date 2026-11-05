// from server: 100% by auto
// roc 2010-06 009c45f0  unit: seg_009c0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c45f0
//
// 009c45f0  68f025b800           push 0xb825f0
// 009c45f5  e8663ddeff           call 0x7a8360
// 009c45fa  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
