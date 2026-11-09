// from server: 100% by auto
// roc 2008-06 007ef920  unit: seg_007e0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007ef920
//
// 007ef920  68341c9300           push 0x931c34
// 007ef925  e85c16ebff           call 0x6a0f86
// 007ef92a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
