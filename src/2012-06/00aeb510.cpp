// from server: 100% by auto
// roc 2012-06 00aeb510  unit: seg_00ae0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeb510
//
// 00aeb510  681cd4d600           push 0xd6d41c
// 00aeb515  e88475e9ff           call 0x982a9e
// 00aeb51a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
