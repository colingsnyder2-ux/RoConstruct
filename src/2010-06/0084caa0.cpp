// from server: 100% by auto
// roc 2010-06 0084caa0  unit: CXTPRibbonBar  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084caa0
//
// 0084caa0  56                   push esi
// 0084caa1  8bf1                 mov esi, ecx
// 0084caa3  e828bbf6ff           call 0x7b85d0
// 0084caa8  8bc8                 mov ecx, eax
// 0084caaa  e801d5f7ff           call 0x7c9fb0
// 0084caaf  33c0                 xor eax, eax
// 0084cab1  817c240888250000     cmp dword ptr [esp + 8], 0x2588
// 0084cab9  8bce                 mov ecx, esi
// 0084cabb  0f94c0               sete al
// 0084cabe  50                   push eax
// 0084cabf  e82cf7ffff           call 0x84c1f0
// 0084cac4  5e                   pop esi
// 0084cac5  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonBar.cpp (function ?OnCustomizePlaceQuickAccess@CXTPRibbonBar@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonBar.cpp
