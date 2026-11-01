// from server: 100% by auto
// roc 2009-06 007bb6f0  unit: CXTPRibbonBar  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bb6f0
//
// 007bb6f0  56                   push esi
// 007bb6f1  8bf1                 mov esi, ecx
// 007bb6f3  e8981cf7ff           call 0x72d390
// 007bb6f8  8bc8                 mov ecx, eax
// 007bb6fa  e831fbf6ff           call 0x72b230
// 007bb6ff  33c0                 xor eax, eax
// 007bb701  817c240888250000     cmp dword ptr [esp + 8], 0x2588
// 007bb709  8bce                 mov ecx, esi
// 007bb70b  0f94c0               sete al
// 007bb70e  50                   push eax
// 007bb70f  e82cf7ffff           call 0x7bae40
// 007bb714  5e                   pop esi
// 007bb715  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonBar.cpp (function ?OnCustomizePlaceQuickAccess@CXTPRibbonBar@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonBar.cpp
