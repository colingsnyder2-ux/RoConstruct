// from server: 100% by auto
// roc 2011-06 00a170d0  unit: seg_00a10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a170d0
//
// 00a170d0  681852c100           push 0xc15218
// 00a170d5  e84439dfff           call 0x80aa1e
// 00a170da  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
