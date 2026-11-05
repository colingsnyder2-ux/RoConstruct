// from server: 100% by auto
// roc 2010-06 00805b00  unit: CXTPPropExchange  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00805b00
//
// 00805b00  6aff                 push -1
// 00805b02  68147fbe00           push 0xbe7f14
// 00805b07  684007a600           push 0xa60740
// 00805b0c  51                   push ecx
// 00805b0d  e82eefffff           call 0x804a40
// 00805b12  83c410               add esp, 0x10
// 00805b15  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?ExchangeLocale@CXTPPropExchange@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
