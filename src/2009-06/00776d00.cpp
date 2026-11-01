// from server: 100% by auto
// roc 2009-06 00776d00  unit: CXTPPropExchange  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00776d00
//
// 00776d00  6a20                 push 0x20
// 00776d02  8d412c               lea eax, [ecx + 0x2c]
// 00776d05  50                   push eax
// 00776d06  68442b8f00           push 0x8f2b44
// 00776d0b  51                   push ecx
// 00776d0c  e88fefffff           call 0x775ca0
// 00776d11  83c410               add esp, 0x10
// 00776d14  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?ExchangeSchemaSafe@CXTPPropExchange@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
