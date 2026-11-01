// from server: 100% by auto
// roc 2009-06 007f5b60  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5b60
//
// 007f5b60  837c240400           cmp dword ptr [esp + 4], 0
// 007f5b65  8d8124010000         lea eax, [ecx + 0x124]
// 007f5b6b  7506                 jne 0x7f5b73
// 007f5b6d  8d8114010000         lea eax, [ecx + 0x114]
// 007f5b73  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?GetFont@CXTPTabPaintManager@@QAEPAVCFont@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
