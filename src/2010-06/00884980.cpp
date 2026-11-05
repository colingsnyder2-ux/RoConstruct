// from server: 100% by auto
// roc 2010-06 00884980  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884980
//
// 00884980  83793000             cmp dword ptr [ecx + 0x30], 0
// 00884984  7511                 jne 0x884997
// 00884986  e895f1f5ff           call 0x7e3b20
// 0088498b  8bc8                 mov ecx, eax
// 0088498d  e86e03e3ff           call 0x6b4d00
// 00884992  85c0                 test eax, eax
// 00884994  7501                 jne 0x884997
// 00884996  c3                   ret 
// 00884997  b801000000           mov eax, 1
// 0088499c  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?IsLunaColorsDisabled@CXTPTabPaintManager@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
