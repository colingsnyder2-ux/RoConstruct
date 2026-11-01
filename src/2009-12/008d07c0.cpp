// from server: 100% by auto
// roc 2009-12 008d07c0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d07c0
//
// 008d07c0  83793000             cmp dword ptr [ecx + 0x30], 0
// 008d07c4  7511                 jne 0x8d07d7
// 008d07c6  e805f2f5ff           call 0x82f9d0
// 008d07cb  8bc8                 mov ecx, eax
// 008d07cd  e80eecf5ff           call 0x82f3e0
// 008d07d2  85c0                 test eax, eax
// 008d07d4  7501                 jne 0x8d07d7
// 008d07d6  c3                   ret 
// 008d07d7  b801000000           mov eax, 1
// 008d07dc  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?IsLunaColorsDisabled@CXTPTabPaintManager@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
