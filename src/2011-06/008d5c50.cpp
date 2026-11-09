// from server: 100% by auto
// roc 2011-06 008d5c50  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d5c50
//
// 008d5c50  56                   push esi
// 008d5c51  8b742408             mov esi, dword ptr [esp + 8]
// 008d5c55  6a00                 push 0
// 008d5c57  56                   push esi
// 008d5c58  ff15681ca400         call dword ptr [0xa41c68]
// 008d5c5e  8bc6                 mov eax, esi
// 008d5c60  5e                   pop esi
// 008d5c61  c21c00               ret 0x1c
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?FillTabControl@CAppearanceSet@CXTPTabPaintManager@@UAE?AVCRect@@PAVCXTPTabManager@@PAVCDC@@V3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
