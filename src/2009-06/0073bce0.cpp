// from server: 100% by auto
// roc 2009-06 0073bce0  unit: CXTPToolBar  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073bce0
//
// 0073bce0  837c240400           cmp dword ptr [esp + 4], 0
// 0073bce5  7405                 je 0x73bcec
// 0073bce7  33c0                 xor eax, eax
// 0073bce9  c20400               ret 4
// 0073bcec  e817d3fdff           call 0x719008
// 0073bcf1  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnNcActivate@CXTPPopupBar@@IAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
