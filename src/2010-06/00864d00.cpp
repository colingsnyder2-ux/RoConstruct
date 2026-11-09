// from server: 100% by auto
// roc 2010-06 00864d00  unit: CXTPDockingPaneTabbedContainer  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00864d00
//
// 00864d00  68f0240000           push 0x24f0
// 00864d05  83c154               add ecx, 0x54
// 00864d08  e803fdffff           call 0x864a10
// 00864d0d  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetPinButton@CXTPDockingPaneTabbedContainer@@QBEPAVCXTPDockingPaneCaptionButton@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
