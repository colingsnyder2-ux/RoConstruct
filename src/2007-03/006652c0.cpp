// from server: 100% by auto
// roc 2007-03 006652c0  unit: seg_00660000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006652c0
//
// 006652c0  837c240400           cmp dword ptr [esp + 4], 0
// 006652c5  7405                 je 0x6652cc
// 006652c7  33c0                 xor eax, eax
// 006652c9  c20400               ret 4
// 006652cc  e80194fbff           call 0x61e6d2
// 006652d1  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnNcActivate@CXTPPopupBar@@IAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
