// from server: 100% by auto
// roc 2012-06 00aeb530  unit: seg_00ae0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeb530
//
// 00aeb530  6864d4d600           push 0xd6d464
// 00aeb535  e86475e9ff           call 0x982a9e
// 00aeb53a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
