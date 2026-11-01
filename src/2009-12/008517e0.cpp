// from server: 100% by auto
// roc 2009-12 008517e0  unit: CXTPPropExchange  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008517e0
//
// 008517e0  6a00                 push 0
// 008517e2  8d442408             lea eax, [esp + 8]
// 008517e6  50                   push eax
// 008517e7  688c7d9f00           push 0x9f7d8c
// 008517ec  51                   push ecx
// 008517ed  e80ef2ffff           call 0x850a00
// 008517f2  83c410               add esp, 0x10
// 008517f5  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?WriteCount@CXTPPropExchange@@UAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
