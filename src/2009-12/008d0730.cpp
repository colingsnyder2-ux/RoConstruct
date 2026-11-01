// from server: 100% by auto
// roc 2009-12 008d0730  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0730
//
// 008d0730  837c240400           cmp dword ptr [esp + 4], 0
// 008d0735  8d8124010000         lea eax, [ecx + 0x124]
// 008d073b  7506                 jne 0x8d0743
// 008d073d  8d8114010000         lea eax, [ecx + 0x114]
// 008d0743  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?GetFont@CXTPTabPaintManager@@QAEPAVCFont@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
