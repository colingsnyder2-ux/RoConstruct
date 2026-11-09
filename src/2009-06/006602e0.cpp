// from server: 100% by auto
// roc 2009-06 006602e0  unit: RBX::VPVInstance::?$NonFactoryProduct  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006602e0
//
// 006602e0  681ccfa400           push 0xa4cf1c
// 006602e5  e8e6bfdaff           call 0x40c2d0
// 006602ea  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli3.cpp (function ?GetClientSite@COleClientItem@@MAEPAUIOleClientSite@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli3.cpp
