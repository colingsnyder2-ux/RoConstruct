// from server: 100% by auto
// roc 2007-03 00667d60  unit: seg_00660000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00667d60
//
// 00667d60  6aff                 push -1
// 00667d62  6890098b00           push 0x8b0990
// 00667d67  682cac7c00           push 0x7cac2c
// 00667d6c  51                   push ecx
// 00667d6d  e8ceefffff           call 0x666d40
// 00667d72  83c410               add esp, 0x10
// 00667d75  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?ExchangeLocale@CXTPPropExchange@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
