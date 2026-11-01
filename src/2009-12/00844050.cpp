// from server: 100% by auto
// roc 2009-12 00844050  unit: CXTPPopupBar  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00844050
//
// 00844050  837c240400           cmp dword ptr [esp + 4], 0
// 00844055  7405                 je 0x84405c
// 00844057  33c0                 xor eax, eax
// 00844059  c20400               ret 4
// 0084405c  e8cffdfaff           call 0x7f3e30
// 00844061  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnNcActivate@CXTPPopupBar@@IAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
