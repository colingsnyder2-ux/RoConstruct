// from server: 100% by auto
// roc 2009-12 008b0c30  unit: CXTPDockingPaneTabbedContainer  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b0c30
//
// 008b0c30  68f0240000           push 0x24f0
// 008b0c35  83c154               add ecx, 0x54
// 008b0c38  e803fdffff           call 0x8b0940
// 008b0c3d  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetPinButton@CXTPDockingPaneTabbedContainer@@QBEPAVCXTPDockingPaneCaptionButton@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
