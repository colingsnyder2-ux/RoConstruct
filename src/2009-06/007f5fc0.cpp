// from server: 100% by auto
// roc 2009-06 007f5fc0  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5fc0
//
// 007f5fc0  56                   push esi
// 007f5fc1  8b742408             mov esi, dword ptr [esp + 8]
// 007f5fc5  6a00                 push 0
// 007f5fc7  56                   push esi
// 007f5fc8  ff1500ee8900         call dword ptr [0x89ee00]
// 007f5fce  8bc6                 mov eax, esi
// 007f5fd0  5e                   pop esi
// 007f5fd1  c21c00               ret 0x1c
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?FillTabControl@CAppearanceSet@CXTPTabPaintManager@@UAE?AVCRect@@PAVCXTPTabManager@@PAVCDC@@V3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
