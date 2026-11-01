// from server: 100% by auto
// roc 2007-03 006c9910  unit: seg_006c0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c9910
//
// 006c9910  68f0240000           push 0x24f0
// 006c9915  83c154               add ecx, 0x54
// 006c9918  e8f3fcffff           call 0x6c9610
// 006c991d  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetPinButton@CXTPDockingPaneTabbedContainer@@QBEPAVCXTPDockingPaneCaptionButton@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
