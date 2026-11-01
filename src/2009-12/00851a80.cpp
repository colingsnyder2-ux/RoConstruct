// from server: 100% by auto
// roc 2009-12 00851a80  unit: CXTPPropExchange  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00851a80
//
// 00851a80  6aff                 push -1
// 00851a82  686471b600           push 0xb67164
// 00851a87  6880c49f00           push 0x9fc480
// 00851a8c  51                   push ecx
// 00851a8d  e86eefffff           call 0x850a00
// 00851a92  83c410               add esp, 0x10
// 00851a95  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?ExchangeLocale@CXTPPropExchange@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
