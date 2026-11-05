// from server: 100% by auto
// roc 2010-06 007b4810  unit: CPatchedControlComboBox  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4810
//
// 007b4810  8b01                 mov eax, dword ptr [ecx]
// 007b4812  ffa030020000         jmp dword ptr [eax + 0x230]
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanager.cpp (function ?OnDrawRibbonMainPanelButtonBorder@CMFCVisualManager@@UAEXPAVCDC@@PAVCMFCRibbonButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanager.cpp
