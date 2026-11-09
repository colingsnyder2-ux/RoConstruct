// from server: 100% by auto
// roc 2010-06 007c6e90  unit: CXTPToolBar  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c6e90
//
// 007c6e90  837c240400           cmp dword ptr [esp + 4], 0
// 007c6e95  7405                 je 0x7c6e9c
// 007c6e97  33c0                 xor eax, eax
// 007c6e99  c20400               ret 4
// 007c6e9c  e8cf10feff           call 0x7a7f70
// 007c6ea1  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnNcActivate@CXTPPopupBar@@IAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPopupBar.cpp
