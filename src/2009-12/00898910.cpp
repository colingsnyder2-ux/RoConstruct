// from server: 100% by auto
// roc 2009-12 00898910  unit: CXTPRibbonBar  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00898910
//
// 00898910  56                   push esi
// 00898911  8bf1                 mov esi, ecx
// 00898913  e8b8bbf6ff           call 0x8044d0
// 00898918  8bc8                 mov ecx, eax
// 0089891a  e8c1d5f7ff           call 0x815ee0
// 0089891f  33c0                 xor eax, eax
// 00898921  817c240888250000     cmp dword ptr [esp + 8], 0x2588
// 00898929  8bce                 mov ecx, esi
// 0089892b  0f94c0               sete al
// 0089892e  50                   push eax
// 0089892f  e82cf7ffff           call 0x898060
// 00898934  5e                   pop esi
// 00898935  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonBar.cpp (function ?OnCustomizePlaceQuickAccess@CXTPRibbonBar@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonBar.cpp
