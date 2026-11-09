// from server: 100% by auto
// roc 2010-06 00805ad0  unit: CXTPPropExchange  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00805ad0
//
// 00805ad0  6a20                 push 0x20
// 00805ad2  8d412c               lea eax, [ecx + 0x2c]
// 00805ad5  50                   push eax
// 00805ad6  68dc83a500           push 0xa583dc
// 00805adb  51                   push ecx
// 00805adc  e85fefffff           call 0x804a40
// 00805ae1  83c410               add esp, 0x10
// 00805ae4  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?ExchangeSchemaSafe@CXTPPropExchange@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
