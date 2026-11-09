// from server: 100% by auto
// roc 2012-06 00ae9cd0  unit: seg_00ae0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00ae9cd0
//
// 00ae9cd0  687c60d600           push 0xd6607c
// 00ae9cd5  e8c48de9ff           call 0x982a9e
// 00ae9cda  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
