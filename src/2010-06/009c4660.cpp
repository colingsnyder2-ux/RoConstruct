// from server: 100% by auto
// roc 2010-06 009c4660  unit: seg_009c0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c4660
//
// 009c4660  683826b800           push 0xb82638
// 009c4665  e8f63cdeff           call 0x7a8360
// 009c466a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
