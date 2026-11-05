// from server: 100% by auto
// roc 2012-06 00757e30  unit: RBX::PartInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00757e30
//
// 00757e30  686862e300           push 0xe36268
// 00757e35  e866cfcbff           call 0x414da0
// 00757e3a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
