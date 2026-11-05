// from server: 100% by auto
// roc 2010-06 00884d30  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884d30
//
// 00884d30  56                   push esi
// 00884d31  8b742408             mov esi, dword ptr [esp + 8]
// 00884d35  6a00                 push 0
// 00884d37  56                   push esi
// 00884d38  ff1548bc9e00         call dword ptr [0x9ebc48]
// 00884d3e  8bc6                 mov eax, esi
// 00884d40  5e                   pop esi
// 00884d41  c21c00               ret 0x1c
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?FillTabControl@CAppearanceSet@CXTPTabPaintManager@@UAE?AVCRect@@PAVCXTPTabManager@@PAVCDC@@V3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
