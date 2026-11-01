// from server: 100% by auto
// roc 2009-06 0077f920  unit: CXTPStatusBar  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f920
//
// 0077f920  56                   push esi
// 0077f921  8bf1                 mov esi, ecx
// 0077f923  e8e096f9ff           call 0x719008
// 0077f928  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0077f92c  898eac000000         mov dword ptr [esi + 0xac], ecx
// 0077f932  5e                   pop esi
// 0077f933  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPStatusBar.cpp (function ?OnSetMinHeight@CXTPStatusBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPStatusBar.cpp
