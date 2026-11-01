// from server: 100% by auto
// roc 2009-06 007f3740  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f3740
//
// 007f3740  8b442404             mov eax, dword ptr [esp + 4]
// 007f3744  8b403c               mov eax, dword ptr [eax + 0x3c]
// 007f3747  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetItemIcon@CXTPTabManager@@UBEPAUHICON__@@PBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
