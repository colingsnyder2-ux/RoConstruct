// from server: 100% by auto
// roc 2009-06 00776d30  unit: CXTPPropExchange  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00776d30
//
// 00776d30  6aff                 push -1
// 00776d32  68946ea200           push 0xa26e94
// 00776d37  68d8bf8f00           push 0x8fbfd8
// 00776d3c  51                   push ecx
// 00776d3d  e85eefffff           call 0x775ca0
// 00776d42  83c410               add esp, 0x10
// 00776d45  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?ExchangeLocale@CXTPPropExchange@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
