// from server: 100% by auto
// roc 2009-06 0071b960  unit: CPatchedControlComboBox  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071b960
//
// 0071b960  8b01                 mov eax, dword ptr [ecx]
// 0071b962  ffa030020000         jmp dword ptr [eax + 0x230]
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanager.cpp (function ?OnDrawRibbonMainPanelButtonBorder@CMFCVisualManager@@UAEXPAVCDC@@PAVCMFCRibbonButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanager.cpp
