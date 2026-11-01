// from server: 100% by auto
// roc 2009-06 007d60f0  unit: CXTPDockingPaneTabbedContainer  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d60f0
//
// 007d60f0  68f0240000           push 0x24f0
// 007d60f5  83c154               add ecx, 0x54
// 007d60f8  e803fdffff           call 0x7d5e00
// 007d60fd  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetPinButton@CXTPDockingPaneTabbedContainer@@QBEPAVCXTPDockingPaneCaptionButton@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
