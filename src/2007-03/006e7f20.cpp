// from server: 100% by auto
// roc 2007-03 006e7f20  unit: seg_006e0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7f20
//
// 006e7f20  56                   push esi
// 006e7f21  8b742408             mov esi, dword ptr [esp + 8]
// 006e7f25  6a00                 push 0
// 006e7f27  56                   push esi
// 006e7f28  ff1550ed7700         call dword ptr [0x77ed50]
// 006e7f2e  8bc6                 mov eax, esi
// 006e7f30  5e                   pop esi
// 006e7f31  c21c00               ret 0x1c
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?FillTabControl@CAppearanceSet@CXTPTabPaintManager@@UAE?AVCRect@@PAVCXTPTabManager@@PAVCDC@@V3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
