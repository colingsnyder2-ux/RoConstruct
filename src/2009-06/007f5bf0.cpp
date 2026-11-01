// from server: 100% by auto
// roc 2009-06 007f5bf0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5bf0
//
// 007f5bf0  83793000             cmp dword ptr [ecx + 0x30], 0
// 007f5bf4  7511                 jne 0x7f5c07
// 007f5bf6  e825eff5ff           call 0x754b20
// 007f5bfb  8bc8                 mov ecx, eax
// 007f5bfd  e87ee9f5ff           call 0x754580
// 007f5c02  85c0                 test eax, eax
// 007f5c04  7501                 jne 0x7f5c07
// 007f5c06  c3                   ret 
// 007f5c07  b801000000           mov eax, 1
// 007f5c0c  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?IsLunaColorsDisabled@CXTPTabPaintManager@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
