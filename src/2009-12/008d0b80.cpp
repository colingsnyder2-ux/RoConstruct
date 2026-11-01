// from server: 100% by auto
// roc 2009-12 008d0b80  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0b80
//
// 008d0b80  56                   push esi
// 008d0b81  8b742408             mov esi, dword ptr [esp + 8]
// 008d0b85  6a00                 push 0
// 008d0b87  56                   push esi
// 008d0b88  ff1564cc9800         call dword ptr [0x98cc64]
// 008d0b8e  8bc6                 mov eax, esi
// 008d0b90  5e                   pop esi
// 008d0b91  c21c00               ret 0x1c
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?FillTabControl@CAppearanceSet@CXTPTabPaintManager@@UAE?AVCRect@@PAVCXTPTabManager@@PAVCDC@@V3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
