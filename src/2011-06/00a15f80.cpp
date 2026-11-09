// from server: 100% by auto
// roc 2011-06 00a15f80  unit: seg_00a10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a15f80
//
// 00a15f80  6854d3c000           push 0xc0d354
// 00a15f85  e8944adfff           call 0x80aa1e
// 00a15f8a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
