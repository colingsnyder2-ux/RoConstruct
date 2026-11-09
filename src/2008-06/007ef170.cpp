// from server: 100% by auto
// roc 2008-06 007ef170  unit: seg_007e0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007ef170
//
// 007ef170  68c8ec9200           push 0x92ecc8
// 007ef175  e80c1eebff           call 0x6a0f86
// 007ef17a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
