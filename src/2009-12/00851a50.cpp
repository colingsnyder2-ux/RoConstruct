// from server: 100% by auto
// roc 2009-12 00851a50  unit: CXTPPropExchange  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00851a50
//
// 00851a50  6a20                 push 0x20
// 00851a52  8d412c               lea eax, [ecx + 0x2c]
// 00851a55  50                   push eax
// 00851a56  68ec409f00           push 0x9f40ec
// 00851a5b  51                   push ecx
// 00851a5c  e89fefffff           call 0x850a00
// 00851a61  83c410               add esp, 0x10
// 00851a64  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?ExchangeSchemaSafe@CXTPPropExchange@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
